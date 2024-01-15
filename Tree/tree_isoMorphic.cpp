class Solution
{
public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL) //2 empty trees are always isomorphic
            return true;
        if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) || root1->data != root2->data)
            return false;

        bool left_right_iso = isIsomorphic(root1->left, root2->right); // checing if structure of left subtree of r1 & structure of right subtree of r2 is same

        bool right_left_iso = isIsomorphic(root1->right, root2->left); // checing if structure of rgiht subtree of r1 & structure of left subtree of r2 is same

        bool left_left_iso = isIsomorphic(root1->left, root2->left);  // checing if structure of left subtree of r1 & structure of left subtree of r2 is same

        bool right_right_iso = isIsomorphic(root1->right, root2->right); // checing if structure of right subtree of r1 & structure of right subtree of r2 is same

        return (left_right_iso && right_left_iso) || (left_left_iso && right_right_iso); //if any pair of condition is true then the trees are isomorphic
    }
};