class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int cnt=0,temp=in[0][1];
        for(int i=1;i<in.size();i++){
            if(temp>in[i][0]){
                cnt++;
                temp=min(temp,in[i][1]);
            }
            else temp=in[i][1];
        }
        return cnt;
    }
};