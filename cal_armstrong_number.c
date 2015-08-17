/*  阿姆斯特朗数
 *  如果一个正整数等于其各个数字的立方和，则该数称为阿姆斯特数
 */
 #include<stdio.h>
 
 int CalArmstrongNumber(int n)
 {
    int cnt = 0;
    int m = 0;
    int i, k, tmp;
    if(n > 65535 || n <= 0)
        return 0;
    
    for(i = 1; i <= n; i++) {
        /* 计算i 的各位数的立方和m */
        tmp = i;
        while(tmp > 0) {
            k = tmp % 10;
            m += tmp * tmp *tmp;
            tmp /= 10;
        }
        
        if(m == i)
            cnt++;
    }
    
    return cnt;
 }
 
 int main()
 {
    int m;
    int res;
    
    scanf("%d", &m);
    res= CalArmstrongNumber(m);
    
    printf("%d", res);
    
    return 0;
 }