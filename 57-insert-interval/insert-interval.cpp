class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedIntervals;
        bool inserted = false;

        // Step 1: Insert newInterval into its correct sorted position
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && intervals[i][0] >= newInterval[0]) {
                updatedIntervals.push_back(newInterval);
                inserted = true;
            }
            updatedIntervals.push_back(intervals[i]);
        }

        // Handle edge case: if newInterval belongs at the very end (or intervals was empty)
        if (!inserted) {
            updatedIntervals.push_back(newInterval);
        }

        // Step 2: Merge overlapping intervals (standard Merge Intervals logic)
        vector<vector<int>> res;
        res.push_back(updatedIntervals[0]);

        for (int i = 1; i < updatedIntervals.size(); i++) {
            // Compare current interval's start with previous interval's end
            if (updatedIntervals[i][0] <= res.back()[1]) {
                // Overlap found: merge by updating the end boundary
                res.back()[1] = max(res.back()[1], updatedIntervals[i][1]);
            } else {
                // No overlap: add as a separate interval
                res.push_back(updatedIntervals[i]);
            }
        }

        return res;
    }
};