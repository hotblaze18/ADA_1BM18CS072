#include<iostream>

using namespace std;

void path_matrix(int n, int* a[]) {
    int path[n][n] = {0};
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            path[i][j] = a[i][j];
        }
    }

    for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                path[i][j] = path[i][j] | (path[i][k] & path[k][j]);
            }
        }
    }

    cout<<"\nThe path matrix is as follows:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<path[i][j] << " ";
        }
        cout<< "\n";
    }
}

int main() {
  int n;
  cout<<"Enter the no. of vertices in the graph\n";
  cin>>n;
  int* a[n];
  cout<<"Enter the adjacency matrix\n";
  for(int i=0; i<n; i++) {
      a[i] = new int[n];
      for(int j=0; j<n; j++) {
          cin>>a[i][j];
      }
  }
  path_matrix(n, a);
  return 0;
}
