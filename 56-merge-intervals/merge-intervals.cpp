class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        int i = 0;
        int n = intervals.size();

        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            while (i < n - 1 && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            res.push_back({start, end});

            i++;
        }

        return res;
    }
};