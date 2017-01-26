/*
 *
 */
#include <stdlib.h>
#include <string.h>
#include "RIG.h"


void initListOfAllVariables()
{
	listOfAllVariables = NULL;
}

//mallocs a struct variable and returns pointer
struct variable *newVariable()
{
	struct variable *var = (struct variable *)malloc(sizeof(struct variable));
	var->name = NULL;
	var->color = -1;
	var->neighbors = NULL;
	return var;
}

//mallocs a struct variableList and returns pointer
struct variableList *newVariableList()
{
	struct variableList *varList = (struct variableList *)malloc(sizeof(struct variableList));
	varList->var = NULL;
	varList->next = NULL;
	return varList;
}

//adds a var to the end of a variable list
void addToVarList(struct variableList **varList, struct variable *var)
{	
	//case when varlist is empty
	if(*varList == NULL)
	{
		*varList = newVariableList();
		(*varList)->var = var;
	}
	else
	{
		struct variableList *temp;
		temp = *varList;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newVariableList();
		temp->next->var = var;
	}
}

struct variable *findVariable(char *var)
{
	struct variable *matchingVar = NULL;
	struct variableList *temp;
	temp = listOfAllVariables;
	while(temp != NULL)
	{
		if(strcmp(temp->var->name, var) == 0)
		{
			matchingVar = temp->var;
			return matchingVar;
		}
		temp = temp->next;
	}
	return matchingVar;
}

