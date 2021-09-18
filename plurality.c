/* description
plurality.c-- voting method 1--*/

/* instructions
this has a different header file(cs50.h)   [since it was part of the workshop]
if we use this , then following changes cn be made:
1-- remove #include <cs50.h> line.
2-- add #include <bool.h>
2-- format specifier for integer here is %i ---> change it to %d 
    ---[lines where this change is to be made is commented as: //minor change ]
3-- here, function like get_string, get_int is used to get input ---> change it to printf & scanf statements.
    ---[lines where this change is to be made is commented as: //change ]
*/

/*execution instructions:
u hv to give 2 or more [upto 9] candidate names as command line argument*/





#include <cs50.h>
#include <stdio.h>
#include <string.h>



// new datatype--Candidate
typedef struct c
{
    string name;
    int votes;
}
candidate;

// Max no. of candidates
#define MAX 9

//no. of candidates
int candidate_count;

// Array: candidates
candidate candidates[MAX];

// to do-- function prototypes
bool vote(string name);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for valid no. of candidates
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // No. of candidates entered by user
    candidate_count = argc - 1;

    //if max exceeds
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX); // minor change
        return 2;
    }

    //intializing
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        //printf ("intial- %s- %i \n",candidates[i].name ,candidates[i].votes);
    }

    //getting no. of voters
    int voter_count = get_int("Number of voters: ");	//change



    // for all voters-- LOOP
    for (int j = 0; j < voter_count; j++)
    {
        string name = get_string("Vote: ");	//change
        
        // Check  if given vote is valid
        (vote(name));
        
    
    
    }
    
    // prints table
    for (int i = 0; i < voter_count; i++)
    {
        //printf ("final- %s- %i \n",candidates[i].name ,candidates[i].votes);	
    }
    

    // prints the winner of the election
    print_winner();
}



// updates vote totals;
bool vote(string name)
{
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            //printf("%i\n", candidates[i].votes);
            //printf("%s\n", candidates[i].name);
            //printf("Found \n");
            return true;
        }
        
    }
    //printf("Not found\n");
    printf("Invalid vote.\n");
    return false;
    
}

// prints winner (or winners) 
void print_winner(void)
{
    int w = candidates[0].votes ;
    string winner = candidates[0].name ;

    for (int i = 0; i < candidate_count - 1 ; i++)
    {
        
        int j = i + 1 ;
       
        if (candidates[j].votes > w) 
        {
            w = candidates[j].votes ;
            winner = candidates[j].name;
            //printf("%i\n", candidates[j].votes);
            //printf("%i\n", candidates[i].votes);
            //printf("diff-%i\n", w);
            //printf("diff-%s\n", winner);

        }
        //else
        { 
            //printf("%i\n", candidates[j].votes);
            //printf("%i\n", candidates[i].votes);
            //printf("same-%i\n", w);
            //printf("same-%s\n", winner);
            
            //X --if (strcmp(candidates[j].name, winner) ==0)
            {
                //ERROR- winner = candidates[j].name , winner;
                //printf("both-%s\n", winner);
                
            }
            
        }
    
    }
   
    //printf("final- %i \n", w);
    printf("%s\n", winner);
   
    //printf("Alice");
    return;
    
}
