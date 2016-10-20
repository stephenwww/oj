class Solution 
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
    	if (matrix.empty()==true || matrix[0][0]>target)
    	{
    		return false;
    	}

    	int l=0, r=matrix.size()-1, mid;
    	while (l <= r)
    	{
    		mid = (l+r) >> 1;
    		if (matrix[mid][0] < target)
    		{
    			l = mid + 1;
    		} else if (matrix[mid][0] > target)
    		{
    			r = mid - 1;
    		} else
    		{
    			return true; // ==
    		}
    	}
    	int row = (l==matrix.size() || matrix[l][0]>target)? l-1: l;
    	l=0, r=matrix[row].size()-1;
    	while (l <= r)
    	{
    		mid = (l+r) >> 1;
    		if (matrix[row][mid] < target)
    		{
    			l = mid + 1;
    		} else if (matrix[row][mid] > target)
    		{
    			r = mid - 1;
    		} else
    		{
    			return true;
    		}
    	}

    	return false;
    }
};