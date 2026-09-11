class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> map(10, 0);
        for(int x:digits){
            map[x]++;
        }
        int cnt = 0;
        for(int i =1 ;i <= 9;i++){
            if(map[i] == 0)continue;
            map[i]--;
            for(int j =0;j <= 9;j++){
                if(map[j] == 0) continue;
                map[j]--;
                for(int k = 0;k <= 8;k+=2){
                    if(map[k] == 0) continue;
                    map[k]--;
                    cnt++;
                    map[k]++;
                }
                map[j]++;
            }
            map[i]++;
        }
        return cnt;
    }
};