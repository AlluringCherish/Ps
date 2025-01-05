#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;

int n,m;
int arr[51][51];
int chicken[14][2]; // [i][0] : ith chicken x, [i][1] : ith chicken y
int isusedChicken[14];
int numchicken;
int visited[51][51];


int dx[4]= {0,0,1,-1};
int dy[4]= {-1,1,0,0};

int cityDistance(){
	int min = INT_MAX;
	
	for (int i=m+1; i<=numchicken; i++){
		isusedChicken[i]=1;
	}
	
	do{
		for (int i=0; i<51; i++){
			for (int j=0; j<51; j++){
				visited[i][j]=-1;
			}
		}
		
		int temp = 0;
		
		queue <pair<int,int>> Q;
		
		for (int i=1; i<=numchicken; i++){
			if (!isusedChicken[i]){
				Q.push({chicken[i][0],chicken[i][1]});
				visited[chicken[i][0]][chicken[i][1]]=0;
			}
		}
		
		while(!Q.empty()){
			auto cur = Q.front();
			Q.pop();
			for (int i=0; i<4; i++){
				int nx = cur.X+dx[i], ny = cur.Y+dy[i];
				
				if(nx <1 || nx > n || ny <1 || ny >n ){
					continue;
				}
				
				if (visited[nx][ny]>=0){
					continue;
				}
				
				else{
					visited[nx][ny]=visited[cur.X][cur.Y]+1;
					Q.push({nx,ny});
				}
			}
		}
		
		//cout << "\n";
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				//cout << visited[i][j] << " ";
				if(arr[i][j]==1){
					temp += visited[i][j];
				}
			}
			
			//cout << "\n";
		}
		
		//cout << "Current step temp: " << temp << "\n";
		
		if (min > temp){
			min = temp;
		}
		
	}while(next_permutation(isusedChicken+1,isusedChicken+1+numchicken));
	
	
	return min;
}


 
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> arr[i][j];
			if (arr[i][j]==2){
				numchicken++;
				chicken[numchicken][0] = i;
				chicken[numchicken][1] = j;
			}
		}
		
	}
	
	cout << cityDistance();
	return 0;
	
}