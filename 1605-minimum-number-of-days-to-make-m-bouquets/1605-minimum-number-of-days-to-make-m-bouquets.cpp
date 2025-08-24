class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int s=*min_element(b.begin(),b.end()),e=*max_element(b.begin(),b.end());
        bool flag=0;
        while(s<=e){
            int mid=s+(e-s)/2,counter=0,reach=0;
            for(int i=0;i<b.size();i++){
                if(b[i]<=mid)
                    counter++;
                else{
                    reach+=(counter/k);
                    counter=0;
                }
            }
            reach+=(counter/k);
            if(reach>=m){
                flag=1;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        if(flag)
            return s;
        else
            return -1;
    }
};