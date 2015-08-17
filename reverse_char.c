/*字符串反转*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reversechar(char *in, char *out) 
{
    if(!in || !out)
        return ;
    
    int len = strlen(in);
    
    for(int i = 0, j = len-1; j >= 0 && i < len; j--, i++)
        out[j] = in[i];
    out[len] = '\0';
    
}

int main()
{
    char *in = "abcd";
    char *out = (char *)malloc(sizeof(char) * strlen(in));
    int i = 0;

	reversechar(in, out); 
    
    while(out[i] != '\0')
        printf("%c", out[i++]);
        
    return 0;
}