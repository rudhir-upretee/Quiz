/* 
 * Efficient memset implementation
 */
 
#include <stdio.h>

int memset_fast(void* pBuf, unsigned char val, unsigned int size)
{
    if(pBuf == NULL)
    {
        return -1;
    }
    
    unsigned char* pCharBuff = (unsigned char*)pBuf;
    unsigned int* pIntBuff = (unsigned int*)pBuf;
    
    unsigned int intVal =(((unsigned int)val << 24) | ((unsigned int)val << 16) 
                        | ((unsigned int)val << 8) | ((unsigned int)val));
    // Or do this
    // unsigned int intVal;
    //unsigned char* pTemp = (unsigned char*)&intVal;
    //pTemp[0] = val; pTemp[1] = val; pTemp[2] = val; pTemp[3] = val;
    
    printf("size=%d, val=%x, intVal=%x\n", size, val, intVal);
    while(size != 0)
    {
        //Write 4 bytes at a time to speedup only if memory 4 bytes aligned and
        //has enough size
        if((((unsigned long)pIntBuff & 0x3) == 0) && (size >= 4))
        {
            *pIntBuff = intVal;
            size -= 4;
            pIntBuff++;
            pCharBuff = (unsigned char*)pIntBuff;
        }
        else 
        {
            *pCharBuff = val;
            size--;
            pCharBuff++;
            pIntBuff = (unsigned int*)pCharBuff;
        }
    }
    
    
    return 0;
}

int main(){
    unsigned char buf[50];
    
    memset_fast(&buf[0], 0xaa, 50);
    for(int i = 0; i < 50; i++)
    {
        if((i % 8) == 0)
        {
            printf("\n");
        }
        printf("%x ", buf[i]);
    }
    
    return 0;
}