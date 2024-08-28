#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    int e;
    int **adj;
    public :
    graph(int v,int e);
    void newedge(int start,int e);
    int dfs_path_print(int start,bool *visited,int end,vector<int> &arr);
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
int graph ::dfs_path_print(int start,bool *visited,int end,vector<int> &arr){
    visited[start]=true;
    arr.push_back(start);
    if(start==end){
        return 1;
    }
    for(int i=0;i<v;i++){
        if(adj[start][i]==1 && !(visited[i])){
            if(dfs_path_print(i,visited,end,arr)){
                return 1;
            }
            
        }
    }
}
int main(){
    int v=10,e=10;
    graph g(v,e);



    g.newedge(0,1);//1
    g.newedge(0,2);//2
    g.newedge(1,3);//3
    g.newedge(1,4);
    g.newedge(2,8);//4
    g.newedge(8,9);//5
    g.newedge(3,5);//6
    g.newedge(5,7);//7
    g.newedge(6,7);//9
    g.newedge(6,4);

    bool *visited=new bool [v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int s,e1;
    cin>>s;
    cin>>e1;
    vector<int> arr;
    g.dfs_path_print(s,visited,e1,arr);
    vector<int> :: iterator it;
    for(it=arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
    }

}