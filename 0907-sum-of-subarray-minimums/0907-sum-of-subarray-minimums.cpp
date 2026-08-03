class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        vector<int> prev(arr.size()),nxt(arr.size());

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            prev[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            nxt[i]=st.empty()?arr.size():st.top();

            st.push(i);
        }
        long long sum=0;
        int MOD=1e9+7;
        for(int i=0;i<arr.size();i++){
            int left=i-prev[i];
            int right=nxt[i]-i;
            sum=(sum+((left*arr[i]*1LL)%MOD*right)%MOD)%MOD;
        }
        return sum;
    }
};