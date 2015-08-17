/*找出字符串中第一个出现次数最多的字符*/

#include<iostream>
#include<string>

using namespace std;

bool FindChar(char *pInputString, char *pChar)
{

    if(!pInputString)
        return false;

    int a[256] = {0};
    for(int i = 0; pInputString[i] != '\0'; i++) {
        a[pInputString[i]]++;
    }

    int max = a[0];
    for(int i = 0; i < 256; i++) {
        if(a[i] > max)  {
            max = a[i];
			*pChar =(char) i;
        }
    }
    
    return true;
}

int main()
{
    char *pInputString = "abcdk!!!a";
    char *pchar = new char();
    if(FindChar(pInputString, pchar))
        cout<<pchar<<endl;
    else
        cout<<"异常失败\n";
        
    return 0;
}