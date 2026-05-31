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
        dp.resize(n+1,vector<int>(m+1,-1));

        return recursiveRelation(0,0,s,p);
    }
};
