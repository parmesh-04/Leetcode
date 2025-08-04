class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int mx=0;
       
        mx=max(startPos+k,fruits.back()[0]);
        vector<int> prefix(mx+2,0);
        for (auto& fruit : fruits) {
            prefix[fruit[0]+1]+=fruit[1]; 
        }

         for (int i = 1; i < prefix.size(); i++) {
            prefix[i] += prefix[i - 1];
        }
        int ans=0;
         for (int stepsLeft = 0; stepsLeft <= k; ++stepsLeft) {
            int leftPos = startPos - stepsLeft;
            if (leftPos < 0) break;
            int rem = k - 2 * stepsLeft;
            if (rem < 0) break;
            int rightPos = startPos + rem;
            if (rightPos > mx) rightPos = mx;

            int total = prefix[rightPos + 1] - (leftPos >= 0 ? prefix[leftPos] : 0);
            ans = max(ans, total);
        }

          for (int stepsRight = 0; stepsRight <= k; ++stepsRight) {
            int rightPos = startPos + stepsRight;
            if (rightPos > mx ) break;
            int rem = k - 2 * stepsRight;
            if (rem < 0) break;
            int leftPos = startPos - rem;
            if (leftPos < 0) leftPos = 0;

            int total = prefix[rightPos + 1] - prefix[leftPos];
            ans = max(ans, total);
        }

    return ans;
    }
};