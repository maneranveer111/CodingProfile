#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp;
int nb, ns, nc;
int pb, ps, pc;
    
bool helper(long long mid, long long r) {
    long long reqB = mp['B'] * mid;
    long long reqS = mp['S'] * mid;
    long long reqC = mp['C'] * mid;
    
    if(nb < reqB) {
        long long need = reqB - nb;
        if(need * pb > r)
            return false;
        r -= need * pb;
    }
    
    if(ns < reqS) {
        long long need = reqS - ns;
        if(need * ps > r)
            return false;
        r -= need * ps;
    }
    
    if(nc < reqC) {
        long long need = reqC - nc;
        if(need * pc > r)
            return false;
        r -= need * pc;
    }
    
    return true;
}

int main(){
    string s;
    cin >> s;
    
    cin >> nb >> ns >> nc;
    
    cin >> pb >> ps >> pc;
    
    long long r;
    cin >> r;
    
    for(char ch : s)
        mp[ch]++;
    
    long long lo = 0, hi = 1000000000100LL;
    long long ans = 0;
    
    while(lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        
        if(helper(mid, r)) {
            ans = mid;
            lo = mid + 1;
        }
        else 
            hi = mid - 1;
    }
    
    cout << ans << endl;
}