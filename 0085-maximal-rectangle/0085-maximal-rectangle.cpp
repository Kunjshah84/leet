class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> temp(matrix[0].size(),0);
        stack<int> s;
        int ans=0;
        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++)  
                if(matrix[row][col]=='0')   temp[col]=0;
                else temp[col]++;
            s.push(0);
            int sub_ans=0;
            for(int i=1;i<=temp.size();i++){
                while(!s.empty() && (i==temp.size() || temp[i]<=temp[s.top()])){
                    int top=s.top();
                    s.pop();
                    if(s.empty()) sub_ans=max(sub_ans,(temp[top]*i));   
                    else sub_ans=max(sub_ans,((i-s.top()-1)*temp[top]));
                }
                s.push(i);
            }
            while(s.size()) s.pop();
            ans=max(ans,sub_ans);
        }
        return ans;
    }
};