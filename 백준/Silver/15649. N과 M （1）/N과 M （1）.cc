#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;


int arr[9];
int brr[9];
int n,m;


int solve(int step){
	if (step==m){
		for (int i=0; i<m; i++){
			cout << brr[i] << " ";
		}
		cout << "\n";	
		return 0;
	}
	
	
	for (int i=1; i<=n ; i++){
		if (arr[i]==0){
			brr[step]=i;
			arr[i]=1;
			solve(step+1);
			arr[i]=0;
		}
	}
	
	return 0;
	
	
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	solve(0);
	
	
	
	
	return 0;
	
}