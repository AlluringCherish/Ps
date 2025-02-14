#include <iostream>


using namespace std;


int n, m;
int arr[1000001];




int find (int b){
	if (arr[b]==b){
		return b;
	}
	else{
		return arr[b] = find(arr[b]);
	}
}

void unio (int b, int c){
	int bRoot = find(b);
	int cRoot = find(c);
	arr[bRoot]=cRoot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m; 
	
	for (int i=0; i<=n; i++){
		arr[i] = i;
	}
	
	
	for (int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if (a==0){ // union
			unio(b,c);
		}
		else{
			if (find(b) == find(c)){
				cout << "YES" << "\n";
			}
			else{
				cout << "NO" << "\n";
			}
		}
	}
	
	
	
	return 0;
}