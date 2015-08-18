/*删除重复多余的字符*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void stringFilter(const char *pInputStr, char *pOutputStr)
{
    int a[256] = {0};
    
    int i = 0, j = 0;
    while(pInputStr[i] != '\0') {
        if(a[pInputStr[i]] == 0) {
            a[pInputStr[i]]++;
            pOutputStr[j++] = pInputStr[i++];
        } else 
            i++;
    }
    
    pOutputStr[j] = '\0';
}

int main()
{
    char *pInputStr = "deefd";
    char *pOutputStr = (char *)malloc(sizeof(char) * strlen(pInputStr));
    
    stringFilter(pInputStr, pOutputStr);
    printf("%s", pOutputStr);
    
    return 0;
}