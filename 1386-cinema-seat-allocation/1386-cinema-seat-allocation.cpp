class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> fq;
        for(auto &val: reservedSeats){
            fq[val[0]].insert(val[1]);
        }
        int res = 2* (n - (fq.size()));
        
        for(auto &[row, bookedSeat] : fq){
            auto isAbilable = [&](int seat){
                return bookedSeat.find(seat) == bookedSeat.end();
            };
            bool groupA = isAbilable(2) && isAbilable(3) && isAbilable(4) && isAbilable(5);
            bool groupB = isAbilable(4) && isAbilable(5) && isAbilable(6) && isAbilable(7);
            bool groupC = isAbilable(6) && isAbilable(7) && isAbilable(8) && isAbilable(9);
            if(groupA && groupC){
                res += 2;
            }else if(groupA || groupB ||groupC){
                res++;
            }
        }


        return res;
    }
};