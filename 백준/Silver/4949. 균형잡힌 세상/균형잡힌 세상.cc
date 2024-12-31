#include <bits/stdc++.h>

using namespace std;

void solve(string str){
	stack<char> s;
	for (int i=0; i<str.size(); i++){
		if (str[i]=='[' || str[i]=='('){
			s.push(str[i]);
		}
		
		else if (str[i]==']'){
			if (!s.empty() && s.top()=='['){
				s.pop();
			}
			else{
				cout << "no" << "\n";
				return;
			}
		}
		
		else if (str[i]==')'){
			if (!s.empty() && s.top()=='('){
				s.pop();
			}
			else{
				cout << "no" << "\n";
				return;
			}
		}
	}
	if (s.empty()) {
        cout << "yes" <<"\n";
    }
    else {
        cout << "no" << "\n";
    }
}





int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		string s1;
		getline(cin,s1);
		if (s1=="."){
			break;
		}
		solve(s1);
	}
}