class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool isPresent0=false;
        bool isPresent1=false;
        bool isPresent2=false;
        int t0=target[0];
        int t1=target[1];
        int t2=target[2];
        
        for(int i=0;i<triplets.size();i++){
            int curr1=triplets[i][0];
            int curr2=triplets[i][1];
            int curr3=triplets[i][2];

            if(t0<curr1 || t1<curr2 || t2<curr3) continue;
            
            if(curr1==t0) isPresent0=true;
            if(curr2==t1) isPresent1=true;
            if(curr3==t2) isPresent2=true;
        }

        return isPresent0 && isPresent1 && isPresent2;
    }
};
