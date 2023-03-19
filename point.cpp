#include <bits/stdc++.h>
using namespace std;
class point
{
private:
    int x,y;
    
public:
    point(int xx,int yy);void print();
    ~point();
};

point::point(int xx,int yy)
{
    x=xx;y=yy;
}

point::~point()
{
}
void point::print(){
    cout<<x<<y;

}
int main(){
    int x,y;
    cout<<"x,y=";
    cin>>x>>y;
    point a(x,y);
    a.print();
    system("pause");
}