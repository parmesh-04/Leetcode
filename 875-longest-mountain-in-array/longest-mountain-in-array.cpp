class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3){
            return 0;
        }
        int cnt=0;

        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int l=i-1;
                int r=i+1;
                while(l>0 && arr[l]>arr[l-1] ){
                    l--;
                }

                while(r<arr.size()-1 && arr[r]>arr[r+1]){
                    r++;
                }
                cnt=max(cnt,r-l+1);
                i=r;
            }
        }
        return cnt;
    }
};