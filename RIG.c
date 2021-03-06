/*
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RIG.h"

int *RIG;
struct variable *list_of_variables;
int num_of_nodes;
int k;

//initializes global variables in RIG.h
void init_RIG()
{
    list_of_variables = NULL;
    num_of_nodes = 0;
    RIG = NULL;
}

//mallocs the bit array for RIG, then reads in edges from standard input and sets edges in RIG
void create_RIG()
{
    //malloc a flattened 2d bit array
    int size = num_of_nodes;
    int temp = 0;
    size = size * size;
    temp = size % 32 != 0;
    size = size / 32;
    size += temp;
    RIG = (int *)malloc(size * sizeof(int));
    

    create_variable_list();

    //read in edges
    char c;
    while(c != EOF)
    {
        int dashSymbolRead = 0;
        //read in first node
        char first_node[MAXSTRINGSIZE];
        int index = 0;
        c = fgetc(stdin); 
        while(c != EOF && c != '-' && c != '\n' )
        { 
            first_node[index] = c;
            index++;
            c = fgetc(stdin);
        }
        first_node[index] = '\0';
        if( c == '-' )
        {
            dashSymbolRead = 1;
        }
        //read in second
        char second_node[MAXSTRINGSIZE];
        index = 0;
        c = fgetc(stdin); 
        while(c != EOF && c != '\n')
        { 
            second_node[index] = c;
            index++;
            c = fgetc(stdin);
        }
        second_node[index] = '\0';

        //add edge to RIG
        if(dashSymbolRead)
        {
            //create edges in both directions
            create_edge(first_node, second_node);
            create_edge(second_node, first_node);
        }

    }
}

//takes in two nodes and create edge between them in the RIG
void create_edge(char *first_node, char *second_node)
{
    int i, j;
    i = atoi(first_node);
    j = atoi(second_node);

    SETBIT(i,j);

    //increase neightbor count, only first_node neighbor count is increased
    //because create edge is always called twice on a single edge in create_RIG
    //function
    list_of_variables[i].neighbor_count++;
}

/*
//mallocs a struct variable and returns pointer
struct variable *new_variable()
{
	struct variable *var = (struct variable *)malloc(sizeof(struct variable));
	var->name = NULL;
	var->color = NO_COLOR;
	return var;
}
*/

//create an array of variables
//variables are assumed to have to be named after numbers so if 
//num_of_nodes = 10 then variables are 0,1,2...9
void create_variable_list()
{
    int index = 0;
    list_of_variables = (struct variable *)malloc(num_of_nodes * sizeof(struct variable));
    char *name;
    struct variable *temp;
    int i;
    for(i = 0; i < num_of_nodes; i++)
    { 
        name = (char *)malloc(MAXSTRINGSIZE * sizeof(char));
        sprintf(name, "%d", i);
        list_of_variables[i].name = name;
        list_of_variables[i].color = NO_COLOR;
        list_of_variables[i].neighbor_count = 0;
    }
}

/* redundant function
int find_variable_index(char *var)
{
    int index = 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name, var) == 0)
		{
				return index;
		}
		temp = temp->next;
        index++;
	}
	return -1;
}
*/

//prints the RIG in the form of a 2d adjacency matrix
void print_RIG()
{
    int i, j;
    for(i = 0; i < num_of_nodes; i++)
    {
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
