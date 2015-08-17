/*周期串问题*/

#include<stdio.h>

int GetMinPeriod(char *inputstring)
{        
    int length = 0;
    int i, flag, gap;
    
    
    if(!inputstring || *inputstring == '\0')
        return 0;
        
    while(inputstring[length] != '\0')
        ++length;
        
    for(gap = 1; gap <= length; gap++) {
        flag = 1;
        
        if(length % gap != 0) /*如果gap不是length的整除数，是不可能为周期数的*/
            continue;
            
        else {
            
            for(i = 0; i < length-gap; i++) {
                if(inputstring[i] != inputstring[i+gap]) {
                    flag = 0;
                    break;
                }
            }
        
        if(flag == 1)
            return gap;
        } 
    }    
    
    return length;
}

int main()
{
    char *str = "abcabcabc";
    int  cycle = GetMinPeriod(str);
    
    printf("%s周期为%d", str, cycle);
    
    return 0;
}