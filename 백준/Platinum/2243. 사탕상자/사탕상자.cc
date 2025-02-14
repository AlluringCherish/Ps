#include <iostream>


using namespace std;


int n; 
int leaf;

long long arr[4000001];



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	
	
	for (leaf=1 ; leaf < 1000001; leaf*=2){
	}
	
	
	
	
	for (int i=0; i<n; i++){
		int a, b, c;
		cin >> a;
		if (a==2){
			cin >> b >> c;
			int node = leaf + b - 1;
			arr[node]+=c;
			while(node>1){
				node/=2;
				arr[node] = arr[2*node] + arr[2*node+1];
			}
			
			
			/*
			for (int j=1; j<=16; j++){
				cout << j << ": " << arr[j] << "\n";
			}*/
		}
		
		else if (a==1){
			cin >> b; // b번째 사탕 찾기 
			int node = 1;
			int num = b;
			while(node<leaf){
				if (arr[2*node] < num ){
					num-=arr[2*node];
					node =  node*2+1;
				}
				else{
					node = node*2;
				}
			}
			
			//taste = node - leaf +1
			
			int ans = node - leaf + 1;
			
			cout << ans << "\n";
			arr[node]-=1;
			
			while(node>1){
				node/=2;
				arr[node] = arr[2*node] + arr[2*node+1];
			}
			
			
		}
		
	}
	
	
	
	
	
}