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
 void range(TreeNode* root, const pair<int,int> &rg,vector<int>&result)
{
      if(root == NULL)
      {
        return;
      }
      if(root->val <rg.first) {
        range(root->right,rg);
      } else if(root->val > rg.second) {
        range(root->left,rg,result);
        range(root->right,rg,result);
      } else{
          result.push_back(root->val);
          range(root->left,rg,result);
          range(root->right,rg,result);
      }
}
vector<int> range(TreeNode* root,pair<int,int> rg)
{

}
int main()
{

}