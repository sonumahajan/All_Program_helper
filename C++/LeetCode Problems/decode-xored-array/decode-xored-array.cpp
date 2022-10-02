class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> result = {first};
        for (const auto x: encoded) {
            result.push_back(result.back() ^ x);
        }
        return result;
        
    }
};
