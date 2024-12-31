#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;


int n, m;
int arr[501][501];
int visited[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int num;
int MaxArea;



void BFS(int x, int y){
	num++;
	int area = 1;
	queue <pair<int,int>> Q;
	visited[x][y]=1;
	Q.push({x,y});
	while(!Q.empty()){
		pair<int,int> cur = Q.front();
		Q.pop();
		for (int i=0; i<4; i++){
			int nx = cur.X+dx[i], ny = cur.Y+dy[i];
			
			if (nx<1 || nx > n || ny <1 || ny > m){
				continue;
			} 
			
			if (!arr[nx][ny] || visited[nx][ny]){
				continue;
			}
			else{
				visited[nx][ny]=1;
				Q.push({nx,ny});
				area++;
			}
		}
	}
	

	MaxArea = max(MaxArea,area);
	
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> arr[i][j];
		}
	}
	
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if(!visited[i][j] && arr[i][j]){
				BFS(i,j);
			}
		}
	}
	
	cout << num << "\n" << MaxArea << "\n";
	
	
}