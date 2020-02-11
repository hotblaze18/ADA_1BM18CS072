#include<iostream>

void bsearch(int a[],int n, int key)
{
	int low = 0;
	int high = n-1;
	int mid = 0;
	std::cout<< "Entered\n";
	while(low <= high)
	{
		mid = low + high / 2;
		if(a[mid] == key)
		{
			break;
		}
		else if(key < a[mid])
		{
			high = mid - 1;
			std::cout<<"high " << high << "\n";
		}
		else
		{
			low = mid + 1;
			std::cout<<"low is " << low << "\n";
		}
	}
	if(low > high)
	{
		std::cout << "Element not found";
		return;
	}
	else
	{
		int m1 = mid;
		int m2 = mid;
		while(a[m1] == key)
		{
			m1--;
		}
		m1++;
		while(a[m2] == key)
		{
			m2++;
		}
		m2--;
		std::cout << "The element belongs to the range " << m1 << " to " << m2 << "\n" << "the count is " << m2-m1+1;
	}
}
int main() 
{
	int n;
	std::cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		std::cin>> a[i];
	}
	bsearch(a, n, 2); 
	return 0;
}
