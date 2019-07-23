class Solution {
public:
    string find(const vector<string>& dict,const string& word,int wordlen){
        int len=0;
        for(auto& element:dict){
            len=element.size();
            if(len<=wordlen){
                if(word.substr(0,len)==element){
                    return element;
                }
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        int first=0;
        sort(dict.begin(),dict.end(),[](const string& a,const string& b){
            return a.size()<b.size();
        });
        int index=0;
        string result;
        sentence+=" ";
        while(index<sentence.size()){
            if(sentence[index]==' '){
            	std::cout<<"substr:"<<sentence.substr(first,index-first)<<std::endl;
                result+=find(dict,sentence.substr(first,index-first),index-first)+" ";
                first=index+1;
            }
            ++index;
        }
        return result;
    }
};

