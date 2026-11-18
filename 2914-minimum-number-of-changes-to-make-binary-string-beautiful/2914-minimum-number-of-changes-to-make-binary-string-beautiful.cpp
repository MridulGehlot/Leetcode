class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        char prev='\0';
        int len=0;
        for(char ch:s)
        {
            if(ch!=prev)
            {
                if(len%2) 
                {
                    prev='\0';
                    len=0;
                    ++ans;
                    continue;
                }
                len=0;
            }
            prev=ch;
            ++len;
        }
        return ans;
    }
};