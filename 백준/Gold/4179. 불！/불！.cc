#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;


int n, m;
string arr[1001];
int fire_visited[1001][1001];
int visited[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue <pair<int,int>> fire_Q;
queue <pair<int,int>> Q;
int flag;
int ans;
void fire_BFS(){
	
	while(!fire_Q.empty()){
		auto cur = fire_Q.front();
		fire_Q.pop();
		for (int i=0; i<4; i++){
			int nx = cur.X+dx[i], ny = cur.Y+dy[i];
			
			if (nx<0 || nx >= n || ny <0 || ny >= m){
				continue;
			} 
			
			if (arr[nx][ny]=='#' || fire_visited[nx][ny]>=0){
				continue;
			}
			else{
				fire_visited[nx][ny]=fire_visited[cur.X][cur.Y]+1;
				fire_Q.push({nx,ny});
			}
		}
	}
	
}

void BFS(){
	
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		if (cur.X == 0 || cur.X == n - 1 || cur.Y == 0 || cur.Y == m - 1){
            // 현재 위치에 불이 도달하지 않았거나, 'J'가 도달하는 시간보다 늦게 도달하는 경우에만 탈출 가능
            if (fire_visited[cur.X][cur.Y] == -1 || fire_visited[cur.X][cur.Y] > visited[cur.X][cur.Y]){
                flag = 1;
                ans = visited[cur.X][cur.Y] + 1;
                break;
            }
        }
		for (int i=0; i<4; i++){
			int nx = cur.X+dx[i], ny = cur.Y+dy[i];
			
			
			
			
			if (nx<0 || nx >= n || ny <0 || ny >= m){
				continue;
			} 
			
			if (arr[nx][ny]=='#' || visited[nx][ny]>=0 ||(fire_visited[nx][ny]!=-1 && fire_visited[nx][ny]<=visited[cur.X][cur.Y]+1)){
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
		for (int j=0; j<m; j++){
			fire_visited[i][j]=-1;
			visited[i][j]=-1;
		}
	}
	
	
	for (int i=0 ; i<n ;i++){
		cin >> arr[i];
		for (int j=0; j<arr[i].size();j++){
			if (arr[i][j] == 'F'){
				fire_Q.push({i,j});
				fire_visited[i][j]=0;
			}
			else if (arr[i][j]=='J'){
				Q.push({i,j});
				visited[i][j]=0;
			}
		}
	}
	
	fire_BFS();
	
	
	
	BFS();
	if (flag){
		cout << ans;
	}
	else{
		cout << "IMPOSSIBLE";
	}
	
	/***
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << fire_visited[i][j] << " ";
				
		}
		cout << "\n";
		
	}
	cout << "\n";
	
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << visited[i][j] << " ";
				
		}
		cout << "\n";
		
	}
	***/
	
	
	
	
	
	

	
}