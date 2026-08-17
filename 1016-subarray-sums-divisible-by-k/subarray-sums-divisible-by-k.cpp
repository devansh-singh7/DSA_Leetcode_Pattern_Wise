class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> f;
        f[0] = 1;  // Initially sum = 0, So hasmap have a value of 0 -> 1. 
        // Like zero is present their.

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            
            // Handle negative remainders
            if(rem < 0) {
                rem = rem + k;
            }
            
            ans += f[rem];
            f[rem]++;
        }
        
        return ans;
    }
};
