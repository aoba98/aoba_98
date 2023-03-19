#include <bits/stdc++.h>
using namespace std;

int main(){
    const char* p=new char[4]{'a','b','c','\0'};//定义常量字符串并赋值
    if(!p) return 1;
    cout<<p<<endl;
    char* q=new char[5]{'d','e','f'};//剩两个空间容纳新字符和\0
    if(!q) return 1;
    cout<<q<<" "<<strlen(q)+2<<endl;//输出q和q的数组长度
    strcpy(q,p);
    char* s=new char[2]{0};//存储新字符
    if(!s) return 1;
    cin>>s;
    strcat(q,s);
    cout<<q;
    if(p) delete[] p;//释放空间
    if(q) delete[] q;
    if(s) delete[] s;
    system("pause");
    return 0;
    
}
