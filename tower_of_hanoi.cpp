#include<iostream>

void TOH(int n,char prev_tower,char aux_tower,char next_tower)
{
	if(n == 1)
	{
		std::cout<< "Disk 1 is moved from " << prev_tower << " to " << next_tower << 					"\n";
		return;
	}
	TOH(n-1, prev_tower, aux_tower, next_tower);
	std::cout << "Disk " << n << " is moved from " << prev_tower << " to " <<   	   			aux_tower << "\n";
	TOH(n-1, aux_tower, next_tower, prev_tower); 
}

int main()
{
	TOH(3,'A','B','C');
	return 0;
}
