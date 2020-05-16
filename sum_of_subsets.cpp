#include <iostream>
#include <stack>
 
using namespace std;
  
stack<int> solutionSet;
bool hasSolution;
 

void displaySolutionSet()
{
      
        stack<int> temp;
      
        while (!solutionSet.empty()) 
        { 
            cout <<  solutionSet.top() << " "; 
            temp.push(solutionSet.top()); 
            solutionSet.pop();
        } 
        cout << '\n';
        
        while (!temp.empty()) 
        { 
            solutionSet.push(temp.top()); 
            temp.pop();
        } 
}
  
bool solve(int s, int idx, int set[],int n,int sum)
{
    if(s>sum)
        return false;
 
    //check if stack has the right subsets of numbers
    if(s==sum){
        hasSolution = true;
        //display stack contents
        displaySolutionSet();
        //Though found a solution but deliberately 
        //returning false to find more
        return false;
    }
        
 
    for(int i=idx; i<n; i++){
        
        solutionSet.push(set[i]);
 
        //add set[i] to the 's' and recusively start from next number
        if(solve(s+set[i],i+1,set,n,sum)){
            return true;
        }
 
        //found false
        //Removing element from stack i.e Backtracking
        solutionSet.pop();
    }
    
    
    return false;
  }
  
  
    

 
int main()
{
	int n;
  	cout<<"Enter number of elements:";
  	cin>>n;
  	int set[n];
  	int sum;
  	cout<<"Enter the sum: ";
  	cin>>sum;
  	cout<<"Enter the elements of the set:"<<endl;
  	for(int i=0;i<n;i++)
    		cin>>set[i];
 
    
    	solve(0,0,set,n,sum);
	    
	if(hasSolution == false)
	    cout << "No Solution";
 
    return 0;
}
