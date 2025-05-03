/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a>b)?a:b)

int getLongestPalindromSubstr(char str[])
{
    int len = strlen(str);
    int maxPalLen = 0;
    int currLen = 0;
    
    printf("Str = %s\n", str);
    
    //special handling for 0, 1 and 2
    if(len < 2)
    {
        return len;
    }
    
    int left, right;
    //Count odd len palindroms
    for(int i = 1; i <len; i++)
    {
        left = i-1;
        right = i+1;
        
        currLen = 1;
        while(((left >= 0) && (right < len)) &&
             (str[left] == str[right])
             )
        {
            left--;
            right++;
            currLen += 2;
        }
        
        maxPalLen = MAX(currLen, maxPalLen);
        printf("Max odd at pos=%d is %d\n", i, maxPalLen);
    }
    
    //Count even len palindroms
    for(int i = 0; i <len; i++)
    {
        left = i;
        right = i+1;
        
        currLen = 0;
        while(((left >= 0) && (right < len)) &&
             (str[left] == str[right])
             )
        {
            left--;
            right++;
            currLen += 2;
        }
        
        maxPalLen = MAX(currLen, maxPalLen);
        printf("Max even at pos=%d is %d\n", i, maxPalLen);
    }
    
    
    //printf("maxPalLen = %d\n", maxPalLen);
    return maxPalLen;
}

int main()
{
    char str[100];
    
    printf("Max palin len = %d\n", getLongestPalindromSubstr("a"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("ab"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("aa"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("aba"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("aabaa"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("xyzaa"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("xyzaabaa"));
    printf("Max palin len = %d\n", getLongestPalindromSubstr("ddccddaabaa"));
    return 0;
}