class Solution {
public:
    vector<vector<int>> dp;

    bool recursiveRelation(int index1,int index2,string s,string p){
        if(index1>=s.size() && index2>=p.size()) return true;
        else if(index2>=p.size()) return false;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        bool ans=false;
        if(index2+1<p.size() && p[index2+1]=='*'){
            ans=ans ||
            recursiveRelation(index1,index2+2,s,p);

            if(index1 < s.size() &&
            (s[index1] == p[index2] || p[index2] == '.')) ans=ans||recursiveRelation(index1+1,index2,s,p);
        }
        if(index1<s.size() && (s[index1]==p[index2] || p[index2]=='.')){
            ans=ans|| recursiveRelation(index1+1,index2+1,s,p);
        }
        return dp[index1][index2]=ans;
    }
    bool isMatch(string s, string p) {
        // int index1=0;
        // int index2=0;

        // return recursiveRelation(index1,index2,s,p);

        //memoization
        int n=s.size();
        int m=p.size();
        // dp.resize(n+1,vector<int>(m+1,-1));

        // return recursiveRelation(0,0,s,p);

        //tabulation
        dp.resize(n+1,vector<int>(m+1,0));

        dp[0][0]=1;

        for(int j=2;j<=m;j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i][j] || dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(j>=2) dp[i][j]=dp[i][j] || dp[i][j-2];
                    if(j>=2 && s[i-1] == p[j-2] || p[j-2] == '.') dp[i][j]=dp[i][j] || dp[i-1][j];
               }
            }
        }

        return dp[n][m];
    }
};
