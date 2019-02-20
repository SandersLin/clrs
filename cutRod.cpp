#include <bits/stdc++.h> 
using namespace std;

int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
map<int,int> m; //lenght to value mapping 


void  printCutSolution(int firstCut[]){
	int n = sizeof(arr)/sizeof(arr[0]); 
	while(n  > 0){
		cout << firstCut[n]<< " ";
		n -= firstCut[n]; 
	}
	cout << endl; 
}	

int CutRod(int n){
	//base case 
	if(n==0){
		return 0; 
	}

	if(m.find(n) != m.end()){
		return m[n]; 
	}
	//compute and save result 
	int maxima = INT_MIN; 
	for (int i = 1; i <= n; ++i)
	{
		// i = left pice size 
		maxima = max(maxima,arr[i-1]+CutRod(n-i));  

	}
	cout << n << " :"<< maxima << endl; 
	m[n] = maxima; 
	return maxima; 
}

int CutRodBottomUp(int n){
	int vals[n+1];
	int firstCut[n+1]; 

	vals[0] = 0; 
	for (int i = 1; i <= n; ++i)
	{
		int maxima = INT_MIN; 
		for (int j = 1; j <= i; ++j)
		{
			if (maxima <  arr[j-1] + vals[i-j]){
				maxima =   arr[j-1] + vals[i-j]; 
				firstCut[i] = j; 
			}
		}
		vals[i] = maxima; 
	}
	
	//print solution 
	cout << "pritning solution...." << endl; 
	printCutSolution(firstCut); 
	return vals[n]; 

}



int main(){

	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	

	 //ans 22 

	cout << CutRodBottomUp(sizeof(arr)/sizeof(arr[0])) << endl ;
	

	return 0;
}

