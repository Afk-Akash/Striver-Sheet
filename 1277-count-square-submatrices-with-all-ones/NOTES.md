```
class Solution {
public:
int squareCounter(vector<int> &pillar){
int n = pillar.size();
vector<int> HorW(n);
for(int i = 0; i < n; i++){
HorW[i] = pillar[i] ? 1 : 0;
for(int j = i + 1; j < min(n, i+pillar[i]); j++){
if(pillar[j] <= HorW[i])break;
HorW[i] = j-i+1;
}
}
int ans = 0;
for(int i = 0; i < n; i++){
ans += HorW[i];
}
return ans;
}
int countSquares(vector<vector<int>>& m) {
int row = m.size(), col = m[0].size(), ans = 0;
vector<int> temp(col,0);
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
if(m[i][j] == 1)temp[j]++;
else temp[j] = 0;
}
ans += squareCounter(temp);
}
return ans;
}
};
```