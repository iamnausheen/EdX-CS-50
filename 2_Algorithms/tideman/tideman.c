#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Initialise preferences to 0
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }

    // TESTING by printing
    for (int l =0; l < candidate_count; l++)
    {
        for (int m = 0; m < candidate_count; m++)
        {
            printf("%i", preferences[l][m]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (j < i || j == i)
                continue;
            if (preferences[i][j] > preferences[j][i])
                {
                    pairs[k].winner = i;
                    pairs[k].loser = j;
                }
            else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[k].winner = j;
                    pairs[k].loser = i;
                }

            k++;
            pair_count++;
        }
    }

    //TESTING by printing
    //
    //for (int l = 0; l < pair_count; l++)
    //{
      //  printf("\n%i, %i\n , %i\n", pairs[l].winner, pairs[l].loser, pair_count);
    //}
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Calculate margin of votes for each pair
    int margin[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        margin[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        //TESTING
        //printf("%i\n", margin[i]);
    }

     //Sorting margin and pairs
    pair x;
    pair max;
    for (int j = 0; j < pair_count; j++)
    {
        for (int k = j+1; k < pair_count; k++)
        {
            if (margin[k] > margin[j])
            {
                x = pairs[j];
                pairs[j] = pairs[k];
                pairs[k] = x;
            }
        }
    }

    // TESTING
    //for (int l = 0; l < pair_count; l++)
    //{
      //  printf("%i, %i\n", pairs[l].winner, pairs[l].loser);
    //}
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //int n = 0;
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }



    /*{
        if (n == pair_count - 2)
            continue;

        for (int j = 0; j < pair_count; j++)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;


            if (locked[pairs[j].loser][pairs[i].winner] == true)
                n++;

            if (locked[pairs[j].winner][pairs[i].winner] == true)
                n++;

        */
       return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = pair_count; i > 0; i--)
    {
        for (int j = pair_count; j > 0; j--)
        {
            if (locked[i][j] == true)
                printf("%s\n", candidates[pairs[i].winner]);
        }
    }
    return;
}
