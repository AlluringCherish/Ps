#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
queue<int> Q;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    
    for (int i=1; i<=n; i++){
    	Q.push(i);
	}
	
	cout << "<";
	while(true){
		for (int i=1; i<k; i++){
			Q.push(Q.front());
			Q.pop();
		}
		
		cout << Q.front();
		Q.pop();
		
		if (Q.empty()){
			break;
		}
		else{
			cout << ", ";
		}
	}
	
	cout << ">";
	
} 