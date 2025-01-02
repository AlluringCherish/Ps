#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int arr[2200][2200];
int ans[3];

bool check(int x, int y, int n){
	for (int i=x ; i<x+n; i++){
		for (int j=y; j<y+n; j++){
			if (arr[x][y]!=arr[i][j]){
				return false;
			}
		}
	}
	
	return true;
}


int solve (int x, int y , int n){
	if (check(x,y,n)){
		ans[arr[x][y]+1]++;
		return 0;
	}
	
	int t = n/3;
	
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			solve(x+i*t,y+j*t,t);
		}
	}
	
	return 0;
	
	
}

int n;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> arr[i][j];
		}
	}
	
	solve(1,1,n);
	
	for (int i=0; i<3; i++){
		cout << ans[i] << "\n";
	}
	
	/***
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << arr[i][j] << " ";
		}
		
		cout << "\n";
	}
	***/
	return 0;
	
}