/*
 * hearestic to reduce graph size
 * this heurestic will remove variables from graph with less than k neighbors
 */
#include "stdio.h"
#include "RIG.h"
#include "heuristic.h"

//this function iterates through each node in the RIG and removes nodes with less
//than k neighbors by setting their color value to REMOVED
void minimize_RIG(int k)
{
   int i;
   for(i = 0; i < num_of_nodes; i++)
   {
       if(list_of_variables[i].neighbor_count < k)
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
