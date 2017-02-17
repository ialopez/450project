#ifndef FIRST_FIT_H
#define FIRST_FIT_H

//todo implement a queue
struct queue{
    int variable_index;
    struct queue *next;
};


void first_fit_coloring();
void push(int variable_index);
int pop();


#endif
