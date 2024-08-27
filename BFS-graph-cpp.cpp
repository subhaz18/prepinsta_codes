#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    int e;
    int **adj;
    public :
    graph(int v,int e);
    void newedge(int start,int e);
    void bfs(int start);
};
graph::graph(int v,int e){
    this->v=v;
    this->e=e;
    adj=new int*[v];
    for(int row=0;row<v;row++){
        adj[row]=new int[v];
        for(int col=0;col<v;col++){
            adj[row][col]=0;
        }
    }
}
void graph :: newedge(int start,int e){
    adj[start][e]=1;
    adj[e][start]=1;
}
void graph ::bfs(int start){
   vector<bool> visited(v,false);
   vector<int> q;
   q.push_back(start);
   visited[start]=true;
   int vis;
   while(!q.empty()){
    vis=q[0];
    cout<<vis<<" ";
    q.erase(q.begin());
    for(int i=0;i<v;i++){
        if(adj[vis][i]==1 && !visited[i]){
            q.push_back(i);
            visited[i]=true;
        }
    }
   }
}
int main(){
    int v=8,e=9;
    graph g(v,e);



    g.newedge(0,1);//1
    g.newedge(0,2);//2
    g.newedge(1,3);//3
    g.newedge(2,4);//4
    g.newedge(2,6);//5
    g.newedge(3,5);//6
    g.newedge(5,4);//7
    g.newedge(3,4);
    g.newedge(6,7);//9
    g.bfs(0);

}