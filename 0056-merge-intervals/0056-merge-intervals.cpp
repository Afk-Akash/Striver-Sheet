class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]) return true;
        if(a[0] > b[0]) return false;
        return a[1] > b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        
        vector<vector<int>> ans;
        vector<int> t(2);
        t = v[0];
        for(int i = 1; i < v.size(); i++){
            if(t[1] >= v[i][0]){
                t[1] = max(t[1], v[i][1]);
            }
            else{
                ans.push_back(t);
                t = v[i];
            }
        }
        ans.push_back(t);
        return ans;
    }
};