#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int len;
}Len_t;

typedef struct
{
    unsigned int a;
    unsigned char b;
    Len_t c[];
}Test_t;

#define MAX_ELEM 10

int main()
{
    printf("%lu\n", sizeof(Test_t));
    
    Test_t* t = malloc(sizeof(Test_t) + (sizeof(Len_t) * MAX_ELEM));
    
    t->a = 0xAABBCCDD;
    t->b = 0xEE;
    for(int i = 0; i < 10; i++)
    {
        t->c[i].len = i;
    }
    
    
    printf("%x %x\n", t->a, t->b);
    for(int i = 0; i < 10; i++)
        printf("%x ", t->c[i].len);
    printf("\n");
}