class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int p,ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(i==j) continue;
                p=(s[i]-'0')*(s[j]-'0');
                ans=max(ans,p);
            }
        }
        return ans;
    }
};