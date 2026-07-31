class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans,last;
        last=0;
        ans=0;
        for(int i=0;i<s.size();++i)
        {
            if(mp.count(s[i]))
            {
                //cout<<"i = "<<i<<", last="<<last<<" ans="<<ans<<endl;
                ans=max(ans,i-last);
                last=max(mp[s[i]]+1,last);
            }
            mp[s[i]]=i;
        }
        ans=max(ans,(int)s.size()-last);
        //cout<<"i = "<<s.size()<<",  ="<<ans<<endl;
        return ans;
    }
};