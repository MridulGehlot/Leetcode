class Solution {
public:
    int day(string &s)
    {
        return stoi(s.substr(3,2));
    }
    int month(string &s)
    {
        return stoi(s.substr(0,2));
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int m,d,mend,dend;
        if(month(arriveAlice)>month(arriveBob))
        {
            m=month(arriveAlice);
            d=day(arriveAlice);
        }
            else if(month(arriveBob)>month(arriveAlice))
            {
                m=month(arriveBob);
                d=day(arriveBob);
            }
            else
            {
                m=month(arriveAlice);
                d=max(day(arriveAlice),day(arriveBob));
            }
        if(leaveAlice<=leaveBob) //Alice Leave Early
        {
            mend=month(leaveAlice);
            dend=day(leaveAlice);
        }
        else //Bob Leave Early
        {
            mend=month(leaveBob);
            dend=day(leaveBob);
        }
        cout<<d<<","<<m<<" : "<<dend<<","<<mend<<endl;
        int count=0;
        int curr=d;
        int i;
        for(i=m;i<mend;++i)
        {
            count+=days[i-1]-curr;
            curr=0;
            cout<<count<<endl;
        }
        if(i==mend && curr<=dend) count+=dend-curr+1;
        return count;
    }
};