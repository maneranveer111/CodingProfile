class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;

        vector<long long> prefix(2 * n + 1, 0);
        for(int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + nums[i % n];
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            long long firstHalf = prefix[i + m] - prefix[i];
            long long secondHalf = prefix[i + n] - prefix[i + m];

            if(firstHalf > secondHalf)
                ans++;
        }

        return ans;
    }
};