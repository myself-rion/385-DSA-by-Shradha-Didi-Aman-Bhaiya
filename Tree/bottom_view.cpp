vector <int> bottomView(Node *root){
 vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*, int> frontNode= q.front();
            q.pop();
            int horizontalDis= frontNode.second;
            Node* temp= frontNode.first;
            
            topNode[horizontalDis]= temp->data;
                
            if(temp->left)
                q.push({temp->left, horizontalDis-1});
            if(temp->right)
                q.push({temp->right, horizontalDis+1});
        }
        
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
}