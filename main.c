#include <stdlib.h>
#include <stdio.h>
#include "RIG.h"

int main()
{
    initRIG();
    numOfNodes = 10;
    createRIG();
    setBit(0, 9);
    setBit(2, 9);
    setBit(7, 2);
    printRIG();
    return 0;
}
