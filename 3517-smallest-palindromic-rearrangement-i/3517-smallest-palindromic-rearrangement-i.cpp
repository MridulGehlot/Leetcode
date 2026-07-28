class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26,0);
        for(char ch:s) arr[ch-'a']++;
        string ans="";
        char odd='9';
        for(int i=0;i<26;i++)
        {
            if(arr[i]%2) odd='a'+i;
            for(int j=0;j<arr[i]/2;++j)
            {
                ans+='a'+i;
            }
        }
        if(odd!='9') ans+=odd;
        for(int i=25;i>=0;i--)
        {
            for(int j=0;j<arr[i]/2;++j)
            {
                ans+='a'+i;
            }
        }
        return ans;
    }
};