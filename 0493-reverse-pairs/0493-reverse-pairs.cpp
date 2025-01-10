class Solution {

    void merge_two_sorted(vector<int> &nums,int low,int high){
        int i=low;
        int mid=(low+high)/2;
        vector<int> temp;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j])    temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);    
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++)  nums[low++]=temp[i];
    }

    void get(vector<int> &nums,int low,int high,int &cnt,int mid){
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i] > 2*(long long)nums[j])   j++;
            cnt+=(j-mid-1);
        }
    }

    void merge(vector<int> &nums,int low,int high,int &cnt){
        if(low==high)   return ;
        int mid=(low+high)/2;
        merge(nums,low,mid,cnt);
        merge(nums,mid+1,high,cnt);
        get(nums,low,high,cnt,mid);
        merge_two_sorted(nums,low,high);
    }
public:
    int reversePairs(vector<int>& nums) {
        //The reason why the old code is haging the TLE is tooo crazy 
        //which is called the programme copying overhead:
        int cnt=0;
        merge(nums,0,nums.size()-1,cnt);
        return cnt;
    }
};