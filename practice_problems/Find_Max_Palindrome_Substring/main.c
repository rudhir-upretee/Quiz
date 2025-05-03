/******************************************************************************

Find longest palindrome substring
*******************************************************************************/
#include <stdio.h>

void findLongestPalindrome(char str[], int size)
{
    int mid, left, right;
    int maxLen, maxL, maxR, currLen;
    maxLen = 0;
    
    for(mid = 0; mid < size; mid++)
    {
        //Odd length palindrome
        left = mid-1;
        right = mid+1;
        while((left >= 0) && (right < size) && (str[left] == str[right]))
        {
            currLen = (right - left + 1);
            if(currLen > maxLen)
            {
                maxLen = currLen;
                maxL = left;
                maxR = right;
            }
            left--;
            right++;
        }
        
        //Even length palindrome
        left = mid;
        right = mid+1;
        while((left >= 0) && (right < size) && (str[left] == str[right]))
        {
            currLen = (right - left + 1);
            if(currLen > maxLen)
            {
                maxLen = currLen;
                maxL = left;
                maxR = right;
            }
            left--;
            right++;
        }
        
    }
    
    //Print
    printf("String: %s Max Palin Len = %d, left = %d, right = %d: ", str, maxLen, maxL, maxR);
    for(int j = maxL; j <= maxR; j++)
    {
        printf("%c", str[j]);
    }
    printf("\n");
    
}

int main()
{
    findLongestPalindrome("babad", 5);
    findLongestPalindrome("babadda", 7);
    findLongestPalindrome("bababda", 7);
    return 0;
}