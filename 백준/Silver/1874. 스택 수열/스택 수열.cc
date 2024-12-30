#include <bits/stdc++.h>
using namespace std;


int n;
stack<int> s;
int arr[100001];
vector<char> V;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i=1; i<=n; i++){
		int temp;
		cin >> temp;
		arr[i]=temp;
	}
	
	int cur = 1, r = 1;
	while(cur <=n+1 && r<=n){
		if (s.empty()){
			s.push(cur++);
			V.push_back('+');
			continue;
		}
		
		if (s.top()<arr[r]){
			s.push(cur++);
			V.push_back('+');
		}
		
		else if (s.top()==arr[r]){
			r++;
			s.pop();
			V.push_back('-');
		}
		else if (s.top()>arr[r]){
			cout << "NO";
			return 0;
		}
	}
	
	if (r==n+1){
		for (auto c:V){
			cout << c <<"\n";
		}
	}
	else{
		cout << "NO";
	}
	
	
}