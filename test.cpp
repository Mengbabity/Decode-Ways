class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0')
            return 0;
        if(n==1 && s[0]!='0')
            return 1;
        vector<int> tmp(n+1,0);
        tmp[0]=1;
        tmp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int first=stoi(s.substr(i-1,1));
            int second=stoi(s.substr(i-2,2));
            
            if(first!=0)
                tmp[i]+=tmp[i-1];
            
            if(second>=10 && second<=26)
                tmp[i]+=tmp[i-2];
        }
        
        return tmp[n];
    }
};
