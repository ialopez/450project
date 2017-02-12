/*
 * a simple function to tranverse the RIG and see if no two colors are touching
 * each other
 */
#include "testAns.h"
#include "RIG.h"
#include <stdio.h>

void test_ans()
{
    int i, j;
    int i_color, j_color;
    for(i = 0; i < num_of_nodes; i++)
    {
        i_color = list_of_variables[i].color;
        for(j = 0; j < num_of_nodes; j++)
        {
            if(CHECKBIT(i,j))
            {
                j_color = list_of_variables[j].color;
                //note every variable should have a color at this point except for
                //spilled variables
                if(i_color == NO_COLOR || i_color == REMOVED)
                {
                    printf("error there are uncolored or removed variables");
                    return;
                }
                else if(i_color != SPILLED && i_color == j_color)
                {
                    printf("coloring is invalid solution");
                    return;
                }
            }
        }
    }
}
