/*百分制成绩*/
#include<stdio.h>

char level(int score)
{
    switch(score/10){
        case 0: case 1: case 2: case 3: case 4 :case 5: 
            return 'E';
            break;
        case 6:
            return 'D';
            break;
        case 7:
            return 'C';
            break;
        case 8:
            return 'B';
            break;
        case 9: case 10:
            return 'A';
            break;
        default:
            return ' ';
            break;
	}
}

int main()
{
    int score;
    
    while(scanf("%d", &score) != EOF)
        printf("%c\n", level(score));
     
    return 0;
}