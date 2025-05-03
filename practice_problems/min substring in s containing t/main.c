/******************************************************************************

Minimum substring in s which contains all chars in t. Substring can contain
the characters in any order.

Eg: s = "ADCEBAC"
    t = "ABC"
    
    Ans="BAC" (Order is not important)
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a<b)?a:b)

int freqT[26];
int freqS[26];

void initFreqTable(unsigned int table[])
{
    memset(&table[0], 0, (sizeof(int) * 26));
}

void calcFreqTable(unsigned int table[], char str[])
{
    for(int i = 0; str[i] != 0; i++)
    {
        table[str[i] - 'A']++;
    }
}

void minSubstring(char s[], char t[])
{
    int minStart, minLen;
    int start, end, matchLen, tLen;
    
    //Calculate freq of t
    initFreqTable(freqT);
    initFreqTable(freqS);
    calcFreqTable(freqT, t);
    
    tLen = strlen(t);
    minLen = strlen(s);
    matchLen = 0;
    minStart = 0;
    for(start = 0, end = 0; s[end] != 0; )
    {
        //Find if all chars in t are seen
        while(s[end] != 0)
        {
            if(freqT[s[end] - 'A'] > 0)
            {
                freqS[s[end] - 'A']++;
                matchLen++;
                
                if((freqS[s[end] - 'A'] > freqT[s[end] - 'A']) ||
                    matchLen >= tLen)
                    {
                        printf("Break find: start=%d end=%d matchLen=%d\n", start, end, matchLen);
                        break;
                    }
            }
            end++;
        }
        
        //Adjust start for min length
        while(s[start] != 0)
        {
            if(freqT[s[start] - 'A'] > 0)
            {
                freqS[s[start] - 'A']--;
                matchLen--;
                
                if(freqS[s[start] - 'A'] < freqT[s[start] - 'A'])
                    {
                        freqS[s[start] - 'A']++;
                        matchLen++;
                        printf("Break Adj: start=%d end=%d matchLen=%d\n", start, end, matchLen);
                        break;
                        ;
                    }
            }
            start++;
        }
        
        if((end-start+1) < minLen)
        {
            minStart = start;
            minLen = end-start+1;
        }
        
        //Move for next round
        end++;
        
    }
    
    printf("minStart=%d minLen=%d\n", minStart, minLen);
}

int main()
{
    char s[] = "ADCEBAC";
    char t[] = "ABC";
    minSubstring(s, t);

    return 0;
}