#include "DynStr.h"

DynStr* DynStrCreate()
{
    DynStr *DS = (DynStr*)malloc(sizeof(DynStr));
    if(!DS)
    {
        printf("memory allocation error in DynStrCreate\n");
        exit(1);
    }
    DS->str = (char*)calloc(1,sizeof(char));
    DS->len = 0;
    DS->reserve = 0;
    return DS;
}

DynStr* DynStrAssign(DynStr *DS, char *str)
{
    //c = strcat(c, "\0");
    size_t len = strlen(str);
    if(len+1>=DS->len)
    {
        DS = (DynStr*)realloc(DS, sizeof(DynStr)*len*3);
        if(!DS)
        {
            printf("memory allocation error in DynStrAssign\n");
            exit(1);
        }
        DS->reserve = len*3;
    }
    DS->str = strcpy(DS->str, str);
    DS->str = strcat(DS->str, "\0");
    DS->len = len;
    return DS;
}

void DynStrPrint(DynStr *DS)
{
    printf("%s\n", DS->str);
}

int DynStrFree(DynStr *DS)
{
    free(DS->str);
    free(DS);
    return 0;
}
