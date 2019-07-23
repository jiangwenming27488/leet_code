class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> vec;
        for(auto& ele:A){
            vec.emplace_back(ele*ele);
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
};
