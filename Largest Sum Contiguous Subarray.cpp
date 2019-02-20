#include <bits/stdc++.h> 
using namespace std;

int maxSubarray(int arr[],int size){
	
	int max_ending_here = 0, maxima =0; 
	for (int i = 0; i < size; ++i)
	{
		max_ending_here += arr[i]; 
		if(max_ending_here < 0) max_ending_here =0; //reset
		if(max_ending_here > maxima) maxima = max_ending_here; 
	}
	return maxima > 0? maxima : 0; 

}

int main(){

	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	
	int n; 
	while(1){
		cin >> n; 
		if(n==0) break; 
		int arr[n]; 
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i]; 
		}
		int ans = maxSubarray(arr, sizeof(arr)/sizeof(arr[0])); 
		if(ans > 0){
			printf("The maximum winning streak is %d.\n",ans );
											
		}
		else {
			printf("%s\n","Losing streak." );
		}

	}

	

	return 0;
}

