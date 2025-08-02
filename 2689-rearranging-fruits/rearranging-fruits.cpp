class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> cnt;
         int min_val = INT_MAX;
         unordered_map<int,int> b1;
        for(int i=0;i<basket1.size();i++){
            cnt[basket1[i]]++;
            b1[basket1[i]]++;
            min_val=min(min_val,basket1[i]);
        }
         for(int i=0;i<basket2.size();i++){
            cnt[basket2[i]]++;
            min_val=min(min_val,basket2[i]);
        }

        vector<int> extra;
        for(auto& [ele,count] : cnt){
            if(count%2!=0){
                return -1;
            }

            int diff=b1[ele]-count/2;
            for(int i=0;i<abs(diff);i++){
                extra.push_back(ele);
            }
           
        }

        long long cost=0;
        sort(extra.begin(),extra.end());
        for(int i=0;i<extra.size()/2;i++){
           long long ds=extra[i];
           long long is=2*min_val;
           cost+=min(ds,is); 
        }
    return cost;

    }
};