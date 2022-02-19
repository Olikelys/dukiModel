#include "ByteToVariant.h"


void* Byte2(char *p,const char *c1,const char *c2)
{
     *(p+0) = *c1;
     *(p+1) = *c2;
    return 0;
}

void* Byte4(char *p, char *c1, char *c2, char *c3, char *c4)
{
    return 0;
}
