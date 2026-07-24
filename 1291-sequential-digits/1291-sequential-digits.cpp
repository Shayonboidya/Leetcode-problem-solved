class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        int lenLow = to_string(low).length();
        int lenHigh = to_string(high).length();

        for(int i = lenLow; i <= lenHigh;i++){
            for(int j = 0; i+j <= 9;j++){
                int num = stoi(s.substr(j,i));
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
        
    }
};