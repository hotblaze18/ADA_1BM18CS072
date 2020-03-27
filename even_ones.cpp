#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countOnes(int n)
{
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }

    if (count % 2 == 0)
        return 1;
    else
        return 0;
}

int sumDigits(int n)
{
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int n;
    cout<<"Enter the no. of elements in the array\n";
    cin>>n;
    int arr[n]
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        if (countOne(arr[i]))
            total_sum += sumDigits(arr[i]);
    }

    cout << total_sum << '\n';

    return 0;
}
