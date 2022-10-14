class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> set;
        int ans = 0;
        for(int i = 0; i < rolls.size(); i++){
            if(set.size() != k)set.insert(rolls[i]);
            else {
                ans++;
                set.clear();
                set.insert(rolls[i]);
            }
        }
        if(set.size()==k)ans++;
        return ans + 1;
    }
};