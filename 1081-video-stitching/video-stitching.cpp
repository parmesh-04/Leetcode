class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int cnt=0;
        int n=clips.size();
        int l=0;
        int r=0;
        int i=0;
        while(r<time){
           while(i<n && l>=clips[i][0]){
             r=max(r,clips[i][1]);
             i++;
           }

           cnt++;
           if(l==r) return -1;
           l=r;
           

        }
        return cnt;
    }
};