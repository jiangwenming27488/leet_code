class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if(len%2==1){
            return this->findKthElement(nums1,nums2,len/2+1);
        }else{
             return 0.5*(this->findKthElement(nums1,nums2,len/2)+this->findKthElement(nums1,nums2,len/2+1));
         }
    }
private:
    int findKthElement(const std::vector<int>& nums1,const std::vector<int>& nums2,int k){
        int idx1=0;
        int idx2=0;
        int element=-1;
        int len1=nums1.size();
        int len2=nums2.size();
        while(idx1<len1 && idx2<len2 && k>1){
            int index1=std::min(len1-1,idx1+k/2-1);
            int index2=std::min(len2-1,idx2+k/2-1);
            if(nums1[index1]<=nums2[index2]){
                k=k-(index1-idx1+1);
                idx1=index1+1;
            }else{
                k=k-(index2-idx2+1);
                idx2=index2+1;
            }
        }
        if(idx1>=nums1.size()){
            element=nums2[idx2+k-1];
        }else if(idx2>=nums2.size()){
            element=nums1[idx1+k-1];
        }else{
            element=std::min(nums1[idx1],nums2[idx2]);
        }
        return element;
    }

};