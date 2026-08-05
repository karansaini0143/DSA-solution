class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<long long> st;
        stack<long long> sc;

        int n=nums.size();
        vector<long long> ngrt(n);
        vector<long long> pgrt(n);
        vector<long long> nlss(n);
        vector<long long> plss(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            while(!sc.empty() && nums[sc.top()]>=nums[i]){
                sc.pop();
            }
            if(sc.empty()) plss[i]=-1;
            else plss[i]=sc.top();
            if(st.empty()) pgrt[i]=-1;
            else pgrt[i]=st.top();

            st.push(i);
            sc.push(i);
        }
        while(!st.empty()) st.pop();
        while(!sc.empty()) sc.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            while(!sc.empty() && nums[sc.top()]>nums[i]){
                sc.pop();
            }
            if(sc.empty()) nlss[i]=n;
            else nlss[i]=sc.top();
            if(st.empty()) ngrt[i]=n;
            else ngrt[i]=st.top();

            st.push(i);
            sc.push(i);
        }
        long long sum=0;
        long long high;
        long long low;
        for(int i=0;i<n;i++){
            high=nums[i]*(ngrt[i]-i)*(i-pgrt[i]);
            low=nums[i]*(nlss[i]-i)*(i-plss[i]);
            sum+=high-low;
        }
        return sum;
    }
};