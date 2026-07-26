class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0,first = 0;
        do{
            first = v[v[first]];
            slow = v[slow];
        }while(slow != first);

        slow = 0;
        while(slow != first){
            first = v[first];
            slow = v[slow];
        }
        return slow;
    }
};