class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        // Kadane's Algorithm 

        int max_end = 0, max_sum = INT_MIN; 
        int min_end = 0, min_sum = INT_MAX;

        for(int x: nums)
        {
            max_end = max(x, max_end + x);
            max_sum = max(max_sum, max_end);

            min_end = min(x, min_end + x);
            min_sum = min(min_sum, min_end);
        }
        // Absolute value for max_sum and min_sum.
        return max(abs(max_sum), abs(min_sum));
    }
};