#include <bits/stdc++.h>

using namespace std;





int pic[21];
int like[101];
int isin[101];
int n,m;
int cur =0;
int ans[101];





int main(){
	cin >> n >> m;
	
	for (int i=0; i<m; i++){
		int s;
		cin >> s;
		
		if (isin[s]>0){
			like[s]+=1;
		}
		
		
		else{//insert
			if (cur < n){
				pic[++cur]=s;
				like[s]=1;
				isin[s]=i+100;
			}
			
			else{ 
				int minIndex = 1;
				for (int j=1; j<=cur; j++){
					if (like[pic[minIndex]]> like[pic[j]]){
						minIndex = j;
					}
					
					else if (like[pic[minIndex]] == like[pic[j]]){
						if (isin[pic[minIndex]] > isin[pic[j]]){
							minIndex = j;
						}
					}
				}
				
				//cout << "PICK MIN : " << minIndex << "\n"; 
				
				isin[pic[minIndex]] = 0; 
				like[pic[minIndex]] = 0;
				
				for (int j = minIndex; j<cur; j++){
					pic[j] = pic[j+1];
				}
				
				pic[cur] = s;
				isin[s] = i+100;
				like[s] = 1;
				
				
				 
				
			}
			
		}
		
		/*
		for (int j=1; j<=cur; j++){
			cout << pic[j] << " ";
		}
		cout << "\n";
		
		*/
		
	}
	
	for (int i=1; i<=cur ; i++){
		ans[pic[i]]=1;
	}
	
	for (int i=1; i<=100; i++){
		if (ans[i]){
			cout << i << " ";
		}
	}
	
}