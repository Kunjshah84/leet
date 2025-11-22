class NumArray {

    vector<int> segmentVec;
    int sizeOfVec;

    void makeSegVector(vector<int> &nums,
    int ind,int s,int e){
        if(s==e){
            segmentVec[ind]=nums[s];
            return ;
        }
        int mid=s+(e-s)/2;
        makeSegVector(nums,(2*ind)+1,s,mid);
        makeSegVector(nums,(2*ind)+2,mid+1,e);
        segmentVec[ind]=segmentVec[(2*ind)+1]+segmentVec[(2*ind)+2];
    }

    void updateSegVec(int ind,int val,int s,int e,int par){
        if(s==ind && e==ind){//first done the mistake that this is going to check 
        // only the start of the range:
            segmentVec[par]=val;
            return ;
        }
        int mid=s+(e-s)/2;
        if(ind<=mid)    updateSegVec(ind,val,s,mid,(2*par)+1);
        else  updateSegVec(ind,val,mid+1,e,(2*par)+2);
        segmentVec[par]=segmentVec[(2*par)+1]+segmentVec[(2*par)+2];
    }


    int boundCheck(int left,int right,int s,int e){
        if(right<s || left>e)   return -1;
        else if(s>=left && e<=right)   return 0;
        return 1;
    }

    int getAns(int left,int right,int s,int e,int par){
        int check=boundCheck(left,right,s,e);
        if(check==-1)   return 0;
        else if(!check) return segmentVec[par];
        if(s==e)    return segmentVec[par];
        int mid=s+(e-s)/2;
        int leftVal=getAns(left,right,s,mid,(par*2)+1);
        int rightVal=getAns(left,right,mid+1,e,(par*2)+2);
        return leftVal+rightVal;
    }


public:
    NumArray(vector<int>& nums) {
        sizeOfVec=nums.size();
        segmentVec.resize(4*nums.size(),0);
        makeSegVector(nums,0,0,sizeOfVec-1);
    }
    
    void update(int index, int val) {
        updateSegVec(index,val,0,sizeOfVec-1,0);
        // TC o(n*4)
    }
    

    int sumRange(int left, int right) {
        return getAns(left,right,0,sizeOfVec-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */