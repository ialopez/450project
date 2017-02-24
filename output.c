/*
 * prints each variable and its color
 */
#include <stdio.h>
#include "output.h"
#include "RIG.h"

void print_colors()
{
    //print a list of variables and their respective color
    int i, j;
    char *name;
    int color;
    for(i = 0; i < num_of_nodes; i++)
    {
        name = list_of_variables[i].name;
        color = list_of_variables[i].color;
        if(color == SPILLED)
        {
            printf("var: %s\t is spilled onto stack\n", name);
        }
        else
        {
            printf("var: %s\tcolor: %d\n", name, color);
        }
    }


    //print adjacency matrix with rows and coloumns labels by their coloring
    printf("\t");
    for(i = 0; i < num_of_nodes; i++)
    {
        printf("%d ", list_of_variables[i].color);
    }
    printf("\n\n");
    for(i = 0; i < num_of_nodes; i++)
    {
        printf("%d\t", list_of_variables[i].color);
		for(j = 0; j < num_of_nodes; j++)
		{
			int bit = CHECKBIT(i,j);
            if(bit)
                printf("1 ");
            else
                printf("0 ");
		}
		printf("\n");
    }
}
