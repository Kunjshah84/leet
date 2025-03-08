class Solution {

    void get(vector<int> &temp,int right){
        for(int i=2;i*i <=right;i++)
            if(temp[i])
                for(int j=i*i;j<=right;j+=i)    temp[j]=0;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        if(right==left) return {-1,-1};
        vector<int> temp(right+1,1);
        get(temp,right);
        temp[0]=temp[1]=0;
        while(left<right && !temp[left])    left++;
        if(left==right) return {-1,-1};
        int pre=left,ans=INT_MAX;
        vector<int> fans;
        left++;
        while(left<=right){
            if(temp[left] && ans>(left-pre)){
                ans=min(ans,(left-pre));
                fans={pre,left};
            }
            pre=(temp[left]) ? left : pre; 
            left++;
        }
        if(ans==INT_MAX)    return {-1,-1};
        return fans; 
    }
};