#include "DynStr.h"

typedef struct rpn_s DRPNStack;

struct rpn_s
{
    DRPNStack *next;
    DynStr *DS;
};

DRPNStack* DRPNSCreate();
DRPNStack* DRPNSPushBack(DRPNStack *DRPNS, DynStr *DS);
DynStr* DRPNSPop(DRPNStack* DRPNS);
void DRPNSPrint(DRPNStack* DRPNS);
DRPNStack* DRPNSFreeEl(DRPNStack* DRPNS);
int DRPNSFreeAll(DRPNStack* DRPNS);

