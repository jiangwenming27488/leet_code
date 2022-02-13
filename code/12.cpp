class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> nums={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::vector<std::string> symbols={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
        std::string roman;
        for(int i=0;i<nums.size();++i){
            int counts=num/nums[i];
            for(int j=0;j<counts;++j){
                roman.append(symbols[i]);
            }
            num%=nums[i];
        }
        return roman;
    }
};