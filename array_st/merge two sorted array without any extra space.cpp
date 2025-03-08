// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& inter) {
//         vector<vector<int>> ans;
//         sort(inter.begin(),inter.end());
//         for(int i=0;i<inter.size();i++){
//             if(!ans.empty() && inter[i][0]<=ans.back()[1]) 
//                 ans.back()[1]=max(ans.back()[1],inter[i][1]);
//             else ans.push_back(inter[i]);
//         }
//         return ans;
//     }
// };