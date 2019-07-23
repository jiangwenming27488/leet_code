class Solution {
public:
   void calcombinationSum2(int index,const vector<int>& nums,const int target,int sum,int len){
	   if(sum>=target){
           if(sum==target){
               if(find(result.begin(),result.end(),path)==result.end()){
                   result.emplace_back(path);
               }
           }
           return;
       }
       for(int i=index;i<len;++i){
		    if(used[i]==false){
			    path.push_back(nums[i]);
			    used[i]=true;
			    calcombinationSum2(i+1,nums,target,sum+nums[i],len);
			    used[i]=false;
			    path.pop_back();
		    }
	    }
       return;
    }
    vector<vector<int>> combinationSum2(vector<int>& vecs, int target) {
	    int len=vecs.size();
        sort(vecs.begin(),vecs.end());
        used.resize(len,false);
        calcombinationSum2(0,vecs,target,0,len);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> used;
    vector<int> path;
};
