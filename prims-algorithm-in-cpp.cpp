#include<bits/stdc++.h>
using namespace std;
#define v 7
int min_key(int key[],bool mst_set[]){
    int min = INT_MAX, min_index;
    for(int i=0;i<v;i++){
        if(mst_set[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
}
void print_mst(int parent[],int graph[v][v]){
    cout<<"Edge \tWeight\n";
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"-"<<i<<"-"<<graph[i][parent[i]]<<"\n";
    }
}
void primsMst(int graph[v][v]){
    int parent[v];
    int key[v];
    bool mst_set[v];
    for(int i=0;i<v;i++){
        key[i] = INT_MAX;
        mst_set[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int cout=0;cout<v-1;cout++){
        int u = min_key(key,mst_set);
        mst_set[u]=true;
        for(int i=0;i<v;i++){
            if(graph[u][i] && mst_set[i] == false && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    print_mst(parent,graph);
}
int main(){
    int graph[v][v] = {
        {0,9,0,0,0,1,0},
        {9,0,4,0,0,0,3},
        {0,4,0,2,0,0,0},
        {0,0,2,0,6,0,5},
        {0,0,0,6,0,8,7},
        {1,0,0,0,8,0,0},
        {0,3,0,5,7,0,0},
    };
    primsMst(graph);
    return 0;
}