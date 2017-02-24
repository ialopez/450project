#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RIG.h"
#include "heuristic.h"
#include "testAns.h"
#include "spilling.h"
#include "first_fit.h"
#include "output.h"

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
    k = 16;

    minimize_RIG(k);

    //debug
    test_minimize_RIG();

    //initialize non available color array
    init_non_available_colors();
    //perform first fit coloring until it returns 0(is successful)
    while(first_fit_coloring())
    {
        reset_colors();
        reset_queue();
        spill_variable();
    }
       
    //color the removed variables
    color_removed(); 

    test_ans();
    print_colors();

    return 0;
}
