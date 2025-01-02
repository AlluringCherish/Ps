#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;



long long remain (long long a, long long b, long long c){
	if (b==1){
		return a%c;
	}
	
	
	long long temp = remain(a, b/2,c)%c;
	
	
	if (b%2 == 0){
		return ((temp*temp)%c);
	}
	
	else{
		return (a%c)*((temp*temp)%c)%c;
	}
	
	
}

long long a,b,c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	
	cout << remain(a,b,c);
	
	
	
	
}