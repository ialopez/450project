/*
 * hearestic to reduce graph size
 * this heurestic will remove variables from graph with less than k neighbors
 */
#include "stdio.h"
#include "heuristic.h"

//this function iterates through each node in the RIG and removes nodes with less
//than k neighbors by setting their color value to REMOVED
void minimize_RIG(int k)
{
    int i,j;
    int num_of_neighbors;
    for(i = 0; i < num_of_nodes; i++)
    {
        num_of_neighbors = 0;
        for(j = 0; j < num_of_nodes; j++)
        {
            if(CHECKBIT(i,j))
            {
                num_of_neighbors++;
            }
        }
        if(num_of_neighbors < k)
        {
            list_of_variables[i].color = REMOVED;
        }
    }
}

//prints nodes that have been removed
void test_minimize_RIG()
{
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {
        if(list_of_variables[i].color == REMOVED)
        {
            printf("variable: %s has been removed\n", list_of_variables[i].name);
        }
    }        
}
