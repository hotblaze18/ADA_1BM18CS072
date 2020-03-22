#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addEdge(list<int> *adj, int u, int v)
{
    adj[u].push_back(v);
}

void lex_small_topological_sort(int V, list<int> *adj) {
  vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }

    multiset<int> s;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            s.insert(i);

    int cnt = 0;

    vector<int> top_order;

    while (!s.empty()) {
        int u = *s.begin();
        s.erase(s.begin());
        top_order.push_back(u);

        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            if (--in_degree[*itr] == 0)
                s.insert(*itr);
        cnt++;
    }

    if (cnt != V) {
        cout << -1;
        return;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
}

int main() {
  int n;
  cout<<"Enter the no. of vertices in the graph\n";
  cin>>n;
  list<int> *adj = new list<int>[n];
  cout<<"Enter the adjacency list\n";
  int u,v;
  while(true) {
    cout<<"Enter the edge to be inserted(-1 -1 to stop)\n";
    cin>>u>>v;
    if(u == -1) {
        break;
    }
    addEdge(adj, u, v);
  }
  lex_small_topological_sort(n, adj);
  return 0;
}
