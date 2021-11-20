class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans;
        ans.push_back(0);

        pq.push({n-1, temperatures[n-1]});

        for(int i = n-2; i >= 0; i--){
            while(!pq.empty() && pq.top().second <= temperatures[i]) pq.pop();

            if(pq.empty()) {ans.push_back(0); pq.push({i, temperatures[i]});}
            else{
                ans.push_back(pq.top().first - i);
                pq.push({i, temperatures[i]});
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};