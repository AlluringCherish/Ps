#include <bits/stdc++.h>
using namespace std;


string str;
int n;
list<char> L;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str >> n;
	for (int i=0; i<str.size(); i++){
		L.push_back(str[i]);
	}
	
	list<char>::iterator t = L.end();
	
	for (int i=0; i<n; i++){
		string choice;
		cin >> choice;
		if (choice == "L"){
			if (t == L.begin()){
				continue;
			}
			else{
				t--;
			}
		}
		
		else if (choice == "D"){
			if (t == L.end()){
				continue;
			}
			else{
				t++;
			}
		}
		
		else if (choice == "B"){
			if ( t== L.begin()){
				continue;
			}
			else{
				t--;
				t = L.erase(t);
			}
		}
		
		else if (choice == "P"){
			char c;
			cin >> c;
			L.insert(t,c);
		}
	}
	
	for (auto c : L){
		cout << c;
	}
	
	
	
	
}