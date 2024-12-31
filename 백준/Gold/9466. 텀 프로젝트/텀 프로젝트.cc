#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n;
int arr[100001];
int visited[100001]; // 0 : not visited , -1 : Cycle, x => Check at starting x.

void solve (int x){
	int cur = x;
	while(true){
		visited[cur] = x; 
		cur = arr[cur];
		if (visited[cur] == x ){
			while(visited[cur]!=-1){
				visited[cur]=-1;
				cur = arr[cur];
			}
			return;
		}
		
		else if (visited[cur]!=0){ // already visited.
			return;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i=0; i<n; i++){
		int m;
		cin >> m;
		for (int j=1; j<=m; j++){
			visited[j]=0;
		}
		
		for (int j=1; j<=m; j++){
			cin >> arr[j];
		}
		
		for (int j=1; j<=m; j++){
			if (visited[j]!=-1){
				solve(j);
			}
		}
		
		int ans = 0;
		for (int j=1; j<=m; j++){
			
			//cout << visited[j] << " ";
			
			if (visited[j]!=-1){
				ans++;
			}
		}
		
		cout << ans << "\n";
		
		
	}
	
	
	
}