#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RIG.h"

int main()
{
    initRIG();

    //read in number of nodes
    char *str;
    str = (char *)malloc(MAXSTRINGSIZE * sizeof(char));
    fgets(str, MAXSTRINGSIZE, stdin);
    numOfNodes = atoi(str);
 
    createRIG();    
    printRIG();
    return 0;
}
