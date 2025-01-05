#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;


int n,m,k;
int r, c;
int sticker[11][11];
int board[41][41];
int ans;

//clockwise rotate(void) ..  transpose - > reverse col
void rotate (){
	int temp[11][11];
	
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			temp[i][j] = sticker[i][j];
		}
	}
	swap(r,c);
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			sticker[i][j] = temp[c-j+1][i];
		}
	}
	
}

bool check(int x,int y){
	//cout << "case1 " << x << y << "\n";
	if (x+r > n+1 || y+c > m+1){
		return false;
	}

	for (int i=x; i<x+r; i++){
		for (int j=y; j<y+c; j++){
			if (sticker[i-x+1][j-y+1]){
				if(board[i][j]){
					return false;
				}
			}
		
			
		}
	}
	//cout << "case2 " << x << y << "\n";
	return true;
}


void paste(int x,int y){
	for (int i=x; i<x+r; i++){
		for (int j=y; j<y+c; j++){
			if (sticker[i-x+1][j-y+1]){
				board[i][j]=1;
			}
			
		}
	}
}


 
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m >> k;
	
	for (int i=1; i<=k; i++){
		cin >> r >> c;
		for (int j=1; j<=r; j++){
			for (int z=1; z<=c; z++){
				cin >> sticker[j][z];
			}
		}
		
		
		for (int w=0; w<4; w++){
			int flag = 0;
			for (int j=1; j<=n; j++){
				for (int z=1; z<=m; z++){
					if(check(j,z)){
						paste(j,z);
						//cout << "attach!" << j<< z <<"\n";
						flag = 1;
						break;
					}
				}
				
				if (flag){
					break;
				}
			}
			
			if (flag){
				break;
			}
			rotate();
		}
			
		
	
		
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (board[i][j]==0){
				ans++;
			}
			//cout << board[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << n*m-ans;
	
	return 0;
	
}