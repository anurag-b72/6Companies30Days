// Problem: https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            vector<pair<string, int>> numsTrim(nums.size());

            for (int j = 0; j < nums.size(); j++)
            {
                numsTrim[j].first = nums[j].substr(nums[j].size() - queries[i][1], queries[i][1]);
                numsTrim[j].second = j;
            }

            sort(numsTrim.begin(), numsTrim.end());
            ans.push_back(numsTrim[queries[i][0] - 1].second);
        }
        return ans;
    }
};