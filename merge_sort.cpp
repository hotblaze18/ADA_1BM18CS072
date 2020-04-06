#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void merge_sort_util(int arr[], int left, int right, int mid) {
    int left_i = left;
    int right_i = mid+1;
    while(left_i <= mid && right_i <= right) {
        if(arr[left_i] < arr[right_i]) {
           left_i++;
        }
        if(arr[left_i] >= arr[right_i]) {
            while(right_i <= right) {
                swap(arr[left_i], arr[right_i]);
                right_i++;
                left_i++;
            }
        }
    }
}

int merge_sort(int arr[], int left, int right) {
    if(left == right) {
        return left;
    }

    int mid = (left + right) / 2;
    int left_i = merge_sort(arr, left, mid);
    int right_i = merge_sort(arr, mid+1, right);
    merge_sort_util(arr, left, right, mid);
}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }
    merge_sort(arr, 0, n-1);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout<< arr[i] << " ";
    }
    return 0;
}
