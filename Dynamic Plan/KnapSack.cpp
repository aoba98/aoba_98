#include <bits/stdc++.h>
using namespace std;
void KnapSack(int n,int capacity,int *p,int *v){//函数接口为物品数量，背包容量，价格数组，体积数组
    int **DP=new int*[n+1]{0};
    for (int i = 0; i < n+1; i++)
    DP[i]=new int[capacity+1]{0};
    int **Refer=new int*[n+1]{0};
    for (int i = 0; i < n+1; i++)
    Refer[i]=new int[capacity+1]{0};
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=capacity; j++)
        {
            if(v[i]<=j && p[i]+DP[i-1][j-v[i]]>DP[i-1][j]){
                DP[i][j]=p[i]+DP[i-1][j-v[i]];
                Refer[i][j]=1;
            }else
            {
                DP[i][j]=DP[i-1][j];
                Refer[i][j]=0;
            }
        }       
    } 
    cout<<endl<<"the optimal value in the knapsack is: "<<DP[n][capacity]<<endl;
    int left=capacity;
    cout<<"solution is to pick number";
    for(int i=n;i>0;i--){
        if(Refer[i][left]==1){
            left-=v[i];
            cout<<i<<" ";
        }
    }
}
int main(){
    int n,capacity;
    cout<<"Please input number of item,capacity of the knapsack"<<endl;
    cin>>n>>capacity;
    int* p= new int[n+1]{0};int* v= new int[n+1]{0};
    cout<<"Please input the price of item in order"<<endl;
    for(int i=1;i<=n;i++)
    cin>>p[i];
    cout<<"Please input the volume of item in order"<<endl;
    for(int i=1;i<=n;i++)
    cin>>v[i];
    KnapSack(n,capacity,p,v);    
    system("pause");
}