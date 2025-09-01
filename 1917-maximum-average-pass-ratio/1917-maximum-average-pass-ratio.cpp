class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++){
            int first=classes[i][0];
            int second=classes[i][1];
            double avgdiff=(double)((double)(first+1)/(second+1))-
            ((double)(first)/(second));
            pq.push({avgdiff,i});
        }
        while(extraStudents--){
            pair<double,int> temp=pq.top();
            int ind=temp.second;
            pq.pop();
            classes[ind][0]++;
            classes[ind][1]++;
            int first=classes[ind][0];
            int second=classes[ind][1];
            double avgdiff=(double)((double)(first+1)/(second+1))-
            ((double)(first)/(second));
            pq.push({avgdiff,ind});
        }
        double ans=0;
        for(int i=0;i<classes.size();i++)   
            ans+=((double)classes[i][0]/classes[i][1]);
        return ans/classes.size(); 
    }
};