/******************************************************************************

Find if given substring has anagram in the string. If yes, return index of 
substring. Else -1.

string = "abcdefghijkl"
subStr = "hgf"

Return 5 (fgh)

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void resetFreqArr(char* src, char* dest, int size)
{
    for(int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

int findSubstrIsAnagram(char* str, char* subStr)
{
    char freqArr[127];
    char tempFreqArr[127];
    
    memset(&freqArr[0], 0, 127);
    
    int len = strlen(str);
    int subStrLen = strlen(subStr);
    for(int i = 0; subStr[i] != '\0'; i++)
    {
        freqArr[(subStr[i] - 'a')]++;
    }
    resetFreqArr(&freqArr[0], &tempFreqArr[0], 127);
    
    int i, j;
    for(i = 0; i <= (len - subStrLen); i = j)
    {
        for(j = i; j < (i+subStrLen); j++)
        {
            tempFreqArr[(str[j] - 'a')]--;
            
            if(tempFreqArr[(str[j] - 'a')] < 0)
            {
                resetFreqArr(&freqArr[0], &tempFreqArr[0], 127);
                break;
            }
        }
        
        if(j == (i+subStrLen))
        {
            //Found it
            return i;
        }
        else
        {
            //Skip this char for next round
            j++;
        }
    }
    
    return -1;
}


int main()
{
    printf("Index = %d\n", findSubstrIsAnagram("abcdefghijkl", "hgf"));
    printf("Index = %d\n", findSubstrIsAnagram("abcdefgnasa", "saan"));
    printf("Index = %d\n", findSubstrIsAnagram("abcdefgnasa", "c"));
    printf("Index = %d\n", findSubstrIsAnagram("abcdefgnasa", "zef"));
    return 0;
}