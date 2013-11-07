#include "dynstr.c"

typedef struct st rpn_stack;

struct st
{
    DynStr *dyns;
    rpn_stack *next;
};

rpn_stack* CreateStack(void)
{
    rpn_stack *rpn = (rpn_stack*)malloc(sizeof(rpn_stack));
    if(!rpn)
    {
        printf("Îøèáêà ïğè ğàñïğåäåëåíèè ïàìÿòè\n");
        exit(1);
    }
    rpn->next = NULL;
    rpn->dyns = DynStrCreate();
    printf("sdf\n");
    return rpn;
}

rpn_stack* StackPushBack(const char *str, rpn_stack *rpn)
{
    rpn_stack *new_rpn = CreateStack();
    if(new_rpn)
    {
        new_rpn->next = rpn;
        DynStrAssign(new_rpn->dyns, str);
        return new_rpn;
    }
    return NULL;
}

int PrintRPNStack(rpn_stack *rpn)
{
    printf("%s\n", rpn->dyns->str);
    if(rpn->next)
    {
        PrintRPNStack(rpn);
        return 0;
    }
    return 1;
}

DynStr* ReadLine()
{
    DynStr *dyns = DynStrCreate();
    char *c;
    while((c = getchar()) != '\n')
    {
        printf("in cycle\n");
        DynStrAssign(dyns, strcat(dyns->str, c));
    }
    return dyns;
}

int main (void)
{
    DynStr* DStr = DynStrCreate();
    DynStrAssign(DStr, "New");
    //DStr = ReadLine();
    /*char *c;
    while((c = getchar()) != '\n')
    {
        printf("%c\n", c);
    }*/
    //DynStrPrint(DStr);
    //printf("%s\n", DStr->str);
    return 0;
}
