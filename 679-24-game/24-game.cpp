class Solution {
public:
    bool solve(vector<double>& v){
        if(v.size()==1){
             return abs(v[0]-24.0)<1e-12;
        }

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i==j) continue;
                vector<double> temp;
                for(int k=0;k<v.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(v[k]);
                    }

                }
                temp.push_back(v[i]+v[j]);
                if(solve(temp)) return true;
                temp.pop_back();

                 temp.push_back(v[i]-v[j]);
                if(solve(temp)) return true;
                temp.pop_back();

               

                 temp.push_back(v[i]*v[j]);
                if(solve(temp)) return true;
                temp.pop_back();

                if(v[j]!=0){
                     temp.push_back(v[i]/v[j]);
                if(solve(temp)) return true;
                temp.pop_back();
                }
                
            }

        }
        return false;
    }


    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.begin(),cards.end());
        return solve(v);
    }
};