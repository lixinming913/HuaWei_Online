/*字符串加减法运算*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

void arithmetric(const char *pInputStr, char *pOutputStr)
{
    int i = 0, cnt = 0;
    int num1, num2, res;
    char op1[MAX], op[MAX], op2[MAX], buffer[4];
    
    while(pInputStr[i] != '\0') {
        if(pInputStr[i] == ' ')
            cnt++;
		i++;
    }
    
    if(cnt != 2) {
        strcat(pOutputStr, 0);
        return ;
    }
    
    sscanf(pInputStr, "%s %s %s", op1, op, op2);
    
    if(strlen(op) > 1 || op[0] != '+' && op[0] != '-') {
        strcat(pOutputStr, 0);
        return ;
    }
    
    for(i = 0; i < strlen(op1); i++) {
        if(!isdigit(op1[i])) {
            strcat(pOutputStr, 0);
            return ;        
        }
    }
    
    for(i = 0; i < strlen(op2); i++) {
        if(!isdigit(op2[i])) {
            strcat(pOutputStr, 0);
            return ;        
        }
    }
    
    num1 = atoi(op1);
    num2 = atoi(op2);
    
    switch(op[0]) {
        case  '+': {
            res = num1 + num2;
            itoa(res, buffer, 10);
            strcat(pOutputStr, buffer);
            break;
        }
        case '-': {
            res = num1 + num2;
            itoa(res, buffer, 10);
            strcat(pOutputStr, buffer);
            break;
        }
        default:
            break;
    }   
    
}

int main()
{
    char *pInputStr = "3 + 4";
	char pOutputStr[MAX] = {0};
    
    arithmetric(pInputStr, pOutputStr);
    printf("%s", pOutputStr);
    
    return 0;
}