#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RIG.h"
#include "heuristic.h"
#include "testAns.h"

int main()
{
    init_RIG();

    //read in number of nodes
    char *str;
    str = (char *)malloc(MAXSTRINGSIZE * sizeof(char));
    fgets(str, MAXSTRINGSIZE, stdin);
    num_of_nodes = atoi(str);
 
    create_RIG();

    
    //here we should read in k 
    //for now we just hardcode to let k be 16(the number of temporary
    //register in mips assembly)
    k = 8;

    print_RIG();

    minimize_RIG(k);
    test_minimize_RIG();
    //test_ans();

    return 0;
}
