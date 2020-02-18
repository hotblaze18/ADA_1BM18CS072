#include<iostream>

using namespace std;

int pivotedBserach(int a[],int n, int key)
{
	int left = 0;
	int right = n-1;

	while(left <= right)
	{
		int mid = (left + right)/2;
		if(a[mid] == key)
		{
			return mid;
		}
		else if(key < a[mid])
		{
			if(key < a[left])
				left = mid+1;
			else
				right = mid-1;	
		}
		else if(key > a[mid])
		{
			if(key < a[right])
				left = mid+1;
			else 
				right = mid-1; 
		}
	}
	return -1;
}

int main() 
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int key;
	cin>> key;
	int index = pivotedBserach(a, n, key);
	cout<< index+1;
	return 0;
}
