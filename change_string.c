/*  修改字符串
 *  将给定字符串中连续出现3次的小写字母替换为改小写字母在字母表中的下一个字母（z变为a），
 *  大写字母和其他字符不处理，仍然保留。要求最终输出的字符串中不再存在任何连续出现3次的小写字母。
 *  例如字符串”ATRcccert893#45ae”经过处理后应该为”ATRdert893#45ae”
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 
 int ChangeString(char *pInStr, char *pOutStr)
 {   
    int flag = 1;
	int i ,j = 0;
    int length = strlen(pInStr);
    
    if(!pInStr || !pOutStr)
        return -1;
       
    for(i = 0; i < length; i++) {
    
        if(flag && pInStr[i] >= 'a' && pInStr[i] <= 'z') {
            
            if(pInStr[i] == pInStr[i+1] && pInStr[i] == pInStr[i+2]) {
            
                flag = 0;
                
                if(pInStr[i] == 'z') {
                    pOutStr[j++] = 'a'; 

                } else  
                    pOutStr[j++] = pInStr[i] + 1;
                
                i += 2;
                    
            }
        } else {
            pOutStr[j++] = pInStr[i];
        }
        
    }
    pOutStr[i] = '\0'; 
    
    return 0;
 }
 
 int main()
 {
    char *pInStr = "ATRcccert893#45ae";
    char *pOutStr = (char *)malloc(sizeof(char)*strlen(pInStr));
    int i = 0;
    
    if(!ChangeString(pInStr, pOutStr) ) {
        printf("执行成功！\n");
        
        while(pOutStr[i] != '\0')
            printf("%c", pOutStr[i++]);
    } else
        printf("执行不成功！\n");
        
 }
 
 