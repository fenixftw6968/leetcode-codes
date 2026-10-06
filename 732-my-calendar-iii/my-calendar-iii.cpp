class MyCalendarThree {
public:
    map<int,int> mpp;
    int ans=0;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int active=0;
        ans=0;
        for(auto it : mpp){
            active+=it.second;
            ans=max(ans,active);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */