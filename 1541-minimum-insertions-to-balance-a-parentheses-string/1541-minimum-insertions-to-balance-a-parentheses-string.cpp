class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int ans=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                stk.push('(');
            }
            else
            {
                if(stk.empty())
                {
                    ans+=1;
                }
                else stk.pop();
                if(i+1<s.size()) //perform look ahead
                {
                    if(s[i+1]==')') ++i;
                    else ans+=1;
                }
                else ans+=1;
            }
        }
        if(!stk.empty()) ans+=2*stk.size();
        return ans;
    }
};