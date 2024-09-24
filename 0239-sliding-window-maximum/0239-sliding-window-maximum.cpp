class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        stack<int> s;
        s.push(nums.size()-1);
        ans[nums.size()-1]=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            while(!s.empty() && nums[i]>=nums[s.top()])
                s.pop();
            if(s.empty())   ans[i]=nums.size();
            else    ans[i]=s.top();
            s.push(i);
        }
        cout<<"The vector is"<<endl;
        for(auto it:ans)
            cout<<it;
        cout<<endl;
        vector<int> fans(nums.size()-k+1,0);
        int fi=0,li=nums.size()+1-k;
        while(fi<li){
            int i=fi;
            if(ans[i]==(i+k-1))
                fans[fi]=nums[i+k-1];
            else if(ans[i]>(i+k-1))
                fans[fi]=nums[fi];
            else{
                while(!(ans[i]>=(fi+k-1)))
                    i=ans[i];
                if(ans[i]==(fi+k-1))    fans[fi]=nums[fi+k-1];    
                else    fans[fi]=nums[i];
            }
            fi++;
        }
        return fans;
    }
};