class Solution {
public:
    typedef pair<int,int>P;
    typedef tuple<long,int,int>T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // heap for free server (wt, idx)
        priority_queue<P,vector<P>,greater<P>> freeServer;

        // heap for busy server (finitime , wt, idx)
        priority_queue<T,vector<T>,greater<T>> busyServer;

        for(int i = 0;i < n;i++){
            freeServer.push({servers[i],i});
        }

        vector<int>result(m);
        for(int i =0;i < m;i++){
            while(!busyServer.empty() && get<0>(busyServer.top()) <= i){
                auto[finitime, wt, idx] = busyServer.top();
                busyServer.pop();

                freeServer.push({wt,idx});
            }

            if(freeServer.empty()){
                 auto[finitime, wt, idx] = busyServer.top();
                 busyServer.pop();
                 result[i] = idx;
                 busyServer.push({finitime + tasks[i], wt,idx});
            }
            else{
                auto[wt, idx] = freeServer.top();
                freeServer.pop();
                result[i] = idx;
                busyServer.push({i + tasks[i], wt,idx});
            }
        }
        return result;
    }
};