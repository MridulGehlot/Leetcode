class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        int maxi=INT_MIN;
        int start,end,s,e,sum,a,b;
        for(int i=0;i<n-firstLen+1;i++)
        {
            start=i;
            end=i+firstLen-1;
            for(int j=0;j<n-secondLen+1;++j)
            {
                s=j;
                e=j+secondLen-1;
                if((s>=start && s<=end) || (e>=start && e<=end)) continue;
                if((start>=s && start<=e) || (end>=s && end<=e)) continue;
                a=prefix[end]-(start>0?prefix[start-1]:0);
                b=prefix[e]-(s>0?prefix[s-1]:0);
                sum=a+b;
                //cout<<start<<","<<end<<":"<<s<<","<<e<<":"<<sum<<"::"<<a<<","<<b<<endl;
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};