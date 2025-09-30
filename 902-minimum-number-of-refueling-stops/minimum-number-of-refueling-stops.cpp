class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        if(stations.size()==0){
            if(startFuel<target){
                return -1;
            }else{
                return 0;
            }
        }
       
        if(startFuel<stations[0][0]){
            return -1;
        }
         int pos=stations[0][0];
         long long f=startFuel-stations[0][0];
        pq.push(stations[0][1]);
        int ans=0;

        for(int i=1;i<stations.size();i++){
           while(!pq.empty() && f<(stations[i][0]-pos)){
                    f+=pq.top();
                    ans++;
                    pq.pop();
                } 
            
            if(f<(stations[i][0]-pos)){
                return -1;
            }else{
                f=f-(stations[i][0]-pos);
                pos=stations[i][0];
                pq.push(stations[i][1]);  
            }  


        }

          while(!pq.empty() && f<(target-pos)){
                    f+=pq.top();
                    ans++;
                    pq.pop();
                } 

            if(f<(target-pos)){
                return -1;
            }else{
               return ans;
            }  
    }
};