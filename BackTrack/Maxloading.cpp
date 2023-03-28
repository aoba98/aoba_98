#include <iostream>
#include <vector>
using namespace std;
template <class T>
T Backtrack(T c,T* w,int n,int* bestx){
    int i=1;
    int* x=new int[n+1];
    T rest=0,bestw=0,cw=0;
    for(int j=1;j<=n;j++){
        rest+=w[j];
    }
    while(1){
        while(i<=n && (cw+w[i])<=c){
            x[i]=1;
            cw+=w[i];
            rest-=w[i];
            i++;
        }
        if(i>n){
            for(int j=1;j<=n;j++)
                bestx[j]=x[j];
                bestw=cw;
            }
        else{
            x[i]=0;
            rest-=w[i];
            i++;
        }
        while(cw+rest<=bestw){
            i--;
            while(i>0&&x[i]==0){
                rest+=w[i];
                i--;
            }
            if(i==0) {
                delete[] x;
                return bestw;
            }//进入右子树
            x[i]=0;
            cw-=w[i];
            i++;
        }
    
    }
}
int main(){
    int n=0,c=0;
    cout<<"please input n and c:"<<endl;
    cin>>n>>c;
    int* w=new int[n+1];
    int* bestx=new int[n+1];
    cout<<"please input w:"<<endl;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<"bestw: "<<Backtrack(c,w,n,bestx)<<endl;
    cout<<"bestx:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<bestx[i]<<" ";
    }
    //system("pause");
    return 0;
}