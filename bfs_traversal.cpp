#include<iostream>
#include<bits/stdc++.h>

using namespace std;

queue<int> q;
void bfs(int v, int start, int* a[], int visited[]) {

    visited[start] = 1;

    for(int i=0; i<v; i++) {
        if(a[start][i] && !visited[i]) {
            q.push(i);
        }
    }
    if(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
        bfs(v, q.front(), a, visited);
    }
}
int main() {
  int v,start;
  cin>>v;
  int *a[v], visited[v];

  for(int i=0; i<v; i++) {
    visited[i] = 0;
    a[i] = new int[v];
    for(int j=0; j<v; j++) {
        cin>>a[i][j];
    }
  }

  cin>>start;
  cout<<start<< " ";
  bfs(v, start, a, visited);
  return 0;
}
