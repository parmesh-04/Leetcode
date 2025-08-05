class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int ans =0;
    for (int i = 0;i<fruits.size();i++) {
        bool flag =false;
        for (int j = 0; j<baskets.size();j++) {
            if (baskets[j]>=fruits[i]) {
                baskets[j]=-1;
                flag= true;
                break;
            }
        }
        if (!flag) ans++;
    }
    return ans;
}
};