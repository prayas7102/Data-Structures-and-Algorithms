class Solution {
    void solve (vector<string> &s, int open, int close, string &st){
        if(open==0 && close==0){
            s.push_back(st);
            return;
        }
        if(open>0){
            st.push_back('(');
            solve(s,open-1,close,st);
            st.pop_back();
        }
        if(close>0 && open<close){
            st.push_back(')');
            solve(s,open,close-1,st);
            st.pop_back();
        } 
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string st;
        solve(s,n,n,st);
        return s;
    }
};