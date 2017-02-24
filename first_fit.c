/*
 * use first fit a greedy approach to graph coloring
 * the algorithm always colors a neighboring node by choosing the lowest
 * value "color" that the neighboring node can assume
 */
#include <stdlib.h>
#include "RIG.h"
#include "first_fit.h"

//debug
#include <stdio.h>

struct queue *head;
int *non_available_colors;

void init_non_available_colors()
{
    int temp = k / 32;
    temp += (k % 32) != 0;
    non_available_colors = (int *)malloc(temp * sizeof(int));
}

void reset_non_available_colors()
{
    int i;
    int temp = k / 32;
    temp += (k % 32) != 0;
    for(i = 0; i < temp; i++)
    {
        non_available_colors[i] = 0;
    }
}

//run a bfs, when each new node is visited, assign it the lowest value color
//that is not being used by any of its neighbors
int first_fit_coloring()
{
    head = NULL;

    //push first variable in variable list that has No color
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {
        if(list_of_variables[i].color == NO_COLOR)
        {
            push(i);
            break;
        }
    }

    //visit nodes in queue until queue is empty
    while(head != NULL)
    {
        int index = pop();
        //run visit, if 1 is return the current graph is not k colorable
        if(visit(index))
            return 1;
    }

}

//this visits node at a given index and gives it a color and pushes its neighbors onto queue
//only neighbors that need to be colored will be pushed onto queue, this avoids nodes that have
//been colored already and avoids removed and spilled variables
//return 1 if a node cannot be colored
int visit(int index)
{
    
    //if node is removed do not push its neighbors because at this point the rest of graph is colored and 
    //removed nodes need to be colored
    int is_removed = 0;
    if(list_of_variables[index].color == REMOVED)
    {
        is_removed = 1;
    }

    //push neighbors onto queue while also finding an available color
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {
        //check if edge exist
        if(CHECKBIT(index,i))
        {
            //the list of non availabe colors is set here 
            if(list_of_variables[i].color > -1)
            {
                SET(list_of_variables[i].color);
            }
            //if it has no color push it onto queue
            if(list_of_variables[i].color == NO_COLOR && !is_removed)
            {
                push(i);
            }
        }
    }

    //find a suitable color
    int color = -1; 
    for(i = 0; i < k; i++)
    {
        //find the first color that is unused
        if(!CHECK(i))
        {
            color = i;
            break;
        }
    }

    reset_non_available_colors();

    if(color == -1)
    {
        //return 1 there is no available color
        return 1;
    }
    else
    {
        list_of_variables[index].color = color;
    }


    //if no error
    return 0;
} 

//push and integer to back of queue
void push(int variable_index)
{
    struct queue *element = (struct queue *)malloc(sizeof(struct queue));
    element->variable_index = variable_index;
    element->next = NULL;

    if(head == NULL)
    {
        head = element;
    }
    else
    {
        struct queue *temp = head;
        while(temp->next != NULL)
        {
            temp  = temp->next;
        }
        temp->next = element;
    }
}

//pop thes front of queue and returns integer saved front
int pop()
{
    struct queue *temp = head;
    head = head->next;

    int variable_index = temp->variable_index;
    free(temp);
    return variable_index;
}

//looks for colors that were set in first fit alogrithm
//sets colored nodes back to no color
void reset_colors()
{
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {
        if(list_of_variables[i].color >= 0)
        {
            list_of_variables[i].color == NO_COLOR;
        }
    }
}

void reset_queue()
{
    struct queue *temp = head;
    while(head != NULL)
    {
        head = temp->next;
        free(temp);
        temp = head;
    }
}

void color_removed()
{
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {

        if(list_of_variables[i].color == REMOVED)
        {
            visit(i);
        }
    }
}

void print_non_available_colors()
{
   int i;
   for(i = 0; i < k; i++)
   {
       printf("%d ", CHECK(i));
   }
}
