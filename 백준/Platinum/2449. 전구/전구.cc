#include <iostream>
#include <algorithm>

using namespace std;



int n, k;
int arr[201];
int dp[201][201]; // dp[i][j]  i~j번째 전구를 같은 색으로 바꾸는 최소 교체 횟수

//간격 1씩 늘리면서 갱신
//만약 dp[a][b] , dp[b+1][c]에서 arr[a] , arr[b], arr[b+1] arr[c]


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << "0";
		return 0;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = 1e9;	
			}
			
		}
	}
	
	
	
	for (int diff = 1 ; diff<=n-1; diff++){
		for (int i=1; i<=n; i++){
			int j=i+diff;
			
			if (j>n){
				break;
			}
			
			if (arr[i]==arr[j]){
				for (int z = i ; z<j; z++){
					dp[i][j]=min(dp[i][j],dp[i][z]+dp[z+1][j]);
				}
			}
			else{
				for (int z = i ; z<j; z++){
					dp[i][j]=min(dp[i][j],dp[i][z]+dp[z+1][j]+1);
				}
			}
			
		}
		
	}
	
	
	/*
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j=i; j<=n; j++){
			cout << dp[i][j] << " ";
		}
		
		cout << "\n";
	}
	*/
	
	cout << dp[1][n];

	return 0;

}