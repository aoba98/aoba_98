#include <iostream>
using namespace std;
int conv(int* a,int s,int n);
void getMax(int a,int n,int k){//a为传入整数，k为分段数，n为整数位数
    int* c=NULL;
    int max=0,tt;
    c=new int[n];
    for(int i=n-1;i>=0;i--){
        c[i]=a%10;
        a/=10;
    }
    int** p=new int*[n]{0};
    for(int i=0;i<n;i++) p[i]=new int[k]{0};
    int** Rec=new int*[n]{0};
    for(int i=0;i<n;i++) Rec[i]=new int[k]{0};
    for(int i=0;i<n;i++) p[i][0]=conv(c,0,i+1);
    for(int j=1;j<k;j++){
        for(int i=j;i<n;i++){
            int temp=0;
            for(int t=0;t<i;t++){
                max=p[t][j-1]*conv(c,t+1,i-t);//穷举所有可能得下标到i位的最大j乘
                if(temp<max){
                    temp=max;
                    tt=t;
                }
            }
            p[i][j]=temp;
            Rec[i][j]=tt;
        }
    }

     cout<<"Max value is"<<p[n-1][k-1]<<endl;
     int nn=n,kk=k;
     for (int i = 1; i < k; i++)
     {
         cout<<"break from position"<<Rec[nn-1][kk-1]+1<<endl;
         nn=Rec[nn-1][kk-1];
         kk--;
     }
     
}
int conv(int* a,int s,int n){//a数组下标s开始的n位数字的大小
    int temp=0;
    for (int i=s;i<s+n;i++){
        temp=temp*10+a[i];
    }
    return temp;
}
int main(){
    int n,k,a;
    cout<<"input n and k of Integer:"<<endl;
    cin>>n>>k;
    cout<<"input the Interger:"<<endl;
    cin>>a;
    getMax(a,n,k);
    system("pause");
    return 0;
}