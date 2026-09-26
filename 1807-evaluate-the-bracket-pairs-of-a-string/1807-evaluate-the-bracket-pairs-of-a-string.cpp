class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto &v:knowledge) mp[v[0]]=v[1];
        int idx,n,pos;
        idx=0;
        string ans="";
        n=s.size();
        while(idx<n)
        {
            if(s[idx]=='(')
            {
                ++idx;
                pos=idx;
                while(s[idx]!=')') ++idx;
                s[idx]='\0';
                string tmp(s.c_str()+pos);
                if(mp.count(tmp)) ans+=mp[tmp];
                else ans+='?';
            }
            else ans+=s[idx];
            ++idx;
        }
        return ans;
    }
};