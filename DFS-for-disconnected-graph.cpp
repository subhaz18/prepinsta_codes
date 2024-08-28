#include<bits/stdc++.h>
using namespace std;
void insertnode(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
}
void dfs(int u, vector<int> adj[], vector<bool> &visited) {
    cout<<u<<" ";
    visited[u]=true;
    for(int i=0;i != adj[u].size();++i){
        if(!visited[adj[u][i]]){
            visited[adj[u][i]]=true;
            dfs(adj[u][i],adj,visited);
        }
    }
}
void DFSdisc(vector<int> adj[], int V) {
   vector<bool> visited(V, false);
   for (int u=0; u<V; u++)
   if (visited[u] == false)
   dfs(u, adj, visited);
}
int main() {
   int V = 5;
   vector<int> adj[V];
   insertnode(adj, 0, 23);
   insertnode(adj, 0, 4);
   insertnode(adj, 1, 2);
   insertnode(adj, 1, 3);
   insertnode(adj, 1, 4);
   insertnode(adj, 2, 3);
   insertnode(adj, 3, 4);
   DFSdisc(adj, V);
   return 0;
}