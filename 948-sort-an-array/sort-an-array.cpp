class Solution {



    void merge(vector<int>& nums,int left ,int mid,int right){

        int n1=mid-left+1;
        int n2=right-mid;
        vector<int> l1(n1),l2(n2);

        for(int i=0;i<n1;i++){
            l1[i]=nums[left+i];
        }
        for(int i=0;i<n2;i++){
            l2[i]=nums[mid+1+i];

        }

        int i=0,k=left,j=0;
        while(i<n1 && j<n2){
            if(l1[i]<l2[j]){
                nums[k]=l1[i];
                i++;
            }
            else{
                nums[k]=l2[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            nums[k]=l1[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=l2[j];
            j++;
            k++;
        }
        
    }


    void mergesort(vector<int>& nums,int left ,int right){
        if(left>=right){
            return;
        }
        int mid=left+(right - left)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};