/*字符串中找出连续最长的数字串*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

unsigned int 
Continumax(char **pOutputstr, char *inputstr)
{
   unsigned int max = 0;
   int pos1= 0, pos2 = 0, k = 0;
   int i , j, cnt;

   for(i = 0; inputstr[i] != '\0'; i++) {
        if(isdigit(inputstr[i])) {

            cnt = 1;
            for( j = i+1; inputstr[j] != '\0'  && isdigit(inputstr[j]); j++)
                ++cnt; 

            if(cnt >= max) {
                max = cnt;
				pos1 = i;
				pos2 = j;
			}
            i = j;
        }
   }
   
   *pOutputstr =(char *)malloc(sizeof(char) * (max+1));
	
	while(pos1 < pos2) {
		(*pOutputstr)[k++] = inputstr[pos1++];
	}
	(*pOutputstr)[k] = '\0';

   return max; 
}

int 
main()
{
    
    int i = 0;
    char *inputstr = "abcd123456eh123456";
	char *pOutputstr;
    unsigned int max = Continumax(&pOutputstr, inputstr);
    
    printf("%d\n", max);
    
    while(pOutputstr[i] != '\0')
        printf("%c" , pOutputstr[i++]);
        
    return 0;
}