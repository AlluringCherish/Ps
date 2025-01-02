#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;


int arr[21];
int n,s;
int ans;

void solve(int cur,int sum){
	if (cur == n+1){
		if (sum == s){
			ans++;
		}
		return;
	}
	
	/*** Incorrect solution : 3,5 == 5, 3
	for (int i=1; i<=n; i++){
		if(!brr[i]){
			brr[i]=1;
			solve(cur+1, sum+arr[i]);
			solve(cur+1, sum);
			brr[i]=0;
		}
	}***/
	solve(cur+1, sum+arr[cur]);
	solve(cur+1, sum);
	
	return;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	
	for (int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	solve(1,0);
	
	if (s==0){
		ans--;
	}
	cout << ans;
	
	return 0;
	
}