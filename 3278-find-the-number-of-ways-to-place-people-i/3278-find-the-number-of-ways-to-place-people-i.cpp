class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt=0;
        sort(points.begin(),points.end(),
        [](const vector<int> &v1,const vector<int> &v2){
            return (v1[0]==v2[0]) ? v1[1]>v2[1] : v1[0]<v2[0];
        });
        for(int i=0;i<points.size()-1;i++){
            int comp=INT_MIN;
            for(int j=i+1;j<points.size();j++)
                if(points[j][1]<=points[i][1] && points[j][1]>comp){
                    cnt++;
                    comp=points[j][1];
                }
        }
        return cnt;
    }
};