class Solution {
public:
    bool check(const string& str1,const string& str2){
        int count=0;
        for(int i=0;i<str1.size();++i){
            if(str1[i]!=str2[i]) ++count;
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        _deque.emplace_back(beginWord);
        int step=0;
        int len=wordList.size();
        vector<int> vec(len,0);
        while(!_deque.empty()){
            ++step;
            int count=_deque.size();
            while(count>0){
                string begin=*_deque.begin();
                for(int i=0;i<len;++i){
                    if(!vec[i] && check(begin,wordList[i])){
                        if(wordList[i]==endWord) return step+1;
                        vec[i]=1;
                        _deque.emplace_back(wordList[i]);
                    }
                }
                _deque.pop_front();
                --count;
            }
        }
        return 0;
    }
private:
    deque<string> _deque;
};
