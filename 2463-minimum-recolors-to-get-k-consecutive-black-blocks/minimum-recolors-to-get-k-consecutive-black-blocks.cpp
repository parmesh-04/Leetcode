class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0;
        int right=k-1;
        int cnt=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                cnt++;
               
            }
        }
    int ans=cnt;
      
        while(right<blocks.size()-1){
            if(blocks[left]=='W'){
                cnt--;
            }
            left++;
           
                right++;
                if(blocks[right]=='W'){
                    cnt++;
                }
            
            
            ans=min(ans,cnt);

        }
        return ans;
    }
};