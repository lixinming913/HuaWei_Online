#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void handle_line(char *s)
{
    int len =  strlen(s);

    int n = 1;
    char c = s[0];
    for(int i = 1; i < len; i++) {
        if(c == s[i])
            n++;
        else {
            if(n != 1)
                putchar(c);
            
            c = s[i];
            n = 1;
        }
    }
    
    if(n != 1)
        putchar(c);
        
    printf("\n");
}

int main() {
    char s[1024];

    while(gets(s)) {
        handle_line(s);
    }
}