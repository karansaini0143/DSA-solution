class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        if(k>=n){
            return "0";
        }
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 &&(st.top()-'0')>(num[i]-'0')){
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