class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse(arr.size(),arr.size());
        vector<int> pse(arr.size(),-1);
        stack<int> snse;
        stack<int> spse;
        for(int i=0;i<arr.size();i++){
            // Finding the pre
            while(spse.size() && arr[spse.top()]>arr[i])  spse.pop();
            if(spse.size())    pse[i]=spse.top();
            spse.push(i);
            // Finding the nse
            while(snse.size() && arr[snse.top()]>=arr[arr.size()-i-1])   snse.pop();
            if(snse.size()) nse[arr.size()-i-1]=snse.top();
            snse.push(arr.size()-i-1);
        }
        int ans=0;
        int mod=1000000007;
        for(int i=0;i<arr.size();i++){
            long long one=nse[i]-i;
            long long second=i-pse[i];
            ans=(ans+(one*second*arr[i]*1ll)%mod)%mod;
        }
        return ans;
    }
};