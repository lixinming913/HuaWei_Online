/*删除重复字符*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

int GetResult(const char *input, char *output)
{
    if(!input || input[0] == '\0' || !output)
        return -1;
        
    int a[256] = {0 };
    int i = 0, j = 0;
    
    while(input[j] != '\0') {
    
        if(a[input[j]] < 1) {
            a[input[j]] = 1;
            output[i++] = input[j++];
        } else
            j++;
    }
    
    output[i] = '\0';
    
    return 1;
}

int main()
{
    const char *in = "abadcbad";
    char *out = (char *)malloc(sizeof(char)*strlen(in));
    int i = 0;
    
    int res = GetResult(in, out);
    if(res == -1)
        printf("Error\n");
    else {
        while(out[i] != '\0') {
            printf("%c", out[i++]);
        }
    }
    
    return 0;
}