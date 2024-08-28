#include<bits/stdc++.h>
using namespace std;
void insertnode(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
}
void breathFirstSearch(int u, vector<int> adj[], vector<bool> &visited) {
   list<int> q;
   visited[u] = true;
   q.push_back(u);
   while(!q.empty()) {
      u = q.front();
      cout << u << " ";
      q.pop_front();
      for (int i = 0; i != adj[u].size(); ++i) {
         if (!visited[adj[u][i]]) {
            visited[adj[u][i]] = true;
            q.push_back(adj[u][i]);
         }
      }
   }
}
void BFSdisc(vector<int> adj[], int V) {
   vector<bool> visited(V, false);
   for (int u=0; u<V; u++)
   if (visited[u] == false)
   breathFirstSearch(u, adj, visited);
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
   BFSdisc(adj, V);
   return 0;
}