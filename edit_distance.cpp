#include<iostream>
#include<string>

using namespace std;
int m = 0;

int min_operations(int n,int m, char a[], char b[]) {
    if(n == 0)
        return m;

    if(m == 0)
        return n;

    if(a[n-1] == b[m-1]) {
        return min_operations(n-1, m-1, a, b) + 0;
    }
    else return min(min(min_operations(n,m-1,a,b),min_operations(n-1,m,a,b)),min_operations(n-1,m-1,a,b)) + 1;
}

int main() {
  int n, m;
  cout<<"Enter the length of the strings 1 & 2\n";
  cin>>n>>m;
  char a[n];
  char b[m];
  cout<<"Enter the first string\n";
  cin>> a;
  cout<<"Enter the second string\n";
  cin>> b;
  cout<< min_operations(n, m, a, b);
  return 0;
}
