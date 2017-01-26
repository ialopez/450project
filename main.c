#include <stdlib.h>
#include <stdio.h>
#include "RIG.h"

int main()
{
	struct variable *firstVar = newVariable();
	struct variable *secondVar = newVariable();
	struct variableList *newVarList = NULL;
	addToVarList(&newVarList, firstVar);
	addToVarList(&newVarList, secondVar);
	return 0;
}
