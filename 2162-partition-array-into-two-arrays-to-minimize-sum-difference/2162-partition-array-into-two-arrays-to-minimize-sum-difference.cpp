class Solution {

    int solve(vector<int> &v1,vector<int> &v2,int sum){
        int ans=INT_MAX;
        for(auto it:v1){
            int target=(sum/2)-it;
            int lb=lower_bound(v2.begin(),v2.end(),target)-v2.begin();
            if(lb==v2.size())   ans=min(ans,abs(sum-2*(it+v2[lb-1])));
            else if(!lb)    ans=min(ans,abs(sum-2*(it+v2[0])));
            else ans=min({ans,abs(sum-2*(it+v2[lb-1])),abs(sum-2*(it+v2[lb]))});
        }
        return ans;
    }

public:
    int minimumDifference(vector<int>& nums) {
        vector<int> vec1,vec2;
        int n=nums.size()/2;
        int sum=0;
        for(int i=0;i<n;i++){
            vec1.push_back(nums[i]);
            vec2.push_back(nums[i+n]);
            sum+=(nums[i]+nums[i+n]);
        }
        // Generating the all of the possible sumations:
        vector<vector<int>> part1(n+1),part2(n+1);
        for(int mask=0;mask<(1<<n);mask++){
            int cnt=0,temp1=0,temp2=0;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    temp1+=(vec1[j]);
                    temp2+=(vec2[j]);
                    cnt++;
                }
            }
            part1[cnt].push_back(temp1);
            part2[cnt].push_back(temp2);
        }
        for(int i=0;i<=n;i++) sort(part2[i].begin(),part2[i].end());
        int ans=INT_MAX;
        for(int i=0;i<=n;i++)
            ans=min(ans,solve(part1[i],part2[n-i],sum));
        return ans;
    }
};