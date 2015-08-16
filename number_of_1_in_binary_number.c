/*二进制中1的个数*/

#include<stdio.h>

int GetCount(unsigned int num)
{
    int count = 0;
    
    while(num >= 1) {
        if(num % 2 == 1)
            count++;
        
        num >>=  1;
    }
    
    return count;
}

int main()
{
    unsigned int number;
    int cnt;
    
    while(scanf("%d ", &number)) {
		cnt = GetCount(number);
		printf("%d", cnt);
	}
        
    return 0;
}