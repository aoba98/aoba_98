#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0;//n记录总长度
    char* p=new char[20];//p记录字符串
    char* ans=new char[20]{0};//ans记录合并后的字符串
    if(!p||!ans) return 1;
    while(cin>>p){         
        char* temp =new char[n+1];//定义temp来记忆原ans数组
        if(!temp) break;
        strcpy(temp,ans);//将ans内容复制到temp
        delete[] ans;//释放ans
        ans =new char[n+strlen(p)+1]{0};//动态申请新的空间
        if(!ans) break;	
		strcpy(ans,temp);
        strcat(ans,p);//复制后拼接p
        delete[] temp;
        n+=strlen(p);//总长度增加
    }
    cout<<ans;
    system("pause");
    return 0;
}
