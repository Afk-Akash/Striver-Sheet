class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int,int> mp;
        for(auto &a : skill)mp[a]++;
        int n = skill.size();
        long long sum  = accumulate(skill.begin(), skill.end(), 0*1LL);
        if(sum % (skill.size()/2)) return -1;
        sum /= (n/2);
        // cout<<1;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int num = skill[i];
            if(!mp.count(num))continue;
            mp[num]--;
            if(!mp.count(sum - num))continue;
            else mp[sum - num]--;
            ans += (1LL* num * (sum - num));
            if(mp[num] == 0)mp.erase(num);
            if(mp[sum-num] == 0) mp.erase(sum - num);
        }
        // cout<<mp.size();
        if(mp.size()) return -1;
        return ans;
    }
};