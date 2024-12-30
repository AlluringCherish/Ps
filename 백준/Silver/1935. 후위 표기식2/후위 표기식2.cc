#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int mapp[27]; // mapp[1] : A ...
stack<double> S;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> str;
    
    for (int i=0; i<n; i++){
    	int temp;
    	cin >> temp;
    	mapp[i]=temp;
	}
	
	
	for (int i=0; i<str.size(); i++){
		if ('A'<=str[i] && str[i]<='Z'){
			S.push((double)mapp[int(str[i])-'A']);
		}
		
		else {
			double p1 = S.top();
			S.pop();
			double p2 = S.top();
			S.pop();
			if (str[i]=='+'){
				S.push(p1+p2);
			}
			else if (str[i]=='-'){
				S.push(p2-p1);
			}
			
			else if (str[i]=='/'){
				S.push(p2/p1);
			}
			else if (str[i]=='*'){
				S.push(p1*p2);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << S.top();

} 