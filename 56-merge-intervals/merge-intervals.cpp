class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) return {};
         
        // Sort the array according to the start value.
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;

        int start_1 = intervals[0][0];
        int end_1 = intervals[0][1];

        for(int i=1; i<intervals.size(); i++)
        {
            // comparing from this range.
            int start_2 = intervals[i][0];
            int end_2 = intervals[i][1];

            if(end_1 >= start_2)
            {
                start_1 = start_1; // New range Start.
                end_1 = max(end_1, end_2); // New range End
                continue;
            } else {
            res.push_back({start_1, end_1});
            start_1 = start_2;  //Updated the value Start.
            end_1 = end_2;  // Updated the value of End.
            }
        } 
         // In last one range can be left like [15, 18]. So, again push to result "res".
         res.push_back({start_1, end_1}); 
         return res;

    }
};