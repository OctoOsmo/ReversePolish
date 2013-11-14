//#pragma once
#include "DRPNS.h"

DRPNStack* DRPNSCreate()
{
    DRPNStack *DRPNS = (DRPNStack*)malloc(sizeof(DRPNStack));
    if(!DRPNS)
    {
        printf("memory allocation error in DRPNSCreate\n");
        exit(1);
    }
    //DRPNS->
    DRPNS->DS = DynStrCreate();
    DRPNS->next = NULL;
    return DRPNS;
}

DRPNStack* DRPNSPushBack(DRPNStack *DRPNS, DynStr *DS)
{
    DRPNStack *NewDRPNStack = DRPNSCreate();
    NewDRPNStack->DS = DS;
    NewDRPNStack->next = DRPNS;
    return NewDRPNStack;
}

DynStr* DRPNSPop(DRPNStack* DRPNS)
{
    /*DynStr* NewDynStr = DynStrCreate();
    NewDynStr = DRPNS->DS;
    DRPNStack *DRPNSOld = DRPNSCreate();
    DRPNSOld = DRPNS;
    DRPNS = DRPNS->next;
    DRPNSFreeEl(DRPNSOld);
    return NewDynStr;*/
    DynStr* ret = DRPNS->DS;
    DRPNS->DS = DRPNS->next->DS;
    DRPNS->next = DRPNSFreeEl(DRPNS->next);
    return ret;
}

void DRPNSPrint(DRPNStack* DRPNS)
{
    printf("%s", DRPNS->DS->str);
    if(!DRPNS->next)
        printf("\n");
    else
        DRPNSPrint(DRPNS->next);
}

DRPNStack* DRPNSFreeEl(DRPNStack* DRPNS)
{
    if(!DRPNS)
    {
        DRPNStack *DRPNStmp = DRPNSCreate();
        DRPNStmp = DRPNS->next;
        DynStrFree(DRPNS->DS);
        return DRPNStmp;
    }
    return NULL;
}

int DRPNSFreeAll(DRPNStack* DRPNS)
{
    while(DRPNS)
        DRPNS = DRPNSFreeEl(DRPNS);
    return 0;
}
