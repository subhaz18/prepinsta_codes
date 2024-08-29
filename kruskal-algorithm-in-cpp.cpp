#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define edge pair<int,int>
class graph{
    private:
    vector<pair<int,edge>> g;//creation of graph
    vector<pair<int,edge>> t;// Minimun spannning tree
    int *parent;
    int v;
    public:
    graph(int v);
    void newweightededge(int u,int v,int w);
    int find_set(int i);
    void union_set(int u,int v);
    void kruskal();
    void print();
};
graph::graph(int v){
    parent=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    g.clear();
    t.clear();
}
void graph::newweightededge(int u,int v,int w){
    g.push_back(make_pair(w,edge(u,v)));
}
int graph::find_set(int i){
    if(i==parent[i]){
        return i;
    }
    else{
        return find_set(parent[i]);
    }
}
void graph::union_set(int u,int v){
    parent[u]=parent[v];
}
void graph::kruskal(){
    int i,urep,vrep;
    sort(g.begin(),g.end());
    for(i=0;i<g.size();i++){
        urep=find_set(g[i].second.first);
        vrep=find_set(g[i].second.second);
        if(urep!=vrep){
            t.push_back(g[i]);
            union_set(urep,vrep);
        }
    }
}
void graph::print(){
    cout<<"Edges in the constructed MST"<<endl;
    int sum=0;
    for(int i=0;i<t.size();i++){
        cout<<t[i].second.first<<" -- "<<t[i].second.second<<" == "<<t[i].first<<endl;
        sum+=t[i].first;
    }
    cout<<"MINIMUM COST = "<<sum<<endl;
}
int main(){
    graph g(6);
    g.newweightededge(0,1,1);
    g.newweightededge(0,2,3);
    g.newweightededge(1,2,4);
    g.newweightededge(1,3,11);
    g.newweightededge(1,5,10);
    g.newweightededge(2,4,12);
    g.newweightededge(2,5,5);
    g.newweightededge(4,5,2);
    g.newweightededge(3,5,6);

    g.kruskal();
    g.print();

    return 0;
}