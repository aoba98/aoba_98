#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void getMin(string s1,string s2,int k){
    ofstream fout;
    int max=26;//上限为26.规定k小于26
    fout.open("output.txt");
    int l1=s1.length();
    int l2=s2.length();
    int** p=new int*[l1+1];
    for (int i = 0; i <l1+1; i++) p[i]=new int[l2+1];
    p[0][0]=0;//两边取0个字符
    for (int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){//自底向上求解
        if(i+j){ 
            p[i][j]=max;
            int tmp;              
            if(i*j){
                    tmp=p[i-1][j-1]+abs(s1[i-1]-s2[j-1]);//假设取Ai和Bj的字符距离
                    if(tmp<p[i][j]) p[i][j]=tmp;
                }
            if(i){
                tmp=p[i-1][j]+k;//假设A中第i个取空格距离
                if(tmp<p[i][j]) p[i][j]=tmp;
            }
            if(j){
                tmp=p[i][j-1]+k;//假设B中第j个取空格距离
                if(tmp<p[i][j]) p[i][j]=tmp;
            }                
            }
        }
    }
    fout<<p[l1][l2];//输出到文件
    fout.close();
}
int main(){
    string s1,s2;
    int k;
    ifstream fin;
    fin.open("input.txt");
    fin>>s1>>s2>>k;
    getMin(s1,s2,k);
    fin.close();
    return 0;
}