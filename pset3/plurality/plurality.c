#include <stdio.h>
#include <string.h>

/*
 * plurality.c
 * CS50 pset 3.2
 * Note 1: pset 3.1 is in my repo because it was made entirely by the CS50 team
 * Note 2: I only coded the vote and print_winner functions. The rest was created by the CS50 team
 * Note 3: I did remove the cs50 library altogether, switching from Strings to Chars[] accordingly 
 * ---------------------------
 * Simulates a plurality election, where each voter casts a vote for one candidate.
 * The candidate(s) with the highest number of votes win(s) the election.
 * The program accepts candidate names as command-line argument,
 * prompting the user to enter the number of voters and each vote by name.
 *
 * Example:
 * $ ./plurality Alice Bob
 * Number of voters: 3
 * Vote: Alice
 * Vote: Bob
 * Vote: Alice
 * Alice
 */


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char *name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;
char name[50];

// Function prototypes
int vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        printf("Vote: ");
        scanf("%49s", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(char voted_name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the voted name against all known candidates
        if (strcmp(voted_name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    // The candidate name provided in this void does not exist
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Until proven otherwise, the first candidate is considered the winner
    int winner_index = 0;
    int winner_votes = candidates[winner_index].votes;

    // The votes of two candidates are compared on each iteration
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // The index of the winner is only updated if the current winner's votes are surpassed
        if (candidates[i].votes < candidates[i + 1].votes && winner_votes < candidates[i + 1].votes)
        {
            winner_index = i + 1;
            winner_votes = candidates[winner_index].votes;
        }
    }

    // Make sure to print all co-winners is case of a tie
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
