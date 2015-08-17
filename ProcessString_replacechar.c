/* 字符串替换 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ProcessString( char * strInput,char chSrc,char chDes ,char * strOutput)
{
    int flag = 0;
    int i = 0;
    
    while(strInput[i] != '\0') {
    
        if(strInput[i] == chSrc) {
            flag++;
            strOutput[i] = chDes;
        } else      
            strOutput[i] = strInput[i];
            
        i++;
    }
    
    strOutput[i] = '\0';
    
    if(!flag)
        return -1;
        
    return 0;
}

int main()
{
    char *in = "ABCDEF";
    char chSrc = 'A';
    char chDes = 'B';
    char *out = (char *)malloc(sizeof(char) * strlen(in));
    
    if(!ProcessString(in, chSrc, chDes, out)) {
        int i = 0;
        while(out[i] != '\0')
            printf("%c",out[i++]);
    } else
        printf("异常");
        
    return 0;
}