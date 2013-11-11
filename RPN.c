//#include <stdio.h>
//#include <stdlib.h>
//#include "DynStr.c"
#include "RPN.h"

int main()
{
    printf("Hello world!\n");

    DynStr *DS = DynStrCreate();
    DynStr *DS1 = DynStrCreate();
    DS = DynStrAssign(DS, "Hello");
    printf("DS = ");
    DynStrPrint(DS);
    RPNStack *RPNS = RPNSCreate();
    RPNStack *RPNSExit = RPNSCreate();
    RPNS = RPNSPushBack(DS, RPNS);
    DS1 = RPNSPop(RPNS);
    printf("DS1 = ");
    DynStrPrint(DS1);
    DS1 = DynStrAssign(DS1, "Ass hole");
    printf("DS1 = ");
    DynStrPrint(DS1);
    DynStrFree(DS);
    return 0;
}
