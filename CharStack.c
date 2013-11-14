#include <stdio.h>
#include <stdlib.h>
#include "CharStack.h"

CharStack* CharStackCreate()
{
    CharStack* ChSt = (CharStack*)malloc(sizeof(CharStack));
    if(!ChSt)
    {
        printf("memory allocation error in CharStackCreate\n");
        exit(1);
    }
    ChSt->next = NULL;
    return ChSt;
}

CharStack* CharStackPushBack(CharStack* ChSt, char c)
{
    CharStack* NewChSt = CharStackCreate();
    NewChSt->c = c;
    NewChSt->next = ChSt;
    return NewChSt;
}

char CharStackPop(CharStack *ChSt)
{
    char ret;
    if(ChSt->next)
    {
        ret = ChSt->c;
        ChSt->c = ChSt->next->c;
        ChSt->next = CharStackFreeEl(ChSt->next);
    }
    else
    {
        CharStackFree(ChSt);
        ret = NULL;
    }


    return ret;
}

void CharStackPrint(CharStack *ChSt)
{
// TODO (Александр#1#): Fix 1 free element in stack
    if(!ChSt->next)
        printf("\n");
    else
    {
        printf("%c", ChSt->c);
        CharStackPrint(ChSt->next);
    }
}

CharStack* CharStackFreeEl(CharStack *ChSt)
{
    CharStack* Next = ChSt->next;
    free(ChSt);
    return Next;
}

void CharStackFree(CharStack *ChSt)
{
    while(ChSt->next)
        CharStackFreeEl(ChSt->next);
}
