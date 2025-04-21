class Solution {
public:
    int hIndex(vector<int>& c) {
        int s=0,e=c.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(c[mid]>=(c.size()-mid))  e=mid-1;
            else s=mid+1;
        }
        return c.size()-s;
    }
};