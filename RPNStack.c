//#pragma once
#include "RPNStack.h"

RPNStack* RPNSCreate()
{
    RPNStack *RPNS = (RPNStack*)malloc(sizeof(RPNStack));
    if(!RPNS)
    {
        printf("memory allocation error in DynStrAssign\n");
        exit(1);
    }
    //RPNS->
    RPNS->DS = DynStrCreate();
    RPNS->next = NULL;
    return RPNS;
}

RPNStack* RPNSPushBack(DynStr *DS, RPNStack *RPNS)
{
    RPNStack *NewRPNStack = RPNSCreate();
    NewRPNStack->DS = DS;
    NewRPNStack->next = RPNS;
    return NewRPNStack;
}
DynStr* RPNSPop(RPNStack* RPNS)
{
    DynStr* NewDynStr = DynStrCreate();
    NewDynStr = RPNS->DS;
    RPNStack *RPNSOld = RPNSCreate();
    RPNSOld = RPNS;
    RPNS = RPNS->next;
    RPNSFreeEl(RPNSOld);
    return NewDynStr;
}

void RPNSPrint(RPNStack* RPNS)
{
    printf("%s", RPNS->DS->str);
    if(RPNS->next)
        printf("\n");
    else
        RPNSPrint(RPNS->next);
}

RPNStack* RPNSFreeEl(RPNStack* RPNS)
{
    if(!RPNS)
    {
        RPNStack *RPNStmp = RPNSCreate();
        RPNStmp = RPNS->next;
        DynStrFree(RPNS->DS);
        return RPNStmp;
    }
    return NULL;
}

int RPNSFreeAll(RPNStack* RPNS)
{
    while(RPNS)
        RPNS = RPNSFreeEl(RPNS);
    return 0;
}
