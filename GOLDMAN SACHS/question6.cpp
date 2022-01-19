class Solution {
public:
    string res="";
    int f=1;
    void gcd(string str1,string str2,int idx1,int idx2)
    {
        if(idx1==str1.length()||idx2==str2.length())
        {
            if(idx1==str1.length() and idx2==str2.length())
            {
                f=0;
                res=str1;
            }
            else if(idx1!=str1.length())
                res=str1.substr(idx1);
            else
                res=str2.substr(idx2);
            return;
        }
        if(str1[idx1]!=str2[idx2])
        {
            res="";
            return;
        }
        else if(str1[idx1]==str2[idx2])
        {
            gcd(str1,str2,idx1+1,idx2+1);
        }
    }
    string gcdOfStrings(string str1, string str2) {
        while(str1[0]==str2[0] and f)
        {
            gcd(str1,str2,0,0);
            if(str1.length()>str2.length())
            {
                str1=str2;
                str2=res;
            }
            else{
                str2=res;
            }
        }
        if(str1[0]!=str2[0])
            res="";
        return res;
    }
};