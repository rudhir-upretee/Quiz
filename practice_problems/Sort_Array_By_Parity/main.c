
#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    
    int temp;
    int* retArr = malloc(numsSize*sizeof(int));
    //memset(retArr, 0, numsSize*sizeof(int));
    
    temp = 0;
    for(int left = 0, right = (numsSize-1); temp < numsSize; temp++)
    {
        if((nums[temp] & 1) == 0)
        {
            retArr[left] = nums[temp];
            left++;
        }
        else if((nums[temp] & 1) == 1)
        {
            retArr[right] = nums[temp];
            right--;
        }
    }
    
    *returnSize = numsSize;
    return retArr;
}

void sortArrayByParityInplace(int* nums, int numsSize) {
    
    int temp;
    //Put evens on Left and odds on right
    for(int left = 0, right = (numsSize-1); left <= right;)
    {
        if((nums[left] & 1) == 0)
        {
            left++;
        }
        else if((nums[right] & 1) == 1)
        {
            right--;
        }
        else if((nums[left] & 1) == 1)
        {
            //swap
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            //we know odd was sent to right side. Increment right.
            //Dont increment left because the value from right could also be 
            // another odd number.
            right--;
        }
        else if((nums[right] & 1) == 0)
        {
            //swap
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            //we know even was sent to left side. Increment left.
            //Dont increment right because the value from left could also be 
            // another even number.
            left++;
        }
    }
    
    return;
}

int main()
{
    /*
    int a[] = {7,3,2,1,4,6};
    int outlen;
    int* out = sortArrayByParity(a, 6, &outlen);
    for(int i = 0; i < outlen; i++)
    {
        printf("%d ", out[i]);
    }
    printf("\n");*/
    
    int b[] = {7,3,2,1,4,6};
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    sortArrayByParityInplace(b, 6);
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    
    
    
    
    int c[] = {1,2,3,4,5,6,7,8};
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    sortArrayByParityInplace(c, 8);
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");


    return 0;
}
