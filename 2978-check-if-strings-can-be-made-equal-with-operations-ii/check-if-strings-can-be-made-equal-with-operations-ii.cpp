class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string even,even1,odd,odd1;
        bool flag2=false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) flag2=true;
            else{
                flag2=false;
                break;
            }
        }
        if(flag2) return true;
        for(int i=0;i<s1.size();i++){
            if(i%2==0) {
                even.push_back(s1[i]);
                even1.push_back(s2[i]);
            }
            else{
                odd.push_back(s1[i]);
                odd1.push_back(s2[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(even1.begin(),even1.end());
        sort(odd.begin(),odd.end());
        sort(odd1.begin(),odd1.end());
        bool flag=false;
        for(int i=0;i<even.size();i++){
            if(even[i]==even1[i]) flag=true;
            else{
                flag=false;
                break;
            }
        }
        bool flag1=false;
        for(int i=0;i<odd.size();i++){
            if(odd[i]==odd1[i]) flag1=true;
            else{
                flag1=false;
                break;
            }
        }
        if(flag && flag1) return true;
        return false;

    }
};