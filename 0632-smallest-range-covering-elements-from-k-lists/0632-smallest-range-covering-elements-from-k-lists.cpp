
class Node{
    public:
    int val,i,j;
    Node(int val,int i,int j){
        this->val=val;
        this->i=i;
        this->j=j;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto com=[](Node* a,Node* b){
            return a->val>b->val;
        };
        priority_queue<Node*,vector<Node*>,decltype(com)> q(com);
        int max_element=INT_MIN;
        for(int i=0;i<nums.size();i++){
            Node* temp=new Node(nums[i][0],i,0);
            q.push(temp);
            max_element=max(max_element,temp->val);
        }
        int lower=-1,upper=-1,ans=INT_MAX;
        while(1){
            if(ans>max_element-(q.top()->val)){
                ans=max_element-(q.top()->val);
                lower=q.top()->val;
                upper=max_element;
            }
            if(q.top()->j+1>=nums[q.top()->i].size()) break ;
            Node* temp=new Node(nums[q.top()->i][q.top()->j+1]
            ,q.top()->i,q.top()->j+1);
            q.pop();
            q.push(temp);
            max_element=max(max_element,temp->val);
        }
        return {lower,upper};
    }
};