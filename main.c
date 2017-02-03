#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RIG.h"

int main()
{
    init_RIG();

    //read in number of nodes
    char *str;
    str = (char *)malloc(MAXSTRINGSIZE * sizeof(char));
    fgets(str, MAXSTRINGSIZE, stdin);
    num_of_nodes = atoi(str);
 
    create_RIG();    
    print_RIG();
    return 0;
}
