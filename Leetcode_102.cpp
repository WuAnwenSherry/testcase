class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> Tree;
        vector<vector<int>> Treeval;
        if(root==nullptr)
            return Treeval;
        vector<TreeNode*> Treenodetemp;
        Treenodetemp.push_back(root);
        vector<int> rootval;
        rootval.push_back(root->val);
        Treeval.push_back(rootval);
        Tree.push_back(Treenodetemp);
        bool flag=true;
        int layer=0;
        while(flag){
            vector<TreeNode*> nextlayer;
            vector<int> nextlayerval;
            for(int i=0;i<Tree[layer].size();i++)
            {
                TreeNode* nodetemp=Tree[layer][i];
                if(nodetemp->left!=nullptr)
                {
                    nextlayer.push_back(nodetemp->left);
                    nextlayerval.push_back(nodetemp->left->val);
                }
                if(nodetemp->right!=nullptr)
                {
                    nextlayer.push_back(nodetemp->right);
                    nextlayerval.push_back(nodetemp->right->val);
                }
            }
            if (nextlayer.empty())
                flag=false;
            else
            {
                Tree.push_back(nextlayer);
                Treeval.push_back(nextlayerval);
                layer++;
            }
        }
      //  for(int i=0;i<Treeval[layer].size();i++)
     //   cout<<Treeval[layer][i]<<endl;
        return Treeval;
        
    }
};
