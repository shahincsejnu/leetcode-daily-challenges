class CombinationIterator {
public:
    vector<string> v;
    string ss;
    int idx;

    void solve(string &s, string ans, int pos, int len)
    {
        if(ans.size() == len){
            v.push_back(ans);
            return;
        }

        for(int i = pos; i < s.size(); i++){
            ans.push_back(s[i]);
            solve(s, ans, i+1, len);
            ans.pop_back();
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        idx = 0;
        solve(characters, "", 0, combinationLength);
    }

    string next() {
        return v[idx++];
    }

    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */