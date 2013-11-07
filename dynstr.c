#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *str;
    size_t buf_size;
    size_t reserve;
}DynStr;

DynStr* DynStrCreate(void)
{
    DynStr *DStr = (DynStr*)malloc(sizeof(DynStr));
    DStr->buf_size = 0;
    DStr->reserve = 0;
    DStr->str = NULL;
    return DStr;
}

DynStr* DynStrAssign(DynStr *DStr, const char *str)
{
    size_t new_size = strlen(str)+1;
    if(DStr->reserve <= new_size)
    {
        DStr->reserve = new_size*2;
        printf("new_size = %d, reserve = %d\n", new_size, DStr->reserve);
        DStr = (DynStr*)realloc(DStr, DStr->reserve);
        if(!DStr)
        {
            printf("Ошибка при распределении памяти\n");
            exit(1);
        }
    }
    //void *to = DStr->str;
    printf("DynStrAssign\n");
    //memcpy(DStr->str, str, new_size);
    strcpy(DStr->str, str);
    printf("AfterDynStrAssign\n");
    DStr->buf_size = new_size;
    return DStr;
}

void DynStrPrint(DynStr *str)
{
    printf("%c\n",str->str);
}

void DeleteDynStr(DynStr* DStr)
{
    free(DStr->str);
    free(DStr);
}
