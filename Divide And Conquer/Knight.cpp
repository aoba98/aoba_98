#include <bits/stdc++.h>
using namespace std;
typedef struct 
{
    int x;
    int y;
}grid;

class Knight
{
private:
    int m,n;
    int pos(int x, int y, int col);
    void step(int m,int n, int**a,grid *b);
    void build(int m,int n,int offx ,int offy ,int col,grid *b);
    void base(int mm,int nn, int offx,int offy);
    bool comp(int mm,int nn,int offx,int offy);
    grid *b66,*b68,*b86,*b88,*b810,*b108,*b1010,*b1012,*b1210,**link;
    
public:
    Knight(int m,int n);
    ~Knight(){};
    void out();
};

Knight::Knight(int mm,int nn)
{
    ifstream fin;
    fin.open("board_path.txt");
    int i,j,**a;
    m=mm;
    n=nn;
    b66=new grid[36];
    b68=new grid[48];
    b86=new grid[48];
    b88=new grid[64];
    b810=new grid[80];
    b108=new grid[80];
    b1010=new grid[100];
    b1012=new grid[120];
    b1210=new grid[120];
    link=new grid*[m];
    for(int k=0;k<m;k++) link[k]=new grid[n];
    a=new int*[10]; 
    for(int k=0;k<10;k++) a[k]=new int[12];
    for(i=0;i<6;i++) for(j=0;j<6;j++) fin>>a[i][j];
    step(6,6,a,b66);
    for(i=0;i<6;i++) for(j=0;j<8;j++) fin>>a[i][j];
    step(6,8,a,b68);
    step(8,6,a,b86);
    for(i=0;i<8;i++) for(j=0;j<8;j++) fin>>a[i][j];
    step(8,8,a,b88);
    for(i=0;i<8;i++) for(j=0;j<10;j++) fin>>a[i][j];
    step(8,10,a,b810);
    step(10,8,a,b108);
    for(i=0;i<10;i++) for(j=0;j<10;j++) fin>>a[i][j];
    step(10,10,a,b1010);
    for(i=0;i<10;i++) for(j=0;j<12;j++) fin>>a[i][j];
    step(10,12,a,b1012);
    step(12,10,a,b1210);
    fin.close();

}
void Knight::step(int m,int n, int**a ,grid *b){
    int i,j,k=m*n;
    if(m<n){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                int p=a[i][j]-1;
                b[p].x=i;
                b[p].y=j;
            }
        }
    }
    else{
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                int p=a[j][i]-1;
                b[p].x=i;
                b[p].y=j;
            }
        }
    }

}
bool Knight::comp(int mm,int nn,int offx,int offy){
    int mm1,mm2,nn1,nn2;
    int x[8],y[8],p[8];
    if(mm%2==1||nn%2==1||abs(mm-nn)>2||mm<6||nn<6)
    return 1;
    if(mm<12||nn<12){
        base(mm,nn,offx,offy);
        return 0;
    }
    mm1=mm/2;
    if(mm%4>0) mm1--;
    mm2=mm-mm1;
    nn1=nn/2;
    if(nn%4>0) nn1--;
    nn2=nn-nn1;
    //分割
    comp(mm1,nn1,offx,offy);
    comp(mm1,nn2,offx,offy+nn1);
    comp(mm2,nn1,offx+mm1,offy);
    comp(mm2,nn2,offx+mm1,offy+nn1);
    //合并
    x[0]=offx+mm1-1;y[0]=offy+nn1-3;
    x[1]=x[0]-1;y[1]=y[0]+2;
    x[2]=x[1]-1;y[2]=y[1]+2;
    x[3]=x[2]+2;y[3]=y[2]-1;
    x[4]=x[3]+1;y[4]=y[3]+2;
    x[5]=x[4]+1;y[5]=y[4]-2;
    x[6]=x[5]+1;y[6]=y[5]-2;
    x[7]=x[6]-2;y[7]=y[6]+1;
    for(int i=0;i<8;i++)
    p[i]=pos(x[i],y[i],n);
    for (int i = 1; i < 8; i+=2)
    {
        int j1=(i+1)%8,j2=(i+2)%8;
        if(link[x[i]][y[i]].x==p[i-1])
        link[x[i]][y[i]].x=p[j1];
        else
        link[x[i]][y[i]].y=p[j1];
        if(link[x[j1]][y[j1]].x==p[j2])
        link[x[j1]][y[j1]].x=p[i];
        else
        link[x[j1]][y[j1]].y=p[i];
    }
    return 0;

}
void Knight::base(int mm,int nn,int offx,int offy){
    if(mm==6&&nn==6)
    build(mm,nn,offx,offy,n,b66);
    if(mm==6&&nn==8)
    build(mm,nn,offx,offy,n,b68);
    if(mm==8&&nn==6)
    build(mm,nn,offx,offy,n,b86);
    if(mm==8&&nn==8)
    build(mm,nn,offx,offy,n,b88);
    if(mm==8&&nn==10)
    build(mm,nn,offx,offy,n,b810);
    if(mm==10&&nn==8)
    build(mm,nn,offx,offy,n,b108);
    if(mm==10&&nn==10)
    build(mm,nn,offx,offy,n,b1010);
    if(mm==10&&nn==12)
    build(mm,nn,offx,offy,n,b1012);
    if(mm==12&&nn==10)
    build(mm,nn,offx,offy,n,b1210);
}
void Knight::build(int m,int n,int offx,int offy,int col,grid *b){
    int i,p,q,k=m*n;
    for(i=0;i<k;i++){
        int x1=offx+b[i].x,y1=offy+b[i].y,x2=offx+b[(i+1)%k].x,y2=offy+b[(i+1)%k].y;
        p=pos(x1,y1,col);
        q=pos(x2,y2,col);
        link[x1][y1].x=q;
        link[x2][y2].y=p;
    }
}
int Knight::pos(int x,int y,int col){
    return col*x+y;
}
void Knight::out(){
    ofstream fout;
    fout.open("output.txt");
    int i,j,k,x,y,p,**a;
    a=new int*[m];
    for ( i = 0; i < n; i++)
     a[i]=new int[n]{0};
    if(comp(m,n,0,0))
    return;
    for ( i = 0; i < m; i++)
    for (j = 0; j< n; j++)
    a[i][j]=0;
    i=0;
    j=0;
    k=2;
    a[0][0]=1;
    cout<<"(0,0)"<<" ";
    fout<<"(0,0)"<<" ";
    for(p=1;p<m*n;p++){
    x=link[i][j].x;
    y=link[i][j].y;
    i=x/n;
    j=x%n;
    if(a[i][j]>0){
        i=y/n;
        j=y%n;
    }
    a[i][j]=k++;
    cout<<  "(" <<i<< "," << j << ")";
    fout<<  "(" <<i<< "," << j << ")";
    if((k-1)%n==0){
    cout<<endl;
    fout<<endl;}
    }
    cout<<endl;
    fout<<endl;
    for ( i = 0; i < m; i++)
    {
       for(j=0;j<n;j++)
       {cout<<a[i][j] <<" ";fout<<a[i][j] <<" ";}
       cout<<endl;
       fout<<endl;
    }   
    fout.close();
}
int main(){
    int m,n,offx=0,offy=0;
    ifstream fin0;
    fin0.open("input.txt"); 
    fin0>>m>>n;
    Knight k(m,n);
    k.out();
    system("pause");
    return 0;
}