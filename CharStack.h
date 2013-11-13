typedef struct ChSt CharStack;

struct ChSt
{
    char c;
    CharStack *next;
};

CharStack* CharStackCreate();
CharStack* CharStackPushBack(CharStack* ChSt, char c);
char CharStackPop(CharStack *ChSt);
void CharStackPrint(CharStack *ChSt);
CharStack* CharStackFreeEl(CharStack *ChSt);
void CharStackFree(CharStack *ChSt);
