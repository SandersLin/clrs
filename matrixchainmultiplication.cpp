#include <bits/stdc++.h> 
using namespace std;

int dims[] =  {10, 20, 30} ;
int dp[5][5]; 


int matrixChain(int i,int j){
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	else if(i == j){
		dp[i][j] == 0; 
		return 0; 
	}
	else{
		int maxima = INT_MAX;
		for (int q = i; q < j ; ++q)
		{
			maxima = min(maxima, matrixChain(i,q)+matrixChain(q+1,j)+dims[i-1]*dims[j]*dims[q]);

			
		}
		dp[i][j] = maxima; 
		return maxima; 
	}

}

int main(){

	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	

	
	
	for (int i = 0; i < 5; ++i)
	{	
		for (int j = 0; j < 5; ++j)
		{
			dp[i][j] = -1; 
		}
	}
	
	int ans = matrixChain(1,2); 
	cout << ans << endl;

	return 0;
}

