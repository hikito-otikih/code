#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int a[200005];
        memset(a, -1, sizeof a);
        a[100000] = 0;
        int cnt = 0, ans = 0;
        for (int i = 1; i <= (int) nums.size(); i ++)
        {
            if (nums[i - 1] == 0) cnt --;
            else cnt ++;
            if (a[cnt + 100000] != -1) ans = max(ans, i - a[cnt + 100000]);
            a[cnt + 100000] = i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 1};
    cout << s.findMaxLength(nums) << endl;
    return 0;
}