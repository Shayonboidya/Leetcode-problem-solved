class Solution {
public:
    int t[100001];
    int solved(int n, vector<int>&costs,int i){
        if(i >= n){
            return 0;
        }
        if(t[i] !=-1){
            return t[i];
        }
        int cost = INT_MAX;
        int j = i+1;
        if(j <= n){
            cost = min(cost , (costs[j-1] + (j -i)*(j-i)) + solved(n,costs,j)); 
        }
        j = i+2;
        if(j <= n){
            cost = min(cost , (costs[j-1] + (j -i)*(j-i)) + solved(n,costs,j)); 
        }
        j = i+3;
        if(j <= n){
            cost = min(cost , (costs[j-1] + (j -i)*(j-i)) + solved(n,costs,j)); 
        }
        return t[i] = cost;
        
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solved(n,costs,0);
    }
};