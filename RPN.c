//#include <stdio.h>
//#include <stdlib.h>
//#include "DynStr.c"
#include "RPN.h"

double ReadNumber(char *str)
{
    return 0;
}

int ReverseExpression(char *str, RPNStack *RPNS, RPNStack *RPNSExit)
{
    size_t i;
    DynStr *DS = DynStrCreate();
    printf("%s\n", str);
    if(!(RPNS||RPNSExit||str))
    {
        printf("Reverse stack error\n");
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
        case '.':
            DS = DynStrPushBack(DS, str[i]);
            break;
        case '(':
            break;
        case '*':
            break;
        case '/':
            break;
        case '+':
            break;
        case '-':
            break;
        case '\0':
            RPNSExit = RPNSPushBack(DS, RPNSExit);
            break;
        default:
            printf("error in expression\n");
            i = strlen(str)+1;
        }
    }
    //DynStrPrint(DS);
    RPNSPrint(RPNSExit);
    return 0;
}

int main(int argc, char *argv[])
{
    //printf("Hello world!\n");
    DynStr *DS = DynStrCreate();
    DynStr *DS1 = DynStrCreate();
    //DS = DynStrAssign(DS, "Hello");
    //printf("DS = ");
    //DynStrPrint(DS);
    RPNStack *RPNS = RPNSCreate();
    RPNStack *RPNSExit = RPNSCreate();
    //RPNS = RPNSPushBack(DS, RPNS);
    //DS1 = RPNSPop(RPNS);
    //printf("DS1 = ");
    //DynStrPrint(DS1);
    //DS1 = DynStrAssign(DS1, "Ass hole");
    //printf("DS1 = ");
    //DynStrPrint(DS1);
    //DynStrFree(DS);
    if(argc > 1)
        ReverseExpression(argv[1], RPNS, RPNSExit);
    else
        ReverseExpression("1+2*3", RPNS, RPNSExit);
    return 0;
}
