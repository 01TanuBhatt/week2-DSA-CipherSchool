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

int find(vector<int> &preorder,int start,int end,int x) {
    int index = start;
    while(index <= end && preorder[index] > x){
        index++;
    }
    return index;
}
TreeNode* buildTree(vector<int> sortedArr,int start,int end)
{
    if(start >end){
        return NULL;
    }
        int mid = start+(end-start)/2;
       TreeNode* newNode = new TreeNode(sortedArr[mid]);
       
        newNode->left = buildTree(sortedArr,start,mid-1);
        newNode->right = buildTree(sortedArr,mid+1,end);
        return newNode;
    
}

TreeNode* leastCommonAncestors(TreeNode* root,const int &l,const int &r) {
    if(root == NULL){
        return NULL;
    }
    if(root->val >= l && root->val <=r)
    {
        return root;
    }
    if(root->val <l)
    {
        return leastCommonAncestors(root->right,l,r);
    } else {
        return leastCommonAncestors(root->left,l,r);
    }
}
int main()
{

}