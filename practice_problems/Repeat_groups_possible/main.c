/******************************************************************************

Find out if a string has minimum letter groups that can be used in repeatation 
to form the string.

Eg: abcabcabc -> TRUE because it has repeated group 'abc'
    aaaaaa    -> TRUE because at least it has repeat of 'a' 
    abcab     -> FALSE because no repeat group possible
    abcda     -> FALSE(Special case)
    abcdef    -> FALSE because no repeat groups possible
*******************************************************************************/
#include <stdio.h>
#include <string.h>

typedef enum
{
    FALSE = 0,
    TRUE
}BOOL;

BOOL isRepeatGroupFound(char str[], int len)
{
    if(len < 2)
    {
        return FALSE;
    }
    
    int base, comp, firstMatchPos;
    
    //Basic idea is, first group of repeat chars should be repeated.
    //Skip unequal chars
    for(base = 0, comp = 1; (str[comp] != '\0') && (str[base] != str[comp]); comp++);
    
    //Found the end with unequal chars. Ret false
    if(str[comp] == '\0')
    {
        printf("No repeat chars\n");
        return FALSE;
    }
    
    firstMatchPos = comp;
    
    //Search till end. All chars should match
    while(str[comp] != '\0')
    {
        if(str[base] != str[comp])
        {
            printf("Non matching char found %c %c\n", str[base], str[comp]);
            return FALSE;
        }
        
        base++;
        comp++;
    }
    
    //If we reach end, make sure all the chars were matched after first match
    //before deciding
    return ((base >= firstMatchPos)? TRUE: FALSE);
    
}

int main()
{
    char a[] = "abcabcabc";
    char b[] = "aaaaaa";
    char c[] = "abcab";
    char d[] = "abcda";
    char e[] = "abcdef";
    printf("%s: , result=%d\n",a, isRepeatGroupFound(a, strlen(a)));
    printf("%s: , result=%d\n",b, isRepeatGroupFound(b, strlen(b)));
    printf("%s: , result=%d\n",c, isRepeatGroupFound(c, strlen(c)));
    printf("%s: , result=%d\n",d, isRepeatGroupFound(d, strlen(d)));
    printf("%s: , result=%d\n",e, isRepeatGroupFound(e, strlen(e)));

    return 0;
}