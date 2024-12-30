#include <bits/stdc++.h>
using namespace std;


int n;
stack<char> S;
int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++){
		int temp;
		cin >> temp;
		if (temp == 0){
			ans-=S.top();
			S.pop();
		}
		else{
			S.push(temp);
			ans+=temp;
		}
		
	}
	
	cout << ans;
	
	
	
}