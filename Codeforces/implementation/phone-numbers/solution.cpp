#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<string>& numbers) {
    int siz = numbers.size();
    // vector<int> ans;
    int girl = 0, taxi = 0, pizz = 0;
    
    for(int i = 0; i < siz; i++) {
        bool same = true, dec = true;
        char back = numbers[i][0];
        
        for(int j = 1; j < 8; j++) {
            
            if(!dec && !same)
                break;
                
            if(numbers[i][j] == '-')
                continue;
            if(back == numbers[i][j]) {
                dec = false;
            }
            else if(back > numbers[i][j]) {
                same = false;
            }
            
            if(back < numbers[i][j]) {
                same = false;
                dec = false;
            }
            
            back = numbers[i][j];
        }
        
        
        if(same) {
            taxi++;
            // cout << "taxi" << taxi << " " << i << endl;
        }
        else if(dec) {
            pizz++;
            // cout << "pizz" << pizz << " " << i << endl;
        }
        else
            girl++;
    }
    
    return {taxi, pizz, girl};
}    

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<string> names;
	vector<vector<int>> result;
	
	string ans = "";
	int cnt = INT_MIN;
	
    while(n--) {
        int siz;
        cin >> siz;
        string name;
        cin >> name;
        
        names.push_back(name);
        vector<string> numbers;
        
        for(int i = 0; i < siz; i++) {
            string num;
            cin >> num;
            numbers.push_back(num);
        }
        
        vector<int> help = helper(numbers);
        result.push_back(help);
    }
    
    
    for(int i = 0; i < result.size(); i++) {
        if(result[i][0] > cnt) {
            ans.clear();
            string tmp = " " + names[i];
            ans += tmp;
            cnt = result[i][0];
        }
        else if(result[i][0] == cnt) {
            string tmp = ", " + names[i]; 
            ans += tmp;  
        }
    }
    
    cout << "If you want to call a taxi, you should call:" << ans << "."<< endl;
    
    ans.clear();
    cnt = INT_MIN;
    
    for(int i = 0; i < result.size(); i++) {
        if(result[i][1] > cnt) {
            ans.clear();
            string tmp = " " + names[i];
            ans += tmp;
            cnt = result[i][1];
        }
        else if(result[i][1] == cnt) {
            string tmp = ", " + names[i]; 
            ans += tmp;   
        }
    }
    
    cout << "If you want to order a pizza, you should call:" << ans << "." << endl;
    
    ans.clear();
    cnt = INT_MIN;
    
    for(int i = 0; i < result.size(); i++) {
        if(result[i][2] > cnt) {
            ans.clear();
            string tmp = " " + names[i]; 
            ans += tmp;
            cnt = result[i][2];
        }
        else if(result[i][2] == cnt) {
            string tmp = ", " + names[i]; 
           ans += tmp;
        }
    }
    
    cout << "If you want to go to a cafe with a wonderful girl, you should call:" << ans << "." << endl;
    
    return 0;
}