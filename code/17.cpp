class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> alphas={
            "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        this->letters.clear();
        std::string letter;
        compute(digits,alphas,letter,0);
        return this->letters;
    }
private:
    void compute(const std::string& src,const std::vector<std::string>& alphas, std::string& letter,int idx){
        if(idx==src.length()){
            if(!letter.empty()){
                letters.push_back(letter);
            }
            return;
        }
        int index=(src[idx]-'0')-2;
        for(auto const& alpha:alphas[index]){
            letter.push_back(alpha);
            compute(src,alphas,letter,idx+1);
            letter.pop_back();
        }
    }
private:
    std::vector<std::string> letters;
};