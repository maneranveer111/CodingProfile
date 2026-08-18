#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; 
	cin >> n;
	
	const int MAX_VAL = 100000;
    vector<long long> sum_(MAX_VAL + 1, 0);
        
	for(int i = 0; i < n; i++) {
	    int x;
	    cin >> x;
	    sum_[x] += x;
	}
	
	vector<long long> dp(MAX_VAL + 1, 0);  
	dp[0] = 0;
	dp[1] = sum_[1];
	
	for(int i = 2; i < (int)dp.size(); i++) {
	    dp[i] = max(dp[i - 1], (dp[i - 2] + sum_[i]));
	}
        
    cout << dp[MAX_VAL] << endl;
    
    return 0;
}