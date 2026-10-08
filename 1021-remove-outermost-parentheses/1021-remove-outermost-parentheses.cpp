class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt,start;
        cnt=0;
        start=0;
        string ans="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(') ++cnt;
            else --cnt;
            if(cnt==0)
            {
                if((start+1)<(i-1)) ans+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return ans;
    }
};