#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *str;
    size_t buf_size;
    size_t reserve;
}DynStr;
