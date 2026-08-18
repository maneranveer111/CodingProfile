#include <bits/stdc++.h>
using namespace std;
// 0 for gym and 1 for contest;
vector<vector<int>> memo;

int helper(int day, int prev, vector<int>& info) {
    if(day >= info.size())
        return 0;
    if(memo[day][prev + 1] != -1)
        return memo[day][prev + 1];
    
    int a_day = info[day];
    int ans = INT_MAX;
    
    if(a_day == 0) {
        int temp = 1 + helper(day + 1, -1, info);    
        ans = min(ans, temp);
    }
    else if(a_day == 1) {
        if(prev == -1 || prev == 0) {
            int temp2 = helper(day + 1, 1, info);
            ans = min(ans, temp2);
        }
        
        int temp1 = 1 + helper(day + 1, -1, info);
        
        ans = min(ans, temp1);
    }
    else if(a_day == 2) {
        if(prev == -1 || prev == 1) {
            int temp1 = helper(day + 1, 0, info);
            ans = min(ans, temp1);
        }
        
        int temp2 = 1 + helper(day + 1, -1, info);
        ans = min(ans, temp2);
    }
    else {
        if(prev == -1 || prev == 0) {
            int temp1 = helper(day + 1, 1, info);
            ans = min(ans, temp1);
        }
        
        if(prev == -1 || prev == 1) {
            int temp2 = helper(day + 1, 0, info);
            ans = min(ans, temp2);
        }
        
        int temp3 = 1 + helper(day + 1, -1, info);
        
        ans = min(ans, temp3);
    }
    
    return memo[day][prev + 1] = ans;
}


int main() {
	// your code goes here
	int n;
	cin >> n;
	
	std::vector<int> info(n);
	
	for(int i = 0; i < n; i++) {
	    cin >> info[i];
	}
	memo.assign(n, vector<int>(3, -1));
	
	int ans = helper(0, -1, info);
	
	std::cout << ans << std::endl;

}