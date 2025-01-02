#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;

vector <pair<int,pair<int, int>>> cctv;
int n,m;
int arr[9][9];
int visited[9][9];
int num_cctv;
int ans=INT_MAX;

void right (int x, int y, int cctv_num){
	for (int i=y+1; i<=m; i++){
		if (arr[x][i]==6){
			break;
		}
		else if (arr[x][i]==0){
			arr[x][i]=7; // 7 equals to wall
			visited[x][i]=cctv_num;
		}
	}
}

void recovery_right (int x, int y, int cctv_num){
	for (int i=y+1; i<=m; i++){
		if (arr[x][i]==6){
			break;
		}
		else if (arr[x][i]==7 && visited[x][i]==cctv_num){
			arr[x][i]=0;
			visited[x][i]=-1;
		}
	}
}

void left (int x, int y, int cctv_num){
	for (int i=y-1; i>=1; i--){
		if (arr[x][i]==6){
			break;
		}
		else if (arr[x][i]==0){
			arr[x][i]=7; // 7 equals to wall
			visited[x][i]=cctv_num;
		}
	}
}

void recovery_left (int x, int y, int cctv_num){
	for (int i=y-1; i>=1; i--){
		if (arr[x][i]==6){
			break;
		}
		else if (arr[x][i]==7 && visited[x][i]==cctv_num){
			arr[x][i]=0;
			visited[x][i]=-1;
		}
	}
}

void up (int x, int y, int cctv_num){
	for (int i=x-1; i>=1; i--){
		if (arr[i][y]==6){
			break;
		}
		else if (arr[i][y]==0){
			arr[i][y]=7; // 7 equals to wall
			visited[i][y]=cctv_num;
		}
	}
}

void recovery_up (int x, int y, int cctv_num){
	for (int i=x-1; i>=1; i--){
		if (arr[i][y]==6){
			break;
		}
		else if (arr[i][y]==7 && visited[i][y]==cctv_num){
			arr[i][y]=0; // 7 equals to wall
			visited[i][y]=-1;
		}
	}
}


void down (int x, int y, int cctv_num){
	for (int i=x+1; i<=n; i++){
		if (arr[i][y]==6){
			break;
		}
		else if (arr[i][y]==0){
			arr[i][y]=7; // 7 equals to wall
			visited[i][y]=cctv_num;
		}
	}
}

void recovery_down (int x, int y, int cctv_num){
	for (int i=x+1; i<=n; i++){
		if (arr[i][y]==6){
			break;
		}
		else if (arr[i][y]==7 && visited[i][y]==cctv_num){
			arr[i][y]=0; // 7 equals to wall
			visited[i][y]=-1;
		}
	}
}


void cctv_one (int x, int y, int dir, int cctv_num){ // 4 directions : right. clockwise.
	if (dir == 0 ){ // right
		right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // down
		down(x,y,cctv_num);
	}
	
	else if (dir == 2 ){ // left
		left(x,y,cctv_num);
	}
	
	else if (dir == 3 ){ // up
		up(x,y,cctv_num);
	}	
}

void recovery_cctv_one(int x, int y, int dir,int cctv_num){
	if (dir == 0 ){ // right
		recovery_right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // down
		recovery_down(x,y,cctv_num);
	}
	
	else if (dir == 2 ){ // left
		recovery_left(x,y,cctv_num);
	}
	
	else if (dir == 3 ){ // up
		recovery_up(x,y,cctv_num);
	}
}

void cctv_two (int x, int y, int dir, int cctv_num){ // 2 directions : left and right clockwise.
	if (dir == 0 ){ // left and right
		left(x,y,cctv_num);
		right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // up and down
		up(x,y,cctv_num);
		down(x,y,cctv_num);
	}
}

void recovery_cctv_two (int x, int y, int dir, int cctv_num){ // 2 directions : left and right clockwise.
	if (dir == 0 ){ // left and right
		recovery_left(x,y,cctv_num);
		recovery_right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // up and down
		recovery_up(x,y,cctv_num);
		recovery_down(x,y,cctv_num);
	}
}

void cctv_three (int x, int y, int dir,int cctv_num){ // 4 directions 
	if (dir == 0 ){ // up and right
		up(x,y,cctv_num);
		right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // right and down
		right(x,y,cctv_num);
		down(x,y,cctv_num);
	}
	
	else if (dir == 2){ // down and left
		down(x,y,cctv_num);
		left(x,y,cctv_num);
	}
	else if (dir==3){ // left and up
		left(x,y,cctv_num);
		up(x,y,cctv_num);
	}
}

