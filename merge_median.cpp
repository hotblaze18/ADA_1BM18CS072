#include<bits/stdc++.h> 
using namespace std; 
  
float median(int a[], int n) 
{ 
    if (n % 2 == 0) 
        return (float)(a[n / 2] +  a[(n / 2 )- 1]) / 2; 
    else
        return a[n / 2]; 
} 
 
  
float findMedian(int a1[], int a2[], int n) 
{ 
   
    	if (n <= 0) 
        	return -1; 
    	if (n == 1) 
        	return (float)(a1[0] + a2[0]) / 2; 
    	if (n == 2) 
        	return (float)(max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2; 
  
    
    	int m1 = median(a1, n);  
    	int m2 = median(a2, n);  
  
    	if (m1 == m2) 
        	return m1; 
  
    
    	if (m1 < m2) 
    	{ 
        	if (n % 2 == 0) 
            		return findMedian(a1 + (n / 2) - 1,  a2, n -( n / 2) + 1); 
        	return findMedian(a1 + (n / 2),  a2, n - (n / 2)); 
    	} 
  
 
    	if (n % 2 == 0) 
        	return findMedian(a2 + (n / 2 )- 1,  a1, n - (n / 2 )+ 1); 
    	return findMedian(a2 + (n / 2),  a1, n -( n / 2)); 
} 
  



int main()
{
	int n;
	cout<<"Enter size of the arrays"<<endl;
	cin>>n;
	int a[n],b[n];
	cout<<"Enter elements of 1st array"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"Enter the elements of 2nd array"<<endl;
	for(int i=0;i<n;i++)
		cin>>b[i];
  	cout<<"Median : "<<findMedian(a,b,n)<<endl;
	return 0;
}
