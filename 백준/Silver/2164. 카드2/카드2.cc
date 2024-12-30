#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> Q;



int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i=1; i<=n; i++){
    	Q.push(i);
	}
    
	
	for (int i=0; i<n-1; i++){
		Q.pop();
		int temp = Q.front();
		Q.pop();
		Q.push(temp);
	}
	
	cout << Q.front();
	
	
} 