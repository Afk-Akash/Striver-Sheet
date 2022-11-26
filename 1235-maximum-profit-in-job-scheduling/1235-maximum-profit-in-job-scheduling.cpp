class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int, int>> time;
        int n = startTime.size();
        
        for(int i = 0; i < n; i++){
            time.push_back({startTime[i] , endTime[i], profit[i]});
        }
        int ans = 0;
        sort(time.begin(), time.end(), cmp);
        map<int,int> mp;
        mp[0] = 0;
        for(int i = 0; i < n; i++){
            int start = get<0>(time[i]);
            auto it = mp.lower_bound(start);
            if(!mp.count(start))
                it--;
            // cout<<start<<" "<<it->first<<" it "<<endl;
            if(it == mp.begin() or it == mp.end()) mp[get<1>(time[i])] = max(get<2>(time[i]), ans);
            else mp[get<1>(time[i])] = max(max(mp[get<1> (time[i])], it -> second + get<2>(time[i])), ans);
            
            ans = max(ans, mp[get<1>(time[i])]);
        }
        
        // for(auto & a : mp){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        return ans;
        
    }
    static bool cmp(tuple<int,int,int> & a, tuple<int,int,int> &b) {
        return get<1> (a) < get<1> (b);
    }
};