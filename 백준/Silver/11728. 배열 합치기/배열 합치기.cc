#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;

int n,m;
int arr[1000001],brr[1000001];
int ans[2000001];
 
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;

	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for (int i=0; i<m; i++){
		cin >> brr[i];
	}


	int l = 0, r = 0, s=0;
	for (int i=0; i<n+m; i++){
		if (l==n){
			ans[i]=brr[r++];
		}
		else if (r==m){
			ans[i]=arr[l++];
		}
		else if (arr[l]<=brr[r]){
			ans[i]=arr[l++];
		}
		else{
			ans[i]=brr[r++];
		}
	}
	
	for (int i=0; i<n+m; i++){
		cout << ans[i] << " ";
	}
	


	return 0;
	
}