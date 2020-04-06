#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void quick_sort(vector<int> &a, int l, int r)
{
    if(l >=r)
        return;

    int p = partition2(a, l, r);
    quick_sort(a, l, p-1);
    quick_sort(a, p+1, r);
}

int main()
{
    vector<int> a(5);
    for(int i=0; i<5; i++)
        std::cin>>a[i];
    quick_sort(a, 0, 4);
    for(int i=0; i<5; i++)
        std::cout<<a[i];
    return 0;
}
