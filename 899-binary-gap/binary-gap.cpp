class Solution {
public:
    int binaryGap(int n) {
       string bin="";
        while(n>0){
        int rem=n%2;
        bin+=to_string(rem);
        n/=2;
       } 
       reverse(bin.begin(),bin.end());
       int last=-1;
       int maxi=0;
       for(int i=0;i<bin.size();i++){
            if(bin[i]=='1'){
                if(last!=-1){
                    maxi=max(maxi,i-last);
                }
                last=i;
            }
       }
       return maxi;
    }
};