#include<iostream>
#include<bits/stdc++.h>

using namespace std;
stack<int> s;

void topological_sort_util(int n, int v, int* a[], bool visited[]) {
    visited[v-1] = true;
    for(int i=0; i<n; i++) {
        if(a[v-1][i]==1 && !visited[i]) {
            topological_sort_util(n, i+1, a, visited);
        }
    }
    s.push(v);
}

void topological_sort(int n, int v, int* a[], bool visited[]) {
  for(int i=0; i<n; i++) {
    if(!visited[i]) {
        topological_sort_util(n, i+1, a, visited);
    }
  }
}

int main() {
  int n;
  cout<<"Enter the no. of vertices in the graph\n";
  cin>>n;
  int* a[n];
  bool visited[n];
  cout<<"Enter the adjacency matrix\n";
  for(int i=0; i<n; i++) {
      a[i] = new int[n];
      visited[i] = false;
      for(int j=0; j<n; j++) {
          cin>>a[i][j];
      }
  }
  int v=1;
  topological_sort(n, v, a, visited);
  return 0;
}
