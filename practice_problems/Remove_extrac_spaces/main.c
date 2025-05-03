/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void removeSpaces(char str[])
{
    int curr = 0, next = 0;
    int firstSpace = 0;
    
    //Skip over extra spaces in beginning
    while(str[next] == ' ')
    {
        next++;
    }
    
    #if 0
    //Remove extra spaces till end. 
    while(str[next] != '\0')
    {
        if(str[next] == ' ')
        {
            if(firstSpace == 0)
            {
                str[curr] = str[next];
                curr++;
                next++;
                firstSpace = 1;
            }
            else
            {
                next++;
            }
            
        }
        else
        {
            str[curr] = str[next];
            curr++;
            next++;
            firstSpace = 0;
        }
    }
    #endif
    
    
    while(str[next] != 0)
    {
        //copy words
        while((str[next] != 0) && (str[next] != ' '))
        {
            str[curr] = str[next];
            curr++;
            next++;
        }
        
        //copy one space
        if(str[next] != 0)
        {
            str[curr] = str[next];
            curr++;
            next++;
        }
            
        //skip extra spaces
        while((str[next] != 0) && (str[next] == ' '))
        {
            next++;
        }
    } 
    
    //Check if there is extra space at the end
    if((curr == 0) || str[curr-1] != ' ')
    {
        str[curr] = '\0';
    }
    else
    {
        str[curr-1] = '\0';
    }
    
}

char str1[] ="    Hello    world    here!!  ";
char str2[] ="";
char str3[] =" ";
char str4[] ="  ";
char str5[] ="Hello ";

int main()
{
    
    printf("%s\n", str1);
    removeSpaces(str1);
    printf("%s %lu\n", str1, strlen(str1));
    
    printf("%s\n", str2);
    removeSpaces(str2);
    printf("%s %lu\n", str2, strlen(str2));
    
    printf("%s\n", str3);
    removeSpaces(str3);
    printf("%s %lu\n", str3, strlen(str3));
    
    printf("%s\n", str4);
    removeSpaces(str4);
    printf("%s %lu\n", str4, strlen(str4));
    
    printf("%s\n", str5);
    removeSpaces(str5);
    printf("%s %lu\n", str5, strlen(str5));

    return 0;
}