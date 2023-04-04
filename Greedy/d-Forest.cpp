#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// 算法要求：设计一个算法求 T 的最小顶点集合 S，使 T/S 为一个 d 森林。

class dTree{
public:
dTree(int n, int d) { 
    int num;
    Vertex* tree=new  Vertex[n];     //此处为构造函数，初始化构建树。
    for(int i=0;i<n;i++){
        cin>>num;
    }
}
void solution(){
                //main函数通过调用dTree类的solution函数，通过cout输出结果。
}
private:
int n, d; //n为顶点个数，d为路径长度
typedef struct edgeNode* Edge;
struct edgeNode
{
    int weight; //权值
    Edge next; //下一条边
};

 struct vertexNode
{
    int accumulative; //累计值
    int parent; //父节点
    Edge firstEdge; //第一条边
};
typedef struct vertexNode Vertex;

};
int main() {
int n, d;               //n为顶点个数，d为路径长度
cin >> n >> d;
dTree dt(n, d);    //构建与初始化树
dt.solution();      //通过solution函数输出结果
return 0;
}