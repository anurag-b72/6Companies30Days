class Solution
{
public:
    int rev(long long int n)
    {
        int reversed_number = 0, remainder;
        while (n != 0)
        {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        return reversed_number;
    }

    int countNicePairs(vector<int> &nums)
    {        
        int n=nums.size();
        const unsigned int M = 1000000007;
        unordered_map<int, int> m;
        long long int ans = 0;
        for (int i = 0;i < n; i++){
            int b = nums[i] - rev(nums[i]);
            if (m[b]){
                ans += m[b];
            }            
             m[b]++;
        }
        
        return ans%M;
    }
};