#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> st;


string solve (string str){
	
	while (!st.empty()){
		st.pop();
	}
	
	int size = str.size();
	
	for (int i=0; i<size; i++){
		if (str[i]=='('){
			st.push(str[i]);
		}
		
		else{
			if (st.empty()){
				return "NO";
			}
			
			st.pop();
		}
	}
	
	
	if (st.empty()){
		return "YES";
	}
	else{
		return "NO";
	}
	
	
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i=0; i<n; i++){
    	string str;
    	cin >> str;
    	cout << solve(str) << "\n";
	}
    
	
	return 0;
} 