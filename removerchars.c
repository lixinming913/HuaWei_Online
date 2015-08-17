/* 输入字符串s和字符c，要求去掉s中所有的c字符， 并输出结果*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int removechars(char *in, char c, char *out)
{
    int length = strlen(in);
    int j = 0;

    for(int i = 0; i < length; i++) {
        if(in[i] != c)
            out[j++] = in[i];
    }
    
    out[j] = '\0';
    
    return 0;
}

int main()
{
    char *in = "abcddefgsd";
    char *out = (char *)malloc(sizeof(char) * strlen(in));
	char c = 'd';
	int i = 0;

    removechars(in, c, out);
    while(out[i] != '\0')
        printf("%c",out[i++]);
        
    return 0;    
}