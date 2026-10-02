class Solution {
public:
    void generate(int &n,vector<string> &ans,string s,int open,int close)
    {
        if(s.size()==(2*n))
        {
            ans.push_back(s);
            return;
        }
        if(close<open) generate(n,ans,s+')',open,close+1);
        if(open<n) generate(n,ans,s+'(',open+1,close);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n,ans,"",0,0);
        return ans;
    }
};