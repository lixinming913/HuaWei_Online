/*字符串压缩*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringZip(const char *pInputStr, char *pOutputStr) 
{
    int k = 0;
    int i, j, cnt;
    
    for(i = 0; pInputStr[i] != '\0'; i++) {
        int cnt = 1;
        
        for(j = i+1; pInputStr[j] != '\0'; j++) {
            if(pInputStr[j] != pInputStr[i])
                break;
            else
                ++cnt;
        }
        
        if(cnt == 1)
            pOutputStr[k++] = pInputStr[i];
        else {
            pOutputStr[k++] = cnt + '0';
            pOutputStr[k++] = pInputStr[i];
        }
        
        i = j - 1;
    }
    pOutputStr[k] = '\0';
}

int main()
{
    char *pInputStr = "cccddeffe";
    char *pOutputStr = (char *)malloc(sizeof(char) * strlen(pInputStr));
    
    stringZip(pInputStr, pOutputStr);
    printf("%s", pOutputStr);
    
    return 0;
}