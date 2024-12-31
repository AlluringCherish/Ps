#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;


int n, m;
int arr[1001][1001];
int visited[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue <pair<int,int>> Q;

void BFS(){
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		for (int i=0; i<4; i++){
			int nx = cur.X+dx[i], ny = cur.Y+dy[i];
			
			if (nx<1 || nx > n || ny <1 || ny > m){
				continue;
			} 
			
			if (arr[nx][ny]==-1 || visited[nx][ny]>=0){
				continue;
			}
			else{
				visited[nx][ny]=visited[cur.X][cur.Y]+1;
				Q.push({nx,ny});
			}
		}
	}
	
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> m >> n;
	for (int i=1 ; i<=n ;i++){
		for (int j=1; j<=m; j++){
			visited[i][j]=-1;
		}
	}
	
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> arr[i][j];
			if (arr[i][j]==1){
				Q.push({i,j});
				visited[i][j]=0;
			}	
		}
		
	}
	
	
	BFS();
	
	int flag = 0;
	int ans = 0;
	for (int i=1 ; i<=n ;i++){
		for (int j=1; j<=m; j++){
			if (arr[i][j]==0 && visited[i][j]==-1){
				flag =1;
				break;
			}
			
			else{
				ans = max (ans, visited[i][j]);
			}
			
			
		}
		
		if (flag){
			break;
		}
	}
	
	if (flag){
		cout << "-1";
	}
	else{
		if (ans == 0 ){
			cout << "0";
		}
		else{
			cout << ans;
		}
	}
	

	
}