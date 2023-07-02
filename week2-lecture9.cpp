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

bool isLeaf(TreeNode * root)
{
    return (root != NULL && root->left ==NULL && root->right ==NULL);
}
void maxSumPath(TreeNode* root,int sum, int &maxSum)
{
    if(root == NULL)
    {
        return;
    }
    sum += root->val;
    if(isLeaf(root)){
        maxSum =max(maxSum,sum);
        return;
    } else{
        maxSumPath(root->left,sum,maxSum);
        maxSumPath(root->right,sum,maxSum);
    }
}
int maxPath(TreeNode* root) {
    int maxSum =0;
    maxSumPath(root,0,maxSum);
    return maxSum;
}

int leafToLeafMaxSum(TreeNode* root,int *ltrSum){
    if(root ==NULL){
        *ltrSum =0;
        return 0;
    }
    if(isLeaf(root)){
        *ltrSum=0;
        return root->val;
    }
    int lSum=0,rSum=0;
    lSum=leafToLeafMaxSum(root->left,ltrSum);
    rSum=leafToLeafMaxSum(root->right,ltrSum);
    if(root->left !=NULL && root->right !=NULL){
        *ltrSum = max(*ltrSum,max(lSum,rSum));
        return max(lSum,rSum) + root->val;
    }else if(root->left != NULL){
        return root->val +lSum;

    }else{
        return root->val +rSum;
    }
}
int main()
{

}