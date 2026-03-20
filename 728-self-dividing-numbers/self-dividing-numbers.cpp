class Solution {
public:
    bool perfect(int n){
        int temp=n;
        bool flag=false;
        while(temp>0){
            int i=temp%10;
            if(i==0){
                flag=false;break;
            }
            else if(n%i==0) flag=true;
            else {
                flag=false;
                break;
            }
            temp/=10;
        }
        if(flag) return true;
        return false;
        
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(perfect(i)) ans.push_back(i);
        }
        return ans;
    }
};