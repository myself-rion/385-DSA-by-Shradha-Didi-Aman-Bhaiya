void solve(vector<int> &a , Node* root, int lvl){
        if(root==NULL)
            return;
        
        
        if(lvl==a.size()) // stepped on new level
            a.push_back(root->data);
            
        solve(a,root->left,lvl+1);
        solve(a,root->right,lvl+1);
        
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(ans,root,0);
       return ans;
    }