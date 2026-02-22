class Solution {
public:
    bool isvowel(char c){
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(!isvowel(s[l])) l++;
            else if(!isvowel(s[r])) r--;
            else{
                swap(s[l],s[r]);l++;r--;
            }
        }
        return s;
    }
};