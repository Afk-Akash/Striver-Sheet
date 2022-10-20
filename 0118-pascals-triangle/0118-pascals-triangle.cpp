class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans = {{1}};
        if(n == 1) return ans;
        ans.push_back({1,1});
        if(n == 2) return ans;
        n -= 2;
        while(n--){
            vector<int> v(1,1);
            vector<int> &temp = ans.back();
            for(int i = 1; i < temp.size(); i++){
                v.push_back(temp[i-1] + temp[i]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};