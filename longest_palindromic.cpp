#include<iostream>
#include<string>

using namespace std;

int longest_pallindromic(char *str) 
{ 
   int n = strlen(str); 
   int i, j, c; 
   int dp[n][n];  
   
   for (i = 0; i < n; i++) 
      dp[i][i] = 1; 
  
    for (c=2; c<=n; c++) 
    { 
        for (i=0; i<n-c+1; i++) 
        { 
            j = i+c-1; 
            if (str[i] == str[j] && c == 2) 
               dp[i][j] = 2; 
            else if (str[i] == str[j]) 
               dp[i][j] = dp[i+1][j-1] + 2; 
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 
  
    return dp[0][n-1]; 
} 

int main() 
{ 
    char str[10] 
    int n = strlen(str); 
    cin >> str;
    cout<< "The lnegth of the LPS is %d", longest_pallindromic(str)); 
    return 0; 
} 
