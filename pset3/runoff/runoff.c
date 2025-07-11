#include <stdio.h>
#include <string.h>

/*
 * runoff.c
 * CS50 2025 pset 3.3
 * Note 1: The main function was coded by the CS50 team. I did code the rest of the functions 
 * Note 2: I did remove the cs50 library altogether, switching from Strings to Chars[] accordingly 
 * ------------------------
 * Simulates an instant-runoff (ranked-choice) election.
 * Voters rank candidates in order of preference. If no candidate receives
 * more than 50% of the first-choice votes, the candidate with the fewest
 * votes is eliminated. Votes are then redistributed to the next preferred,
 * non-eliminated candidate. This process repeats until a winner emerges.
 *
 * Example:
 * $ ./runoff Alice Bob Charlie
 * Number of voters: 5
 * Rank 1: Alice
 * Rank 2: Bob
 * Rank 3: Charlie
 * ...
 * Alice
 */

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char *name;
    int votes;
    int eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// A few global variables
int voter_count;
int candidate_count;
int active_candidates;
char name[50];

// Function prototypes
int vote(int voter, int rank, char name[]);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Initialaze array of candidates
    candidate_count = argc - 1;
    active_candidates = candidate_count;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = 0;
    }

    // Set (and validate) number of voters
    printf("Number of voters: ");
    scanf("%d", &voter_count);
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            printf("Rank %i: ", j + 1);
            scanf("%49s", name);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (1)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        int won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        int tie = is_tie(min);

        // If tie, everyone not-yet-eliminated wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
int vote(int voter, int rank, char voted_name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Check whether the voted candidate exists
        if (strcmp(voted_name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return 1;
        }
    }
    // The voted name is not a valid candidate 
    return 0;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int preferred;
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // A voter's preferance is 0, if eliminated then 1, and so on
            preferred = preferences[i][j];
            if (!candidates[preferred].eliminated)
            {
                candidates[preferred].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        // A candidates wins only after obtaining more than 50% of the votes
        if ((candidates[i].votes * 100 / voter_count) > 50)
        {
            printf("%s\n", candidates[i].name);
            return 1;
        }
    }
    return 0;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Until proven otherwise, the min votes are 100% of the votes
    int min_votes = voter_count;

    // The votes of two candidates are compared on each iteration
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        // No comparison is made if the candidate is already eliminated or has more votes than the min
        if ((candidates[i].eliminated == 0 && candidates[i + 1].eliminated == 0)
            && (candidates[i].votes < min_votes || candidates[i + 1].votes < min_votes))
        {
            // Either the 'left' or 'right' candidate has less votes than the current min
            if (candidates[i].votes < candidates[i + 1].votes)
            {
                min_votes = candidates[i].votes;
            }
            else
            {
                min_votes = candidates[i + 1].votes;
            }
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    int disposable_candidates = 0;

    // Compare the votes of each (active) candidate against the min number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == 0)
        {
            disposable_candidates++;
        }
    }
    // All remaining candidates have the same number of votes
    if (disposable_candidates == active_candidates)
    {
        return 1;
    }
    return 0;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Only active candidates can be eliminated
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = 1;
            active_candidates--;
        }
    }
    return;
}
