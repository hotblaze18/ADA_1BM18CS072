#include<iostream>
#include<vector>

using namespace std;

vector<int> fibonaci(int n) {
    vector<int> steps;
    int f = 0;
    int s = 1;
    int t = 0;
    while(t < n) {
        t = f+s;
        steps.push_back(t);
        f = s;
        s = t;
    }

    return steps;
}

int min_moves(int n, int a[], vector<int> steps) {
    int dp[n + 1];
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        int m_steps = i+1;
        if(a[i-1]) {
            for(int j=0; j<steps.size(); j++) {
                if(i >= steps[j] && dp[i-steps[j]] != -1) {
                    int m = dp[i-steps[j]] + 1;
                    if(m < m_steps)
                      m_steps = m;
                }
            }
            dp[i] = m_steps;
        }
        else dp[i] = -1;
    }
    if(m = n+1)
        return -1;
    return dp[n];
}

int main() {
  int n;
  cout<<"Enter the no. of elements in the array\n";
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>> a[i];
  }
  vector<int> steps = fibonaci(n);
  cout << min_moves(n, a, steps);
  return 0;
}

