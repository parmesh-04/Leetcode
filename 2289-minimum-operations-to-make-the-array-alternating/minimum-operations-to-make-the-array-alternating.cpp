class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
       unordered_map<int,int> even;
        unordered_map<int,int> odd;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                even[nums[i]]++;
            }else{
                odd[nums[i]]++;
            }
        }
    vector<pair<int,int>> e(even.size());
    vector<pair<int,int>> o(odd.size());
    for(auto& [val,freq]:even){
        e.push_back({freq,val});
    }

     for(auto& [val,freq]:odd){
        o.push_back({freq,val});
    }

    sort(e.begin(),e.end(),greater<pair<int,int>>());
    sort(o.begin(),o.end(),greater<pair<int,int>>());
    
    if(e.size()==1 && o.size()==1){
        return nums.size();
    } 

    int es=(nums.size()+1)/2;
    int os=(nums.size())/2;

    if(e.size()>1 && o.size()>1){
        if(e[0].second!=o[0].second){
            return es-e[0].first+os-o[0].first;
        }else{
            return min( es-e[1].first+os-o[0].first,es-e[0].first+os-o[1].first);
        }
    }else if(e.size()==1){
          if(e[0].second!=o[0].second){
            return es-e[0].first+os-o[0].first;
        }else{
            return min( es-e[0].first+os-o[1].first,es+os-o[0].first);
        }
    }else{
        if(e[0].second!=o[0].second){
            return es-e[0].first+os-o[0].first;
        }else{
            return min(es-e[1].first+os-o[0].first,es-e[1].first+os);
        }
    }

   




      
    }
};