class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0, leftQ = 0;
        int rightQ = 0, rightSum = 0;
        int l = 0, r = num.size()-1;

        while(l < r){
            if(num[l] == '?'){
                leftQ++;
            }else{
                leftSum += (num[l] - '0');
            }
            l++;

            if(num[r] == '?'){
                rightQ++;
            }else{
                rightSum += (num[r] - '0');
            }
            r--;
        }

        if((leftQ + rightQ) % 2 == 1){
            return true;
        }
        int left = 2 * leftSum + 9 * leftQ;
        int right = 2 * rightSum + 9 * rightQ;
        return left == right ? false : true;
    }
};