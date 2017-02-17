/*
 * use first fit a greedy approach to graph coloring
 * the algorithm always colors a neighboring node by choosing the lowest
 * value "color" that the neighboring node can assume
 */
#include "RIG.h"
#include "first_fit.h"

struct queue *head;

//run a bfs, when each new node is visited, assign it the lowest value color
//that is not being used by any of its neighbors
void first_fit_coloring()
{
    head = NULL;
    
    //push first variable in variable list that hasn't been removed or spilled
    int i;
    for(i = 0; i < num_of_nodes; i++)
    {
        if(list_of_variables[i].color != REMOVED && list_of_variables[i].color != SPILLED)
        {
            push(i);
            break;
        }
    }
    
}

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

int pop()
{
   struct queue *temp = head;
   head = head->next;

   int variable_index = temp->variable_index;
   free(temp);
   return variable_index;
}

