class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int sum = 0;
        
        // Calculate total sum of all elements in the vector.
        for(int i : nums){
            sum += i;
        }

        for(int i=0; i<n; i++)
        {
            // Add left only to avaoid reading nums[-1].
            if(i > 0){
            left += nums[i-1];
            }
            
            // Logic for 'right':
            // Total Sum = (left elements) + (current element nums[i]) + (right elements)
            // Rearranging gives: right = total sum - nums[i] - left

            int right = sum - nums[i] - left;

            if(left == right)
            {
                return i;
            }
        }
        return -1;
    }
};