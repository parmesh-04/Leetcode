class Solution {
public:
    multiset<long long> l,h;
    long long s=0;
    int cnt;

    void add(long long val){
        l.insert(val);
        s+=val;
        if(l.size()>cnt){
          long long t=*l.rbegin();
          s-=t;
          l.erase(prev(l.end()));
          h.insert(t);
        }
    }

    void remove(long long val){
        auto it=h.find(val);
        if(it!=h.end()){
            h.erase(it);
        }else{
            it=l.find(val);
            if(it!=l.end()){
                s-=*it;
                l.erase(it);
            }
        }

        if(l.size()<cnt && !h.empty()){
            long long t=*h.begin();
            h.erase(h.begin());
            l.insert(t);
            s+=t;
        }
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
       int n=nums.size();
       cnt=k-2;
       long long ans=LLONG_MAX;
       long long cost=0;
       for(int i=2;i<=dist+1 && i<n;i++){
         add(nums[i]);
       }

       for(int i=1;i<n;i++){
         if(l.size()+h.size()>=cnt){
            cost=nums[0]+nums[i]+s;
            if(ans>cost){
                ans=cost;
            }
         }
         
       if(i+1<n) remove(nums[i+1]);
       if(i+dist+1<n) add(nums[i+dist+1]);
       }

    return ans;

    }
};