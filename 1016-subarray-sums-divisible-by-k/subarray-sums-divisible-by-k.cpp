#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        
        // Map to store remainder frequencies (remainder -> count)
        unordered_map<int, int> remainderCount;
        
        // Base case: A prefix sum of 0 has a remainder of 0 once
        remainderCount[0] = 1;
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Calculate remainder with k
            int remainder = prefixSum % k;
            
            // Handle negative remainders in C++ / Java
            if (remainder < 0) {
                remainder += k;
            }
            
            // If this remainder has been seen before, add its frequency to total count
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            
            // Increment frequency of current remainder
            remainderCount[remainder]++;
        }
        
        return count;
    }
};