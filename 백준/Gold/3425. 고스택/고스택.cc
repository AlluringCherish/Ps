#include <bits/stdc++.h>

using namespace std;
int arr[1001];
string inst[100001];
int num[100001];
int top; // 0 -> empty


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	while(1){
		int numInst = 0;
		while(1){
			string s;
			cin >> s;
			
			if (s == "QUIT"){
				return 0;
			}
			
			if (s == "END"){
				break;
			}
			
			inst[numInst] = s;
			
			if (s=="NUM"){
				int temp;
				cin >> temp;
				num[numInst] = temp;
				
			}
			
			numInst++;
			
		}
		
		
		int n;
		cin >> n;
		
		for (int i=0; i<n; i++){
			top = 0;
			bool isError = false;
			int v;
			cin >> v;
			arr[top++]=v;
			
			for (int j=0; j<numInst; j++){
				string t = inst[j];
				if (t == "NUM"){
					arr[top++] = num[j];
				}
				
				else if (t == "POP"){
					if (top == 0){
						isError = true;
						break;
					}
					top--;
				}
				
				else if ( t == "INV"){
					if (top == 0){
						isError = true;
						break;
					}
					int a = arr[--top];
					arr[top++] = (-1)*a;
				}
				
				else if ( t == "DUP"){
					if (top == 0){
						isError = true;
						break;
					}
					
					int a = arr[top-1];
					arr[top++]=a;
					
					
				}
				
				else if ( t == "SWP"){
					if (top < 2 ){
						isError = true;
						break;
					}
					
					int a = arr[--top];
					int b = arr[--top];
					arr[top++]=a;
					arr[top++]=b;
					
				}
				
				else if (t == "ADD"){
					if (top<2){
						isError = true;
						break;
					}
					
					int a = arr[--top];
					int b = arr[--top];
					if ( (a+b)>1000000000 || (a+b)< ((-1)*1000000000)){
						isError = true;
						break;
					}
					else{
						arr[top++]=a+b;
					}
				}
				
				else if (t == "SUB"){
					if (top<2){
						isError = true;
						break;
					}
					
					int a = arr[--top];
					int b = arr[--top];
					if ( (b-a)>1000000000 || (b-a)< ((-1)*1000000000)){
						isError = true;
						break;
					}
					arr[top++]=b-a;
					
				}
				
				else if (t == "MUL"){
					if (top<2){
					
						isError = true;
						break;
					}
					
					long long a = arr[--top];
					long long b = arr[--top];
					if (a*b>1000000000 || a*b < ((-1)*1000000000)){
						isError = true;
						break;
					}
					else{
						arr[top++]=a*b;
					}
				}
				
				else if ( t== "DIV"){
					
					if (top<2){
						isError = true;
						break;
					}
					
					int a = arr[--top];
					int b = arr[--top];
					
					if (a==0){
						isError = true;
						break;
					}
					
					if (a<0 && b>0){
						int c = (-1)*a;
						arr[top++]=(-1)*(b/c);
					}
					
					else if (a>0 && b<0){
						int c = (-1)*b;
						arr[top++]=(-1)*(c/a);
					}
					
					else if (a<0 && b<0){
						int c = (-1)*a;
						int d = (-1)*b;
						arr[top++]=(d/c);
					}
					
					else {
						arr[top++]=b/a;
					}
					
					
				}
				
				else if ( t== "MOD"){
					
					if (top<2){
						isError = true;
						break;
					}
					
					int a = arr[--top];
					int b = arr[--top];
					
					if (a==0){
						isError = true;
						break;
					}
					
	
					if (a<0 && b>0){
						int c = (-1)*a;
						arr[top++]=(b%c);
					}
					
					else if (a>0 && b<0){
						int c = (-1)*b;
						arr[top++]=(-1)*(c%a);
					}
					
					else if (a<0 && b<0){
						int c = (-1)*a;
						int d = (-1)*b;
						arr[top++]=(-1)*(d%c);
					}
					else{
						arr[top++]=b%a;
					}
					
				}
				/*
				int temp = top;
				while (temp > 0){
					cout << arr[--temp] << " ";
				}
				
				cout << "\n\n";
				*/
			}
			
			if (isError==true || top != 1){
				cout << "ERROR" << "\n";
			}
			else{
				cout << arr[0] << "\n";
			}
			
		}
		cout << "\n";
		
		
	}
	
	return 0;
	
	
}