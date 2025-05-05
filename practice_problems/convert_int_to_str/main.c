/******************************************************************************

Convert
1. Hex number to string (0x1A2B3C4D = "1A2B3C4D")
2. Decimal number to string (12345678 = "12345678") 
*******************************************************************************/
#include <stdio.h>
#include <string.h>

typedef unsigned int uint32;

void reverseString(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void convertHexToString(uint32 hex, char str[])
{
   int i = 0;
   uint32 n;
   int cnt = 0;
   
   while(cnt < (sizeof(uint32)*2))
   {
       n = (hex & 0xF0000000) >> 28;
       
       if(n < 10)
       {
           str[i] = '0' + n;
       }
       else
       {
           str[i] = 'A' + (n-10);
       }
       
       hex <<= 4;
       i++;
       cnt++;
   }
   str[i] = 0;
   
   return;
}

void convertDecToString(uint32 dec, char str[])
{
    int i;
    for(i = 0; dec != 0; i++)
    {
        str[i] = ('0' + (dec % 10));
        dec = (dec / 10);
    }
    str[i] = 0;
    
    reverseString(str);
}

int main()
{
    char str[50];
    int size;
    
    convertHexToString(0x1A2B3C4D, str);
    printf("Hex 0x1A2B3C4D = \"%s\"\n", str);
    convertHexToString(0x1A000000, str);
    printf("Hex 0x1A000000 = \"%s\"\n", str);

    convertDecToString(12345678, str);
    printf("Dec 12345678 = \"%s\"\n", str);

    return 0;
}
