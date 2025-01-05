#include <bits/stdc++.h>



using namespace std;
string s;
int dp[5001]; // dp[i] : 1~i th pass

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	
	
	dp[0]=1;
	if (s[0]=='0'){
		dp[1]=0;
	}
	else{
		dp[1]=1;
	}
	
	for (int i=2; i<=s.size(); i++){
		
		if (s[i-1]=='0'){
			if (s[i-2]=='0'){
				dp[i]=0;
			}
			
			else if (s[i-2]=='1' || s[i-2]=='2'){
				dp[i]=dp[i-2];
			}
			else{
				dp[i]=0;
			}
		}
		
		
		else if (s[i-2]=='1'){
			if (0< s[i-1]-'0' && s[i-1]-'0'<=9){
				dp[i]=(dp[i-1]%1000000+dp[i-2]%1000000)%1000000;
			}
			else{
				dp[i]=dp[i-1];
			}
		}
		
		else if (s[i-2]=='2'){
			if (0< s[i-1]-'0' && s[i-1]-'0'<=6){
				dp[i]=(dp[i-1]%1000000+dp[i-2]%1000000)%1000000;
			}
			else{
				dp[i]=dp[i-1];
			}
		}
		
		
		else{
			dp[i]=dp[i-1];
		}
	}
	
	cout << dp[s.size()];
	return 0;
}
