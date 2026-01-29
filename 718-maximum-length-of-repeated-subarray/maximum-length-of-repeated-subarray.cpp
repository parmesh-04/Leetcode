class Solution {
public:
     void shift(vector<int>& nums1, vector<int>& nums2,int s1,int s2,int len, int& ans){
        int s=0;
        for(int i=0;i<len;i++){
            if(nums1[s1+i]==nums2[s2+i]){
                s++;
                if(s>ans){
                    ans=s;
                }
            }else{
                    s=0;
                }
        }
     }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int t=min(n-i,m);
            shift(nums1,nums2,i,0,t,ans);
        }

        for(int j=0;j<m;j++){
            int t=min(n,m-j);
            shift(nums1,nums2,0,j,t,ans);
        }
        return ans;
    }
};