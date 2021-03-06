class Solution 
{
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
    	vector<vector<int>> ret;
        vector<TreeNode*> same_level_node[2];
		same_level_node[0].push_back(root);

        while (same_level_node[0].empty() == false)
        {
        	vector<int> num;
        	same_level_node[1].clear();
        	
        	for (size_t i = 0; i < same_level_node[0].size(); ++ i)
        	{
        		if (same_level_node[0][i] != NULL)
        		{
        			num.push_back( same_level_node[0][i]->val );
        			same_level_node[1].push_back( same_level_node[0][i]->left );
        			same_level_node[1].push_back( same_level_node[0][i]->right );
        		}
        	}
            if (num.size() != 0)
            {
            	ret.push_back(num);
            }
        	same_level_node[0] = same_level_node[1];
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};