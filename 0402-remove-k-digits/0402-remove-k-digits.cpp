class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};