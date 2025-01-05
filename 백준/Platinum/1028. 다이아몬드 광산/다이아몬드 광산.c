#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define min(a,b) ((a)>(b) ? (b):(a))
#define max(a,b) ((a)>(b) ? (a):(b))

int arr[800][800];

int lu[800][800]; 
int ld[800][800];
int ru[800][800]; 
int rd[800][800];

int r,c;




int main() {
	scanf("%d %d",&r,&c);
	
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	
	
	//lu
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			if(arr[i][j]){
				lu[i][j]=lu[i-1][j-1]+1;
				ru[i][j]=ru[i-1][j+1]+1;
			}
		}
	}
	
	
	for (int i=r; i>0; i--){
		for (int j=c; j>0; j--){
			if(arr[i][j]){
				ld[i][j]=ld[i+1][j-1]+1;
				rd[i][j]=rd[i+1][j+1]+1;
			}
		}
	}
	
	
	
	int ans=0;
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			int a = min(ld[i][j],rd[i][j]);
			for (int z = a; z>0; z--){
				if ( i+2*(z-1)<=r && lu[i+2*(z-1)][j]>=z && ru[i+2*(z-1)][j]>=z){
					ans = max(ans , z);
				}
			}
		}
		
	}
	
	
	printf("%d",ans);
	
	
}