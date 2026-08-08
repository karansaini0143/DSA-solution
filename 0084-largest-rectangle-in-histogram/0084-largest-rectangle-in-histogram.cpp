class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> prev(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) prev[i]=-1;
            else prev[i]=st.top();
            st.push(i);
        }
        stack<int> sc;
        vector<int> nxt(n);
        for(int i=n-1;i>=0;i--){
            while(!sc.empty() && heights[sc.top()]>=heights[i]){
                sc.pop();
            }
            if(sc.empty()) nxt[i]=n;
            else nxt[i]=sc.top();
            sc.push(i);
        }
        long long sum=0;

        for(int i=0;i<n;i++){
            
            int l=nxt[i]-prev[i]-1;
            int b=heights[i];
            sum=max(sum,l*b*1LL);
        }
        return sum;
    }
};