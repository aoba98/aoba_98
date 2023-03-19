#include <bits/stdc++.h>
using namespace std;
int catalan(int n){
 if(n==1) return 1;
 if(n==0) return 1;
 int count=0;
 for (int i = 0; i < n; i++)//2n大小的有序正整数（1，2，3，4，5，6.....
   //用1，0顺序标记，累计1的个数不能小于0的个数
   //两个满足上述条件的子序列相加也满足条件
 {
    count+=catalan(i)*catalan(n-1-i);//将序列分块累加求得数量
 }
 return count;
}
int main(){
ofstream fout( "output.txt" );  
ifstream fin( "input.txt" );   
   int n;
   fin>>n;
   fout<<catalan(n);
   system("pause");
   fout.close();
    fin.close();    
   return 0;
}