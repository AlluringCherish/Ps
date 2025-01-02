#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;



string arr[65];
int brr[65][65];
int ans[2];

bool check(int x, int y, int n){
	for (int i=x ; i<x+n; i++){
		for (int j=y; j<y+n; j++){
			if (brr[x][y]!=brr[i][j]){
				return false;
			}
		}
	}
	
	return true;
}


int solve (int x, int y , int n){
	
	
	
	if (check(x,y,n)){
			
		
		if (brr[x][y]==1){
			cout << "1";
		}
		else{
			cout << "0";
		}
		
		return 0;
	}
	
	
	
	int t = n/2;
	
	if (n!=1){
		cout << "(";	
	}
	
	for (int i=0; i<2; i++){
		
		for (int j=0; j<2; j++){
			
			solve(x+i*t,y+j*t,t);
			
		}
		
	}
	cout << ")";
	return 0;
	
	
}

int n;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		for (int j=0; j<n; j++){
			if (arr[i][j]=='1'){
				brr[i][j+1]=1;
			}
			else{
				brr[i][j+1]=0;
			}
		}
	}
	
	solve(1,1,n);
	
	/***
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << brr[i][j] << " ";
		}
		
		cout << "\n";
	}***/
	
	return 0;
	
}