class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> res;
        int i=0, j=0;
        
        while(i<firstList.size() && j<secondList.size())
        {
            int start_1 = firstList[i][0];
            int end_1 = firstList[i][1];

            int start_2 = secondList[j][0];
            int end_2 = secondList[j][1];
            
            // Find the boundary of the potential intersection
            
            int s = max(start_1, start_2);
            int e = min(end_1, end_2);

            // If they overlap, add it to the result
            if(s <= e)
            {
                res.push_back({s, e});
            }
            
            // Move the pointer that points to the interval ending earlier
            if(end_1 <= end_2)
            {
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};