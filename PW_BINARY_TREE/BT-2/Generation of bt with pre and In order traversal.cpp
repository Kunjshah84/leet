#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* get(vector<int> pre,vector<int> in){
    int i=0,j=0;
     
}


void levelordertraversal(Node* root,vector<vector<int>> &ans){
        queue<Node*> q;
        q.push(root); 
        q.push(NULL); 
        vector<int> sub;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(!temp){
                ans.push_back(sub);
                sub.clear();
                if(!q.empty())  q.push(NULL);
            }
            else{
                sub.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
        }
        cout<<"Displaying The vector of the level order traversal:"<<endl;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }

int main(){
    vector<int> pre={1,2,4,5,3,6,7};
    vector<int> in={4,2,5,1,6,3,7};
    Node* root=get(pre,in);
    //The leve order travarsal to check weather the given generated tree is right of wrong?
    vector<vector<int>> ans;
    // levelordertraversal(a,ans);
    return 0;
}