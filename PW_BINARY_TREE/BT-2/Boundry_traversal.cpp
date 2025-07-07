#include <bits/stdc++.h>
using namespace std;
#include <climits>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelordertraversal(Node *root, vector<vector<int>> &ans)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> sub;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            ans.push_back(sub);
            sub.clear();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            sub.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    cout << "Displaying The vector of the level order traversal:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

// int get_hight(Node* root){
//     if(!root)   return 0;
//     return 1+max(get_hight(root->left),get_hight(root->right));
// }

bool print_left_boundry(Node *root)
{
    if (!root)
        return 1;
    if (!root->left && !root->right)
        return 0;
    cout << root->val << " ";
    if (!print_left_boundry(root->left))
        return 0;
    if (!print_left_boundry(root->right))
        return 0;
    return 1;
}

// Instead of doing this we can right the function of left boundry like this:
void print_left_boundry_second_method(Node *root)
{
    if (!root)
        return;
    if (!root->right && !root->left)
        return;
    print_left_boundry_second_method(root->left);
    if (!root->left)
        print_left_boundry_second_method(root->right);
}

bool print_right_boundry(Node *root, vector<int> ans)
{
    if (!root)
        return 1;
    if (!root->left && !root->right)
    {
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        return 0;
    }
    ans.push_back(root->val);
    if (!print_right_boundry(root->right, ans))
        return 0;
    if (!print_right_boundry(root->left, ans))
        return 0;
    return 1;
}

void pre(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->val << " ";
        return;
    }
    pre(root->left);
    pre(root->right);
}

void get(Node *root)
{
    print_left_boundry(root);
    pre(root);
    print_right_boundry(root->right, {});
    cout << endl;
}

Node *get_tree(vector<int> ans)
{
    if (!ans.size())
        return NULL;
    queue<Node *> q;
    Node *root = new Node(ans[0]);
    q.push(root);
    int i = 1;
    while (i < ans.size())
    {
        Node *t = q.front();
        q.pop();
        if (ans[i] != INT_MIN)
        {
            Node *ln = new Node(ans[i]);
            t->left = ln;
            q.push(ln);
        }
        i++;
        if (i < ans.size() && ans[i] != INT_MIN)
        {
            Node *rn = new Node(ans[i]);
            t->right = rn;
            q.push(rn);
        }
        i++;
    }
    return root;
}

int main()
{
    // From this we can only add the node of the tree with our hand:
    Node *a = new Node(1);
    Node *b = new Node(7);
    Node *c = new Node(9);
    Node *d = new Node(2);
    Node *e = new Node(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    Node *f = new Node(8);
    Node *g = new Node(7);
    e->left = f;
    e->right = g;
    Node *i = new Node(0);
    c->right = i;
    Node *j = new Node(13);
    i->left = j;
    cout << "Doing the level order traversal first:---->" << endl;
    vector<vector<int>> ans;
    levelordertraversal(a, ans);
    cout << endl;
    cout << "print the boundry node in the BT in anticlock wise order:--->" << endl;
    cout << "It can be consider as the view of the BT:--->" << endl;
    get(a);

    // To construct a tree easly we can use the method of creating the tree form the vector:

    vector<int> new_tree = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    Node *root = get_tree(new_tree);
    cout << "Doing the level order traversal of the second big tree:---->" << endl;
    vector<vector<int>> ntree;
    levelordertraversal(root, ntree);
    cout << endl;
    cout << "print the boundry node in the BT in anticlock wise order for the second Big tree:--->" << endl;
    cout << "It can be consider as the view of the BT:--->" << endl;
    get(root);
    return 0;
}