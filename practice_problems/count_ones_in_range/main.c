/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int countOnesInRange(int n)
{
    //Create a hasmap
    int *intArr = malloc((n+1)*sizeof(int));
    if(intArr == NULL)
    {
        return -1;
    }
    
    intArr[0] = 0;
    int onesCnt = 0;
    int base = 0;

    for(int i = 1; i <= n; i++)
    {
        if((i & (i-1)) != 0)
        {
            //update count array
            intArr[i] = (intArr[i-base] + intArr[base]);
         
            onesCnt += intArr[i];
            printf("NPow2 Num=%d base=%d onesCnt=%d\n", i, base, onesCnt);
            
        }
        else
        {
            //update count array
            intArr[i] = 1;
            
            //Base two number only have one 1
            onesCnt += intArr[i];
            
            //update base
            base = i;
            printf("Pow2 Num=%d base=%d onesCnt=%d\n", i, base, onesCnt);
        }
        
        //Update hashmap
        //intArr[i] = onesCnt;
    }
    
    return onesCnt;
}

int main()
{
    int res;
    res = countOnesInRange(0);
    printf("Counting ones [0 to 0] = %d\n\n", res);
    res = countOnesInRange(1);
    printf("Counting ones [0 to 1] = %d\n\n", res);
    res = countOnesInRange(5);
    printf("Counting ones [0 to 5] = %d\n\n", res);
    res = countOnesInRange(8);
    printf("Counting ones [0 to 8] = %d\n\n", res);
    res = countOnesInRange(20);
    printf("Counting ones [0 to 20] = %d\n\n", res);
    
    return 0;
}