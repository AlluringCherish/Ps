#include <bits/stdc++.h>
#include <limits.h>
#define X first
#define Y second

using namespace std;


int arr[14];
int brr[14];

void init(){
	
	for (int i=0; i<14; i++){
		arr[i]=0;
		brr[i]=0;
	}
	
	for (int i=0; i<6; i++ ){
		brr[i]=1;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	
	while(true){
		int choice;
		cin >> choice;
		if (choice==0){
			break;
		}
		
		
		for (int i=0; i<choice; i++){
			cin >> arr[i];
		}
		
		
		for (int i=0; i<6; i++ ){
			brr[i]=0;
		}
		
		for (int i=6; i<14; i++ ){
			brr[i]=1;
		}
		
		do{
			for (int i=0; i<choice; i++){
				if(brr[i]==0){
					cout << arr[i] << " ";
				}
			}
			cout << "\n";
		}while(next_permutation(brr,brr+choice));
		cout << "\n";
	}
	
	
	return 0;
	
}