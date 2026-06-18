class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> carAtt;
        int n=position.size();

        for(int i=0;i<n;i++){
            carAtt.push_back({position[i],speed[i]});
        }

        sort(carAtt.begin(),carAtt.end());

        double nextFleetTime=(double)(target-carAtt[n-1][0])/carAtt[n-1][1];
        int numberOfFleets=1;

        for(int i=n-2;i>=0;i--){
            double currentFleetTime=(double)(target-carAtt[i][0])/carAtt[i][1];

            if(currentFleetTime>nextFleetTime){
                nextFleetTime=currentFleetTime;
                numberOfFleets++;
            }
        }
        return numberOfFleets;
    }
};
