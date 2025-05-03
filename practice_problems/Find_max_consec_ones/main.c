#include <stdio.h>

#define MAX(a,b) ((a>b)?a:b)

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0, curr = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1)
        {
            curr++;
            max = MAX(curr, max);
        }
        else
        {
            curr = 0;
        }
    }
    
    return max;
    
}

int main()
{
    int a[6] = {0,1,1,0,0,1};
    printf("Max consec ones = %d\n", findMaxConsecutiveOnes(a, 6));
    int b[6] = {0,1,1,1,1,1};
    printf("Max consec ones = %d\n", findMaxConsecutiveOnes(b, 6));
    int c[6] = {1,1,1,0,0,1};
    printf("Max consec ones = %d\n", findMaxConsecutiveOnes(c, 6));

    return 0;
}