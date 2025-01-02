#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

 //a to b with n elements. 
int solve (int n, int r, int c){
	if (n==0){
		return 0;
	}
	
	int a = 1<<(n-1);
	
	if (r<a && c<a){
		return solve(n-1,r,c);
	}
	
	else if (r<a && c>=a){
		return a*a+solve(n-1,r,c-a);
	}
	
	else if (r>=a && c<a){
		return 2*a*a+solve(n-1,r-a,c);
	}
	else{
		return 3*a*a+solve(n-1,r-a,c-a);
	}
	
	
	
}

int n,r,c;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;
	
	cout << solve(n,r,c);
	
	
	
	
}