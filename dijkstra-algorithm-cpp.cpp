#include<bits/stdc++.h>
using namespace std;
#define v 7
int mindist(int dist[],bool sptset[]){
    int min = INT_MAX, min_index;
    for(int i=0;i<v;i++){
        if(sptset[i] == false && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
}
void print(int dist[]){
    cout<<"vertex \t\t distance from source\n";
    for(int i=1;i<v;i++){
        cout<<i<<"-"<<dist[i]<<"\n";
    }
}
void dijkstra(int graph[v][v],int src){
    int dist[v];
    bool sptset[v];
    for(int i=0;i<v;i++){
        dist[i] = INT_MAX;
        sptset[i] = false;
    }
    dist[0] = 0;
    for(int cout=0;cout<v-1;cout++){
        int u = mindist(dist,sptset);
        sptset[u]=true;
        for(int i=0;i<v;i++){
            if(!sptset[i]&&graph[u][i] && dist[i]!=INT_MAX && dist[u]+graph[u][i]<dist[i]){
                dist[i] = dist[u]+graph[u][i];
            }
        }
    }
    print(dist);
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
    dijkstra(graph,0);
    return 0;
}