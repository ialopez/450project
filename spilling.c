/*
 * here spilling of variables that cannot be fit onto a k colorable graph is handled
 * the heuristic used here is to spill the variables with the most conflicts hence most neighbors in RIG
 */
#include "RIG.h"
#include "spilling.h"


//spill variable that has the greates amount of conflicts(i.e. most amount of
//neighbors)
void spill_variable()
{
    //find variable with greatest neighbor count
    int i;
    int index_of_max = 0;
    int max = 0;
    for(i = 0; i < num_of_nodes; i++)
    {
        //only spill variables if it needs to be colored(ie. not spilled already or removed)
        if(list_of_variables[i].neighbor_count > max && list_of_variables[i].color == NO_COLOR)
        {
            max = list_of_variables[i].neighbor_count;
            index_of_max = i;
        }
    }
    //spill that variable
    list_of_variables[index_of_max].color = SPILLED;

    //update the neighbor count for variables adjacent to spilled variable
    for(i = 0; i < num_of_nodes; i++)
    {
        if(CHECKBIT(index_of_max,i))
        {
            list_of_variables[i].neighbor_count--;
        }
    }
}    