void recovery_cctv_three (int x, int y, int dir, int cctv_num){ // 4 directions 
	if (dir == 0 ){ // up and right
		recovery_up(x,y,cctv_num);
		recovery_right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // right and down
		recovery_right(x,y,cctv_num);
		recovery_down(x,y,cctv_num);
	}
	
	else if (dir == 2){ // down and left
		recovery_down(x,y,cctv_num);
		recovery_left(x,y,cctv_num);
	}
	else if (dir==3){ // left and up
		recovery_left(x,y,cctv_num);
		recovery_up(x,y,cctv_num);
	}
}

void cctv_four (int x, int y, int dir, int cctv_num){ // 4 directions 
	if (dir == 0 ){ // left,up,right
		left(x,y,cctv_num);
		up(x,y,cctv_num);
		right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // up and right and down
		up(x,y,cctv_num);
		right(x,y,cctv_num);
		down(x,y,cctv_num);
	}
	
	else if (dir == 2){ // right, down and left
		right(x,y,cctv_num);
		down(x,y,cctv_num);
		left(x,y,cctv_num);
	}
	else if (dir==3){ //left, down and up
		down(x,y,cctv_num);
		left(x,y,cctv_num);
		up(x,y,cctv_num);
	}
}

void recovery_cctv_four (int x, int y, int dir,int cctv_num){ // 4 directions 
	if (dir == 0 ){ // left,up,right
		recovery_left(x,y,cctv_num);
		recovery_up(x,y,cctv_num);
		recovery_right(x,y,cctv_num);
	}
	else if (dir == 1 ){ // up and right and down
		recovery_up(x,y,cctv_num);
		recovery_right(x,y,cctv_num);
		recovery_down(x,y,cctv_num);
	}
	
	else if (dir == 2){ // right, down and left
		recovery_right(x,y,cctv_num);
		recovery_down(x,y,cctv_num);
		recovery_left(x,y,cctv_num);
	}
	else if (dir==3){ //left, down and up
		recovery_down(x,y,cctv_num);
		recovery_left(x,y,cctv_num);
		recovery_up(x,y,cctv_num);
	}
}


void cctv_five (int x, int y, int cctv_num){ // 4 directions 
	left(x,y,cctv_num);
	up(x,y,cctv_num);
	right(x,y,cctv_num);
	down(x,y,cctv_num);
}

void recovery_cctv_five (int x, int y, int cctv_num){ // 4 directions 
	recovery_left(x,y,cctv_num);
	recovery_up(x,y,cctv_num);
	recovery_right(x,y,cctv_num);
	recovery_down(x,y,cctv_num);
}

void update_ans(){
	int temp = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (arr[i][j]==0){
				temp++;
			}
		}
	}
	if (ans > temp){
		ans = temp;
	}
}

void solve(int cur){
	if (cur==num_cctv){
		update_ans();
		return;
	}
	
	auto c = cctv[cur];
	int x = c.Y.X;
	int y = c.Y.Y;
	int type = c.X;
	if (type == 1){
		for (int i=0; i<4; i++){
			cctv_one(x,y,i,cur);
			solve(cur+1);
			recovery_cctv_one(x,y,i,cur);
		}
	}
	
	else if (type==2){
		for (int i=0; i<2; i++){
			cctv_two(x,y,i,cur);
			solve(cur+1);
			recovery_cctv_two(x,y,i,cur);
		}
	}
	
	else if (type==3){
		for (int i=0; i<4; i++){
			cctv_three(x,y,i,cur);
			solve(cur+1);
			recovery_cctv_three(x,y,i,cur);
		}
	}
	
	else if (type==4){
		for (int i=0; i<4; i++){
			cctv_four(x,y,i,cur);
			solve(cur+1);
			recovery_cctv_four(x,y,i,cur);
		}
	}
	
	else if (type==5){
		cctv_five(x,y,cur);
		solve(cur+1);
		recovery_cctv_five(x,y,cur);
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> arr[i][j];
			if (arr[i][j]!=0 && arr[i][j]!=6){
				cctv.emplace_back(arr[i][j],make_pair(i,j));
				num_cctv++;
			}
		}
	}

	solve(0);
	
	/***	
	cout << "\n";
	cout << "\n";
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*///
	 
	cout << ans;
	
	return 0;
	
}