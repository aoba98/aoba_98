#include <iostream>
using namespace std;
void FindMax(int* a,int n){
 int* DP=new int[n]{0};
 int* Rec=new int[n]{0};
 DP[n-1]=a[n-1];
 Rec[n-1]=n;
 int max=a[n-1];
 int k=n;
 for(int i=n-2;i>=0;i--){
 if(DP[i+1]<=a[i]) {
    DP[i]=a[i];
    Rec[i]=i+1;
    }
 else {
    DP[i]=DP[i+1]+a[i];
    Rec[i]=Rec[i+1];
 }
 if(DP[i]>max){max=DP[i];k=i+1;}
 }
 cout<<"the maxsubArrySum is"<<max<<"From"<<k<<"to"<<Rec[k-1];
}
int main(){
    int n;
    cout<<"Please input how long are the Arry"<<endl;
    cin>>n;
    int* a=new int[n]{0};
    cout<<"Please input values in arry in order"<<endl;
    for(int i=0;i<n;i++) cin>>a[i];
    FindMax(a,n);
    system("pause");
}