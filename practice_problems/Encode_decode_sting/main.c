
/*
Given list of words. Encode and store these into one string.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str_vec[4][20] = {"Very Happy", "Thanks", "Giving", "everyone!!"};
#define N_ROWS  4
#define N_COLS  20

char out_vec[4][20];

char* encodeStr(int rows, int cols, char svec[rows][cols])
{
    //max_len = (Max chars) + (1 byte word len for each word) + (NULL char)
    int max_len = (rows*cols) + rows + 1;
    char* enc_str = malloc(max_len);
    memset(enc_str, 0, max_len);
    
    //Go over string vector
    int enc_idx, i; 
    unsigned char word_len;
    for(enc_idx = 0, i = 0; i < rows; i++)
    {
        word_len = strlen(svec[i]);
        enc_str[enc_idx] = word_len;
        enc_idx++;
        strncpy(&enc_str[enc_idx], svec[i], word_len);
        enc_idx += word_len;
        //printf("word_len=%d enc_idx=%d\n", word_len, enc_idx);
    }
    enc_str[enc_idx] = 0;
    
    return enc_str;
}

char* decodeStr(int rows, int cols, char* str, char ovec[rows][cols])
{
    //int max_len = strlen(str);
    unsigned char word_len;
    for(int i = 0, r = 0; str[i] != '\0';)
    {
        word_len = str[i];
        i++;
        strncpy(ovec[r], &str[i], word_len);
        ovec[r][word_len] = 0;
        r++;
        i += word_len;
    }
}

int main()
{
    printf("\nInput str:\n");
    for(int i = 0; i < N_ROWS; i++)
    {
        printf("%s\n", str_vec[i]);
    }
    
    char* out_str = encodeStr(N_ROWS, N_COLS, str_vec);
    printf("\nEnc str=%s\n", out_str);
    
    decodeStr(N_ROWS, N_COLS, out_str, out_vec);
    printf("\nDecoded result:\n");
    for(int i = 0; i < N_ROWS; i++)
    {
        printf("%s\n", out_vec[i]);
    }
    
    return 0;
}