class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0;
        int res = 0;
        
        // Hash map stores (diff -> first_seen_index)
        // diff represents the difference between total 0s and total 1s so far (zero - one).
        unordered_map<int, int>f;

        for(int i=0; i<n; i++)
        {
            // Track total count of 0s and 1s up to the current index
            if(nums[i] == 0)
            {
                zero++;
            }
            else {
                one++;
            }

            int diff = zero - one;
            
            // Base case: If diff == 0, the subarray from index 0 to i has equal 0s and 1s.
            if(diff == 0)
            {
                res = max(res, i+1);
                continue;
            }

            // Key Logic: If the same 'diff' occurred at a previous index 'idx',
            // the subarray between 'idx + 1' and 'i' must have an equal number of 0s and 1s
            // (since the relative count of 0s vs 1s remained unchanged across this interval).
            
            // Only store the FIRST appearance of each diff value to maximize subarray length (i - idx)

            else if(f.find(diff) == f.end())
            {
                f[diff] = i;
            }
            else
            {   
                // If seen before, calculate the length of the balanced subarray and update max length
                int idx = f[diff];
                int len = i - idx;
                res = max(res, len);
            }
        }

        return res;
    }
};