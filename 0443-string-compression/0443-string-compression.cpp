class Solution {
public:
    int compress(vector<char>& chars) {//O(n)
        int n = chars.size(), idx = 0;

        for(int i =0; i < n;i++){
            int cnt = 0; char ch = chars[i];

            while(i < n && ch == chars[i]){
                cnt++; i++;
            }

            if(cnt == 1) chars[idx++] = ch;
            else{
                chars[idx++] = ch;
                string str = to_string(cnt);
                for(char dig: str){
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
        
    }
};