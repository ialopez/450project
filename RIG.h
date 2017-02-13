#ifndef RIG_H
#define RIG_H

//note these implement a flattened 2d array
#define SETBIT(i,j) (RIG[(((i*num_of_nodes)+j)/32)] |= (1 << ((i*num_of_nodes+j)%32)) ) 
#define CLEARBIT(i,j)   ( RIG[(((i*num_of_nodes)+j)/32)] &= ~(1 << ((i*num_of_nodes+j)%32)) )  
#define CHECKBIT(i,j)  ( RIG[(((i*num_of_nodes)+j)/32)] & (1 << ((i*num_of_nodes+j)%32)) )

#define MAXSTRINGSIZE 40
#define NO_COLOR -1
#define REMOVED -2
#define SPILLED -3

/*
 *Here we declared the datastructures used to build the register interference graph
 *Also functions that build RIG are declared here and defined in RIG.c
 */
struct variable {
	char * name;
	int color;
    int neighbor_count;
};

//global variables

extern int *RIG;
extern struct variable *list_of_variables;
extern int num_of_nodes;
extern int k; //the amount of colors you can use to color the RIG

//forward declarations
void init_RIG();
void create_RIG();
void create_edge(char *firstNode, char *secondNode);
//struct variable *new_variable();
void create_variable_list();
//int find_variable_index(char *var);

void print_RIG();

#endif
