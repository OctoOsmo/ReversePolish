//#include <stdio.h>
//#include <stdlib.h>
//#include "DynStr.c"
#include "RPN.h"

double ReadNumber(char *str)
{
    return 0;
}

int ReverseExpression(char *str, CharStack* ChSt, DRPNStack *DRPNS)
{
    size_t i;
    char c;
    DynStr *DS = NULL;
    printf("%s\n", str);
    if(!(ChSt||DRPNS||str))
    {
        printf("ReverseExpression input data error\n");
        exit(1);
    }
    for(i=0; i<=strlen(str); ++i)
    {
        switch(str[i])
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
        case '.'://Reading current number
            if(!DS)
                DS = DynStrCreate();
            DS = DynStrPushBack(DS, str[i]);
            break;
        case '(':
        case '*':
        case '/':
        case '+':
        case '-'://Add function symbol to stack
            ChSt = CharStackPushBack(ChSt, str[i]);
            break;
        case ')':
            while(c!='(')
            {
                c = CharStackPop(ChSt);
                DS = DynStrPushBack(DS, c);
                DRPNS = DRPNSPushBack(DRPNS, DS);
                DS = DynStrAssign(DS, '\0');
            }
            CharStackPop(ChSt);//pop '('

            break;
        case '\0'://Add number to exit string
            DS = DynStrPushBack(DS, '\0');
            DRPNS = DRPNSPushBack(DRPNS, DS);
            DS = NULL;
            //DS = DynStrAssign(DS, "\0");
            break;
        default:
            printf("error in expression\n");
            i = strlen(str)+1;
        }
    }
    do
    {
        c = CharStackPop(ChSt);
        DS = DynStrCreate();
        DS = DynStrPushBack(DS, c);
        DS = DynStrPushBack(DS, '\0');
        DRPNS = DRPNSPushBack(DRPNS, DS);
    }
    while(c);
    //DynStrPrint(DS);
    DRPNSPrint(DRPNS);
    //DynStrPrint(DSf);
    //CharStackPrint(ChSt);
    return 0;
}

int main(int argc, char *argv[])
{
    //printf("Hello world!\n");
    //DynStr *DS = DynStrCreate();
    //DynStr *DS1 = DynStrCreate();
    //DS = DynStrAssign(DS, "Hello");
    //printf("DS = ");
    //DynStrPrint(DS);
    DRPNStack *DRPNS = DRPNSCreate();
    //RPNStack *RPNSExit = RPNSCreate();
    //RPNS = RPNSPushBack(DS, RPNS);
    //DS1 = RPNSPop(RPNS);
    //printf("DS1 = ");
    //DynStrPrint(DS1);
    //DS1 = DynStrAssign(DS1, "Ass hole");
    //printf("DS1 = ");
    //DynStrPrint(DS1);
    //DynStrFree(DS);
    CharStack *ChSt = CharStackCreate();
    if(argc > 1)
        ReverseExpression(argv[1], ChSt, DRPNS);
    else
        ReverseExpression("1+2*3", ChSt, DRPNS);
    return 0;
}
