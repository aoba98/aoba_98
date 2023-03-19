#include <iostream>
using namespace std;
int main(){
    int n=0,sum=0;//n表示输入数字个数，sum表示数字总和
    cin>> n;
    int **p=NULL;//定义数组指针
    p=new int*[n];          //申请动态空间
    if(!p) return 1;
    else{
    for(int i=0;i<n;i++) {//按个数给数组复制
        p[i]=new int;
        cin>>*p[i];
        sum+=*p[i];//每个数字相加构成sum
        if(p[i]) delete[] p[i];
    }
    }
    cout<<sum;//输出
    if(p) delete[] p;//释放空间
   
    return 0;
}