#include<iostream>
#include <ctime>

using namespace std;

int Bsearch_recursive(int a[], int left, int right, int key)
{
	if(left>right)
		return -1;
	
	int mid = (left+right)/2;
	if(a[mid] == key)
		return mid;
	else if(key < a[mid])	
		return Bsearch_recursive(a, left, mid-1, key);
	else
		return Bsearch_recursive(a, mid+1, right, key);
}

int Lsearch_recursive(int a[], int left, int right, int key)
{
	if(left>right)
		return -1;
	
	if(a[left] == key)
		return left;
	else {
		left++;
		return Lsearch_recursive(a, left, right, key);
	}
}

int main()
{
	int a[] = {12,15,19,21,26,50};
	int ib = Bsearch_recursive(a, 0, 5, 21);
	int il = Lsearch_recursive(a, 0, 5, 21);
	cout<< il << " " << ib;
	return 0;
}
