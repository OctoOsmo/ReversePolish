#include "DynStr.h"

typedef struct rpn_s RPNStack;

struct rpn_s
{
    RPNStack *next;
    DynStr *DS;
};

RPNStack* RPNSCreate();
RPNStack* RPNSPushBack(DynStr *DS, RPNStack *RPNS);
DynStr* RPNSPop(RPNStack* RPNS);
void RPNSPrint(RPNStack* RPNS);
RPNStack* RPNSFreeEl(RPNStack* RPNS);
int RPNSFreeAll(RPNStack* RPNS);

