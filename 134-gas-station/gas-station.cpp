class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg=0;
        int sc=0;
        for(int i=0;i<gas.size();i++){
            sg+=gas[i];
            sc+=cost[i];
        }

        if(sg<sc){
            return -1;
        }

        int cnt=0;
        int start=0;

        for(int i=0;i<gas.size();i++){
            cnt+=gas[i]-cost[i];
            if(cnt<0){
                cnt=0;
                start=i+1;
            }
        }
        return start;
    }
};