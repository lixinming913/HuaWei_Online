/*IP地址判断有效性*/

#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

bool isIPAddressValid(const char* pszIPAddr)
{
    if(!pszIPAddr || *pszIPAddr =='\0')
        return false;
        
    bool legal = false;
    unsigned int dot = 0;
    unsigned int len = 0;
    
    /*求字符串长度*/
    while(pszIPAddr[len] != '\0')
        ++len;    
        
    /*去掉尾部空格*/   
    while(pszIPAddr[len-1] == ' ')
        --len;
    
    /*略过头部空格*/
    int i = 0;
    while(pszIPAddr[i] == ' ' && i < len)
        ++i;  
        
   for(; i < len; ){
        if(pszIPAddr[i] == '0' && pszIPAddr[i+1] != '.' ) 
			break;

        if(pszIPAddr[i] == ' ' )
            break;
            
        if(isdigit(pszIPAddr[i]))
            ++i;
        if(pszIPAddr[i] == '.') {
			++dot;
			++i;
		}         
    }
    
    if(dot == 3 &&i == len)
        legal = true;
        
    return legal;
}

void test1()
{
    char *ip1 = "01.1.1.1";
    
    if(isIPAddressValid(ip1))
        cout<<ip1 << "合法" << endl;
    else
        cout<< ip1<<"不合法" << endl;
}

void test2()
{
    char *ip2 = "01.1.1";
    
    if(isIPAddressValid(ip2))
        cout<<ip2 << "合法" << endl;
    else
        cout<< ip2<<"不合法" << endl;
}

void test3()
{
    char *ip3 = "0.0.0.0";
    
    if(isIPAddressValid(ip3))
        cout<<ip3 << "合法" << endl;
    else
        cout<< ip3<<"不合法" << endl;
}

void test4()
{
    char *ip4= " 1.1.1.1 ";
    
    if(isIPAddressValid(ip4))
        cout<<ip4 << "合法" << endl;
    else
        cout<< ip4<<"不合法" << endl;
    
    char *ip5 = "1. 3. 2.2";
    
    if(isIPAddressValid(ip5))
        cout<<ip5 << "合法" << endl;
    else
        cout<< ip5<<"不合法" << endl;
}

void test5()
{
	char *ip5= " 198.12.13.1   ";
    
    if(isIPAddressValid(ip5))
        cout<<ip5 << "合法" << endl;
    else
        cout<< ip5<<"不合法" << endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
	test5();
    
    return 0;
}