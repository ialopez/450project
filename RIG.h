#ifndef RIG_H
#define RIG_H
//note these implement a flattened 2d array
#define setBit(i,j) (RIG[(((i*numOfNodes)+j)/32)] |= (1 << ((i*numOfNodes+j)%32)) ) 
#define clearBit(i,j)   ( RIG[(((i*numOfNodes)+j)/32)] &= ~(1 << ((i*numOfNodes+j)%32)) )  
#define checkBit(i,j)  ( RIG[(((i*numOfNodes)+j)/32)] & (1 << ((i*numOfNodes+j)%32)) )

/*
 *Here we declared the datastructures used to build the register interference graph
 *Also functions that build RIG are declared here and defined in RIG.c
 */
struct variable {
	char * name;
	int color;
	struct variableList * neighbors;
};

struct variableList {
	struct variable * var;
	struct variableList * next;
};

//global variables

int *RIG;
struct variableList *listOfAllVariables;
int numOfNodes;

void initRIG();
void createRIG();
struct variable *newVariable();
struct variableList *newVariableList();
void addToVarList(struct variableList **varList, struct variable *var);
struct variable *findVariable(char *var);

void printRIG();

#endif
