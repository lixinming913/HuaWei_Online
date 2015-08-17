/* 字符串加解密
 * 加密：
 * 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,
 * 如字母a时则替换为B；字母Z时则替换为a；
 * 当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；其他字符不做变化。
 * 解密方法为加密的逆过程
 */
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


void Encrypt(char aucPassword[], char aucResult[])
{
    if(!aucPassword || !aucResult || aucPassword[0] == '\0')
        return ;
        
    int i = 0; 
    
    for(i = 0; aucPassword[i] != '\0'; i++) {
        char c = aucPassword[i];
        
        if(isdigit(c)) {
            if(c == '9')
                aucResult[i] = '0';
            else
                aucResult[i] = c + 1;
            
            continue;
        }     
            
        if(c >= 'a' && c <= 'z') {
            if(c == 'z')
                aucResult[i] = 'A';
            else 
                aucResult[i] = toupper(aucPassword[i] + 1) ;
            
            continue;
        }    
            
        if(c >= 'A' && c <= 'Z') {
            if(c == 'Z')
                aucResult[i] = 'a';
            else
                aucResult[i] = tolower(aucPassword[i] + 1) ; 
            
            continue;
        }   
            
        aucResult[i] = c;

    }
    
    aucResult[i] = '\0';
}

int unEncrypt(char result[], char password[])
{
    if(password[0] ='\0')
        return -1;
        
    int i = 0;
    
    for(i = 0; result[i] != '\0'; i++) {
        char c = result[i];
        
        if(isdigit(c)) {
            if(c == '0')
                password[i] = '9';
            else
                password[i] = c - 1;
            
            continue;
        }     
            
        if(c >= 'a' && c <= 'z') {
            if(c == 'a')
                password[i]= 'Z';
            else 
                password[i] = toupper(result[i] - 1) ;
            
            continue;
        }    
            
        if(c >= 'A' && c <= 'Z') {
            if(c == 'A')
                password[i] = 'z';
            else
                password[i] = tolower(result[i] - 1) ; 
            
            continue;
        } 
            
        password[i] = c;

    }
    
    password[i] = '\0';
    
    return 0;
}
 
 int main()
 {
    char aucPassword[] = "abz129!";
    char *aucResult = (char *)malloc(sizeof(char) * strlen(aucPassword));
    char *password= (char *)malloc(sizeof(char) * strlen(aucPassword));
    int i =0;
    
    Encrypt(aucPassword, aucResult);
    while(aucResult[i] != '\0')
        printf("%c", aucResult[i++]);
    printf("\n");
    
    if(unEncrypt(aucResult, password) == 0) {
        i = 0;
        while(password[i] != '\0')
            printf("%c", password[i++]);
    }
     
    return 0;
 }