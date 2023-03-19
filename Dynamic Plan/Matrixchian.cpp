#include <iostream>
#include <fstream>
using namespace std;
void getChain(int*row,int n){
    int** dp=new int*[n];
    int** Rec=new int*[n];
    for(int i=0;i<n;i++) dp[i]=new int[n];
    for(int i=0;i<n;i++) Rec[i]=new int[n];
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=0;i<n;i++) Rec[i][i]=0;
    for(int r=1;r<n;r++){
        for (int i=0;i<n-r;i++)
        {   int j=i+r;
            dp[i][j]=dp[i][j-1]+row[i]*row[j]*row[j+1];
            Rec[i][j]=i;
            for(int k=i;k<j;k++){//遍历寻找最优解
                int t=dp[i][k]+dp[k+1][j]+row[i]*row[k+1]*row[j+1];
                if(t<dp[i][j]){
                    dp[i][j]=t;
                    Rec[i][j]=k;
                }
            }
        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    cout<<"this is Rec"<<endl;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<Rec[i][j];
        }
        cout<<endl;
    }
}
int main(){
    int n;
    ifstream fin;
    fin.open("input.txt");
    fin>>n;
    int* row=new int[n+1];
    for(int i=0;i<=n;i++) fin>>row[i];
    getChain(row,n);
    system("pause");
    return 0;
}