#include<iostream>
#include<cstdlib>

using namespace std;

void isort(int a[], int n) {
	for(int i=0; i<n; i++) {
		int ele = a[i+1];
		for(int j=i; j>=0; j--) {
			if(a[j] > ele) {
				swap(a[j], a[j+1]);
			}
			else break;
		}
	}
}

int main() {
	int a[5] = {1, 2, 5, 2, 3};
	isort(a, 5);
	cout << "Sorted array is: ";
	int i;
	for(i=0; i<5; i++) {
		cout<< a[i] << " ";
	}	
	return 0;
}
