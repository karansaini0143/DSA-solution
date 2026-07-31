class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        int j = 0, maxi = nums[0];
        for (int i = 1; i < n; i++) {
            if (maxi < nums[i]) { 
                maxi = nums[i]; j = i;
            }
        }
        ans[j] = -1;
        st.push(maxi);

        int k = j;
        for (int cnt = 0; cnt < n - 1; cnt++) {
            k = (k == 0) ? n - 1 : k - 1;
            while (!st.empty() && st.top() <= nums[k]) st.pop();
            ans[k] = st.empty() ? -1 : st.top();
            st.push(nums[k]);
        }
        return ans;
    }
};