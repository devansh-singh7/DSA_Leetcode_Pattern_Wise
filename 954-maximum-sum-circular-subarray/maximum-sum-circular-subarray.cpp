class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;
        int minEnding = 0, minSoFar = nums[0];
        int maxEnding = 0, maxSoFar = nums[0];

        for(int x: nums)
        {
            totalSum += x;  // Total Sum gets stored here
            
            // Standard Kadane's for Minimum Subarray
            minEnding = min(x, minEnding + x);
            minSoFar = min(minSoFar, minEnding);
            
            // Standard Kadane's for Maximum Subarray
            maxEnding = max(x, maxEnding + x);
            maxSoFar = max(maxEnding, maxSoFar);
        }

        // If all numbers are negative. So, max will be negaive too.
        // So, then return (totalSum - minSoFar).
        // Else we return just maxSoFar.

        if(maxSoFar < 0)
        {
            return maxSoFar;
        }
        // Compare standard maximum subarray sum vs circular wrapped sum
        return max(maxSoFar, totalSum - minSoFar);
    }
};