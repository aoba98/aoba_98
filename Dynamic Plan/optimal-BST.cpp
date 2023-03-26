#include <iostream>
#include <limits> 
#include <vector>  
#include <algorithm>
#include <string>
#include <queue>
#include <cfloat>
using namespace std;
void optimalBST(double *p, double *q, int n){
    double **e = new double*[n+2];
    double **w = new double*[n+2];
    int **root = new int*[n+1];
    for(int i = 0; i < n+2; i++){
        e[i] = new double[n+1];
        w[i] = new double[n+1];
        if(i < n+1)
            root[i] = new int[n+1];
    }
    for(int i = 1; i <= n+1; i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(int l = 1; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            e[i][j] = 1.7976931348623157e+308;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(int r = i; r <= j; r++){
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if(t < e[i][j]){
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "The optimal cost is " << e[1][n] << endl;
    queue<pair<int,int> > qq;  // pair<left, right>
    pair<int, int> r(1,n);
    qq.push(r);
    while(!qq.empty()){
        pair<int, int> pp = qq.front();
        qq.pop();
        int i = pp.first;
        int j = pp.second;
        if(i > j)
            continue;
        cout << "k" << root[i][j] << " is the root of ";
        if(i == j)
            cout << "d" << i << endl;
        else
            cout << "k" << i << " and k" << j << endl;
        pair<int, int> p1(i, root[i][j]-1);
        pair<int, int> p2(root[i][j]+1, j);
        qq.push(p1);
        qq.push(p2);
    }
}
int main(){
    double p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    double q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    optimalBST(p, q, 5);
    return 0;
}