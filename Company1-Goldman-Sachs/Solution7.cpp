// Problem: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

vector<int> findTwoElement(vector<int> arr, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int rpt = 0, mis = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > 1)
            rpt = arr[i];
        if (mp.find(i + 1) == mp.end())
            mis = i + 1;
    }

    return {rpt, mis};
}