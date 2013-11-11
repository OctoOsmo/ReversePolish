//#include <stdio.h>
//#include <stdlib.h>
//#include "DynStr.c"
#include "RPN.h"

int main()
{
    printf("Hello world!\n");

    DynStr *DS = DynStrCreate();
    DS = DynStrAssign(DS, "Hello");
    DynStrPrint(DS);
    RPNStack *RPNS = RPNSCreate();
    DynStrFree(DS);
    return 0;
}
