/******************************************************************************

Perform Decimal String multiplication and return result in string.

Eg:
a = "2345"
b = "68"
ans = "159460"

You can also give negative numbers to make program bit difficult.

*******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static inline uint8_t decStrToInt(uint8_t c)
{
    return (c - '0');
}

static inline uint8_t intToStr(uint8_t val)
{
    return (val + '0');
}

void strReverse(char* c)
{
    int len = strlen(c);
    char temp;
    
    for(int i = 0, j = len-1; i < j; i++, j--)
    {
        temp = c[i];
        c[i] = c[j];
        c[j] = temp;
    }
}

void decStrMult(char* a, char* b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    char *output = malloc(lenA+lenB+1);
    memset(output, '0', (lenA+lenB+1));
    
    int innerA, outerB, outCnt, inCnt;
    int prod = 0, rem = 0;
    for(outCnt = 0, outerB = lenB-1; outerB >= 0; outCnt++, outerB--)
    {
        for(inCnt = 0, innerA = lenA-1; innerA >= 0; inCnt++, innerA--)
        {
            //printf("outerN=%d innerN=%d outputN=%d\n", decStrToInt(a[innerA]), decStrToInt(b[outerB]), decStrToInt(output[outCnt+inCnt]));
            prod = ((decStrToInt(a[innerA])) * decStrToInt(b[outerB]) + rem) + decStrToInt(output[outCnt+inCnt]);
            rem = (prod/10);
            prod = (prod%10);
            
            output[outCnt+inCnt] = intToStr(prod);
            //printf("outer=%c inner=%c prod=%d rem=%d\n", b[outerB], a[innerA], prod, rem);
        }
        
        if(rem)
        {
            output[outCnt+inCnt] = intToStr(rem);
            inCnt++;
        }
        
        rem = 0;
    }

    //Close the str
    output[outCnt+inCnt-1] = 0;
    
    //Reverse answer string
    strReverse(output);
    
    printf("%s\n", output);
}

int main()
{
    char a[100];
    char b[100];
    
    strcpy(a, "2345");
    strcpy(b, "1");
    printf("a=%s b=%s\n", a, b);
    decStrMult(a, b);
    
    strcpy(a, "2345");
    strcpy(b, "68");
    printf("a=%s b=%s\n", a, b);
    decStrMult(a, b);
    
    strcpy(a, "2345");
    strcpy(b, "0");
    printf("a=%s b=%s\n", a, b);
    decStrMult(a, b);
    
    strcpy(a, "9999");
    strcpy(b, "999999");
    printf("a=%s b=%s\n", a, b);
    decStrMult(a, b);
    
    
    return 0;
}
