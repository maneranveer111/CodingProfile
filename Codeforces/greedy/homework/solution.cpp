#include <bits/stdc++.h>
using namespace std;
   

int main() {
	// your code goes here
	unordered_set<char> mp;
	vector<pair<int, int>> freq(26);
	
	string s;
	cin >> s;
    int k;
    cin >> k;
    
    for(char ch : s) {
        freq[ch - 'a'].second++;
        freq[ch - 'a'].first = ch - 'a';
    }
    
    sort(freq.begin(), freq.end(), [](auto a, auto b) {
        return a.second < b.second;
    });
    
    for(int i = 0; i < 26; i++) {
        if(k <= 0)
            break;
        
        if(freq[i].second <= k) {
            k -= freq[i].second;
            freq[i].second = 0;
        }
        else {
            k = 0;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(freq[i].second > 0) {
            mp.insert('a' + freq[i].first);
        }
    }
    
    string ans = "";
    for(char ch : s) {
        if(mp.count(ch)) {
            ans.push_back(ch);
        }
    }
    cout << mp.size() << endl;
    cout << ans << endl;
    
    return 0;
}