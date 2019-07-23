class Solution {
public:
    bool find(char ch){
        if(ch>='A' && ch<='Z') ch=ch-'A'+'a'; 
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    } 
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right && !find(s[left])) ++left;
            while(right>left && !find(s[right])) --right;
            swap(s[left],s[right]);
            ++left;
            --right;
        }
        return s;
    }
};
