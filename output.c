/*
 * prints each variable and its color
 */
#include "output.h"
#include "RIG.h"

void print_colors()
{
    int i;
    char *name;
    int color;
    for(i = 0; i < num_of_nodes; i++)
    {
        name = (&list_of_variables[i])->name;
        color = (&list_of_variables[i])->color;
        if(color == SPILLED)
        {
            printf("var: %s\t is spilled onto stack");
        }
        else
        {
            printf("var: %s\tcolor: %d", name, color);
        }
    }
}

