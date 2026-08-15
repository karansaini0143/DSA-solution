class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row=matrix.size();
        int column=matrix[0].size();

        vector<int> vcc(column);
        vector<int> nxt(column);
        vector<int> prev(column);

        long long ans=0;
        for(int i=0;i<row;i++){
            stack<int> st;
            for(int j=0;j<column;j++){
                if(matrix[i][j]=='1') vcc[j]++;
                else vcc[j]=0;
                
                while(!st.empty() && vcc[st.top()]>=vcc[j])
                    st.pop();
                if(st.empty())  prev[j]=-1;
                else    prev[j]=st.top();

                st.push(j);
            }
            while(!st.empty()) st.pop();
            for(int j=column-1;j>=0;j--){
                while(!st.empty() && vcc[st.top()]>vcc[j])
                    st.pop();
                if(st.empty())  nxt[j]=column;
                else    nxt[j]=st.top();

                st.push(j);
            }
            
            for(int j=0;j<column;j++){
                int b=nxt[j]-prev[j]-1;
                ans=max(ans,1LL*b*vcc[j]);
            }
            
        }
        return ans;
    }
};