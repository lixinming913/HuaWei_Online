/*求圆的面积*/

#include<stdio.h>
#define PI 3.14
#define MAX 10

void  OutPutRotundityArea(float* pResultArray, int &ArrayCount)
{
    ArrayCount = 0;
    float area = 0.0;
    int i ;
    
    for(i  = 1; i <= 10; i++) {
        area = PI * i * i;
        if(area >= 40 && area <= 90)
            pResultArray[ArrayCount++] = area;
    }
}

int main()
{
    float res[MAX];
    int arraycount;
    int i;
    
    OutPutRotundityArea(res, arraycount);
    for(i = 0; i < arraycount; i++)
    {
        printf("%f ", res[i]);
    }
        
    return 0;
}