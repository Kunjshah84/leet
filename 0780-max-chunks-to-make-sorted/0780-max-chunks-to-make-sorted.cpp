class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int range=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>range)    range=arr[i];
            else if(range==i){
                ans++;
                range++;
            }
        }
        return  ans ? ans : ++ans;
    }
};