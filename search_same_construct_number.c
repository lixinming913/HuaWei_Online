/*  查找同构数的数量
 *  同构数：这个数字出现在其平方数的右边，5是25的同构，25是625的同构
 */
 
 #include<stdio.h>
 
 int SearchSameConstructNum(int n)
 {
    int cnt = 0;
    int i, temp, squre;
    
    for(i = 1; i <= n; i++) {
        temp = i;
        squre = i * i;
        
        while(temp > 0) {
            if(temp % 10  == squre % 10) {
                temp /= 10;
                squre /= 10;
            } else
                break;
        }
        
        if(temp == 0)
            cnt++;
    }
    
    return cnt;
 }
 
 int main()
 {
    int n;
    
    scanf("%d", &n);
    
    printf("%d内有同构数%d个\n", n, SearchSameConstructNum(n));
    
    return 0;
 }