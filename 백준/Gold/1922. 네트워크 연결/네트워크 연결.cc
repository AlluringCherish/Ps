#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int n,m;

vector <tuple<int,int,int>> v;
int arr[1001];


int find(int a){
	if (arr[a]==a){
		return a;
	}
	
	else{
		return arr[a] = find(arr[a]);
	}
}


void unio (int a, int b){
	int aRoot = find(a);
	int bRoot = find(b);
	arr[aRoot] = bRoot;
}



int main(){
	cin >> n >> m;
	
	
	for (int i=1; i<=n; i++){
		arr[i]=i;
	}
	
	
	for (int i=0; i<m; i++){
		int a, b,c;
		cin >> a >> b >> c;
		tuple<int,int,int> t = make_tuple(c,a,b);
		v.push_back(t);
	}
	
	
	
	sort(v.begin(),v.end());
	
	//cout << "==========\n";
	
	int ans = 0;
	for (int i=0; i<m; i++){
		tuple<int,int,int> t = v[i];
		int a = get<0>(t), b = get<1>(t), c=get<2>(t);
		
		if (find(b)!=find(c)){
			unio(b,c);
			ans+=a;
		}
	}
	
	cout << ans;
	
	
	
	
	
	return 0; 
}