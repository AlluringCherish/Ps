#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;


int n, m;
string arr[101];
int visited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


void BFS(int x, int y){
	queue <pair<int,int>> Q;
	visited[x][y]=0;
	Q.push({x,y});
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		for (int i=0; i<4; i++){
			int nx = cur.X+dx[i], ny = cur.Y+dy[i];
			
			if (nx<0 || nx >= n || ny <0 || ny >= m){
				continue;
			} 
			
			if (arr[nx][ny]!='1' || visited[nx][ny]>=0){
				
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
	
	
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for (int i=0 ; i<n ;i++){
		for (int j=0; j<m; j++){
			visited[i][j]=-1;
		}
	}
	
	
	BFS(0,0);
	
	cout << visited[n-1][m-1]+1 << "\n";
	
	
}