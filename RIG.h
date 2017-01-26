#ifndef RIG_H
#define RIG_H

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

struct variableList *listOfAllVariables;

void initListOfAllVariables();
struct variable *newVariable();
struct variableList *newVariableList();
void addToVarList(struct variableList **varList, struct variable *var);
struct variable *findVariable(char *var);

#endif
