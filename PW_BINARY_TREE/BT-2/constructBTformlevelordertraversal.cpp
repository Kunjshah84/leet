#include<iostream>
#include<vector>
#include<queue>
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
    Node(){
        this->val=0;
        this->right=NULL;
        this->left=NULL;
    }
};


    Node* get(vector<int> ans){
        if(!ans.size()) return NULL;
        queue<Node*> q;
        Node* root=new Node(ans[0]);
        q.push(root);
        int i=1;
        while(i<ans.size()){
            Node* t=q.front();
            q.pop();
            if(ans[i]!=INT_MIN){
                Node* ln=new Node(ans[i]);
                t->left=ln;
                q.push(ln);
            }
            i++;
            if(i < ans.size() && ans[i]!=INT_MIN){
                Node* rn = new Node(ans[i]);
                t->right = rn;
                q.push(rn);
            }
            i++;
        }
        return root;
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
    vector<int> ans={1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    Node* root=get(ans); 
    vector<vector<int>> temp;
    levelordertraversal(root,temp);
    return 0;
}