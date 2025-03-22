#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char* name;
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
    printf("%d", candidates[1].votes);
    printf("%d", candidates[2].votes);
    printf("%d", candidates[3].votes);
    // print_winner();
}

// Update vote totals given a new vote
int vote(char name[])
{
    if (strcmp(name, candidates[1].name) || strcmp(name, candidates[2].name) || strcmp(name, candidates[3].name))
    {
        candidates[1].votes++;
        return 1;
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    printf("The winner is...\n");
    return;
}