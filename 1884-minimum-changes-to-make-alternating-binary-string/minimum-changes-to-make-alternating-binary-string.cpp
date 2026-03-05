class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string a;
        string b;
        for(int i=0;i<n;i++){
            if(i%2==0){
               a+='0';
               b+='1';
            }
            else{
                a+='1';
                b+='0';
            }
        }    
        int cnt=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i]!=s[i]) cnt++;
            if(b[i]!=s[i]) count++;
        }

        return min(cnt,count);
    }
};