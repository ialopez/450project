#ifndef FIRST_FIT_
#define FIRST_FIT_H

#define SET(i) ( non_available_colors[i/32] |= (1 << (i % 32) ) )
#define CLEAR(i)   ( non_available_colors[i/32] &= ~(1 << (i % 32) ) )
#define CHECK(i)  ( non_available_colors[i/32] & (1 << (i % 32) ) )

//todo implement a queue
struct queue{
    int variable_index;
    struct queue *next;
};

extern int *non_available_colors; 

void init_non_available_colors();
void reset_non_available_colors();
int first_fit_coloring();
int visit(int index);
void push(int variable_index);
int pop();
void reset_colors();
void reset_queue();
void color_removed();

//debug
void print_non_available_colors();

#endif
