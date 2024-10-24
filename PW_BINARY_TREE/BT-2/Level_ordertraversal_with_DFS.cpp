#include<iostream>
#include<queue>
#include<vector>
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

    void get(Node* root,int level,int cur_level){
        if(!root)   return ;
        if(level==cur_level){
            cout<<root->val<<" ";
            return ;
        }
        get(root->left,level,cur_level+1);
        get(root->right,level,cur_level+1);
    }

    int hight(Node* root){
        if(!root)   return 0;
        return 1+max(hight(root->left),hight(root->right));
    }

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* g=new Node(6);
    Node* h=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=g;
    c->right=h;
    vector<vector<int>> ans;
    levelordertraversal(a,ans);
    int n;
    cout<<"Enter the number of level that you have to print:"<<endl;
    cin>>n;
    get(a,n,1);
    //Now we can easly do the level order traversal if we know the hight of the tree:
    // Then agian we have to create the function that can find the depth of the tree:
    cout<<"Doing the BFS on the basis of DFS:"<<endl;
    for(int i=1;i<=hight(a);i++){
        get(a,i,1);
        cout<<endl;
    }
    return 0;
}