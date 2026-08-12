class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> f;

        // Base Case: A prefix sum of 0 has occurred once (represents an empty prefix).
        // This allows us to count valid subarrays that start directly at index 0.
        f[0] = 1; 
        int res = 0;

        for(int i=0; i<n; i++)
        {
            sum += nums[i];

            // We want to find a previous prefix sum 'ques' such that:
            // current_sum - ques = k  ==>  ques = current_sum - k
            int ques = (sum - k);

            // We want to find a previous prefix sum 'ques' such that:
            // current_sum - ques = k  ==>  ques = current_sum - k
            int freq = f[ques];

            res += freq; // Add the number of valid subarrays ending at index i to the total
            f[sum]++; // Record the current prefix sum into the frequency map
        }
        return res;
    }
};