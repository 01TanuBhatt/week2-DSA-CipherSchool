#include <bits/stdc++.h>
using namespace std;


class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root,vector<int> &result){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    result.push_back(root->val);
    inorder(root->right);
}
vector<int> inorder(TreeNode *root){
      vector<int> result;
      inorder(root,result);
      return result;
}
vector<int> presorder(TreeNode* root){
    if(root == NULL){
        return{};
    }
    vector<int> result;
    stack<TreeNode *>S;
    S.push(root);
    TreeNode *temp;
    while(true) {

        while(temp != NULL && temp->left !=NULL){
            result.push_back(temp->val);
            temp=temp->left;
        }
        if(!S.empty()) {
          break;  
        }
        temp =S.top();S.pop();
             temp=temp->right;
       
    }
    return result;
}

void printGivenLevel(TreeNode* root,int level,vector<int> &levelH){
    if(root == NULL)
    {
        return;
    }
    if(level == 0){
        levelH.push_back(root->val);
        } else if(level>0){
            printGivenLevel(root->left,level-1,levelH);
            printGivenLevel(root->right,level-1,levelH);

        }
}
int height(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    else{
        return 1+max(height(root->left),height(root->right));
    }
}
vector<vector<int>> levelOrder(TreeNode* root){
    if(root == NULL){
        return {};
    }
    vector<vector<int>> levelOrder;
    int H = height(root);
    for(int h=1;h<=H;h++) {
        vector<int> levelH;
        printGivenLevel(root,h,levelH);
        levelOrder.push_back(levelH);
    }
    return levelOrder;
}

vector<vector<int>> levelOrderLineByLineIterative(TreeNode* root) {
    if(root ==NULL) {
        return {};
    }
    vector<vector<int>> result;
    vector<int> currLevel;
    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()) {
        root =Q.front();Q.pop();
        if(root == NULL) {
            result.push_back(currLevel);
            currLevel.clear();
            if(!Q.empty()) {
                    Q.push(NULL);
            }
        }else{
        currLevel.push_back(root->val);
        if(root->left != NULL)
        Q.push(root->left);
        if(root->right != NULL)
        Q.push(root->right);
        }
       
    }
    return result;
}

int diameter(TreeNode* root){
    if(root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh+rh+1,diameter(root->left),diameter);
}
int main(){

}