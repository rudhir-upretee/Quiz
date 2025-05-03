/******************************************************************************

Function to 
1. Convert HexString to integer ("12345678" = 0x12345678)
2. Convert DecimalString to integer ("123456" = 123456)

*******************************************************************************/
#include <stdio.h>
typedef unsigned int uint32;

uint32 convertHexStrToInt(char hexStr[], int size)
{
    uint32 ret = 0, n = 0;
    
    for(int i = 0; i < size; i++)
    {
        ret <<= 4;
        
        if((hexStr[i] >= '0') && (hexStr[i] <= '9'))
        {
            n = (hexStr[i] - '0');
        }
        else if((hexStr[i] >= 'A') && (hexStr[i] <= 'F'))
        {
            n = (10 + (hexStr[i] - 'A'));
        }
        else
        {
            return 0xFFFFFFFF;
        }
        
        ret |= n;
    }
    
    return ret;
    
}


uint32 convertDecStrToInt(char decStr[])
{
    uint32 ret = 0;
    
    for(int i = 0; (decStr[i] != 0) && (i <= 7); i++)
    {
        ret = ((ret*10) + (decStr[i] - '0'));
    }
    
    return ret;
}

int main()
{
    printf("Hex \"12345678\" = 0x%x\n", convertHexStrToInt("12345678", 8));
    printf("Hex \"12345678\" = 0x%x\n", convertHexStrToInt("A3", 2));
    printf("Dec \"12345678\" = %u\n", convertDecStrToInt("12345678"));

    return 0;
}