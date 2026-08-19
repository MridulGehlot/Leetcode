class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int curr,count;
        curr=-1;
        count=0;
        bool left,right,midleft,midright;
        int ans=0;
        left=false;
        right=false;
        midleft=false;
        midright=false;
        for(auto &p:reservedSeats)
        {
            if(p[0]!=curr)
            {
                curr=p[0];
                ++count;
                //now assign values
                if(left && right && midleft && midright) ans+=2;
                else if(left && midleft) ans+=1;
                else if(right && midright) ans+=1;
                else if(midleft && midright) ans+=1;
                left=true;
                right=true;
                midleft=true;
                midright=true;
                //cout<<curr<<","<<ans<<endl;
            }
            if(p[1]==2 || p[1]==3) left=false;
            if(p[1]==4 || p[1]==5) midleft=false;
            if(p[1]==6 || p[1]==7) midright=false;
            if(p[1]==8 || p[1]==9) right=false;
        }
        if(left && right && midleft && midright) ans+=2;
        else if(left && midleft) ans+=1;
        else if(right && midright) ans+=1;
        else if(midleft && midright) ans+=1;
        return (n-count)*2+ans;
    }
};