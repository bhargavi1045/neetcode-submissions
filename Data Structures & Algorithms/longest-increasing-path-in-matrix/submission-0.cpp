class Solution {
public:
    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j){
        if(dp[i][j]) return dp[i][j];
        dp[i][j]=1;

        int drow[4]={0,0,1,-1};
        int dcol[4]={1,-1,0,0};

        for(int k=0;k<4;k++){
            int ni=i+drow[k];
            int nj=j+dcol[k];

            if(ni>=0 && ni<matrix.size() && nj>=0 && nj<matrix[0].size() && matrix[ni][nj]>matrix[i][j]){
                dp[i][j]=max(dp[i][j],dfs(matrix,dp,ni,nj)+1);
            }
        }

        return dp[i][j];
    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m));

        int longestPath=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                longestPath=max(longestPath,dfs(matrix,dp,i,j));
            }
        }
        
        return longestPath;
    }
};
