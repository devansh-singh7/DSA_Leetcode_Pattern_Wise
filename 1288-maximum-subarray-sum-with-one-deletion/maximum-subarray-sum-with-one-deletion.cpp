class Solution {
public:
    int maximumSum(vector<int>& arr) {

        // Med - Hard Question

        int n = arr.size();
        int one_del = 0;      // Max sum ending at i with 1 deletion.
        int no_del = arr[0];  // Max sum ending at i with 0 deletion.

        int res = arr[0];

        for(int i=1; i<n; i++)
        {
            // Either delete current element (take prev_no_del)
            // OR keep current element and append to a prevoiusly deleted subarray (one_del + arr[i]).

            one_del = max(no_del, one_del + arr[i]);

            // Standard Kadane's Algorithm for 0 deletions.
            no_del = max(arr[i], no_del + arr[i]);
            
            // Track global max
            res = max({res, no_del, one_del});
        }

        return res;
    }
};