#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

struct TrieNode
{
	map<char, shared_ptr<TrieNode>> children;
	bool is_word = false;
};

class Trie
{
public:
	Trie(vector<string>& words): root(shared_ptr<TrieNode>(new TrieNode))
	{
		for (auto word: words)
		{
			insert(word);
		}
	}

	// Inserts a word into the trie.
	void insert(string word) const
	{
		if (word.empty())
		{
			return ;
		}
		auto node = root;
		for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
		{
			if (node->children.find((word[i])) == node->children.end())
			{
				node->children[word[i]] = shared_ptr<TrieNode>(new TrieNode);
			}
		}
		node->is_word = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) const
	{
		auto node = searchNode(word);
		return node!=nullptr && node->is_word;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) const
	{
		return searchNode(prefix) != nullptr;
	}

private:
	shared_ptr<TrieNode> searchNode(string word) const
	{
		auto node = root;
		for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
		{
			if (node->children.find(word[i]) == node->children.end())
			{
				return nullptr;
			}
		}
		return node;
	}

	shared_ptr<TrieNode> root;
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
    	if (board.empty())
    	{
    		return ret;
    	}

        Trie trie(words);
        vi = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++ i)
        {
        	// use board[0] instead of board[i] to get the better performance
        	for (int j = 0; j < board[0].size(); ++ j)
        	{
        		dfs(string(), board, i, j, trie);
        	}
        }

        return ret;
    }

private:
	void dfs(string cur, const vector<vector<char>>& board, int i, int j, Trie& trie)
	{
		if (vi[i][j] == true)
		{
			return ;
		}

		vi[i][j] = true;
		cur += board[i][j];
		if (trie.search(cur))
		{
			ret.push_back(cur);
		}
		if (trie.startsWith(cur) == true)
		{
			for (auto dir: dirs)
			{
				if (i+dir[0]>=0 && i+dir[0]<board.size()
					&& j+dir[1]>=0 && j+dir[1]<board[0].size())
				{
					dfs(cur, board, i+dir[0], j+dir[1], trie);
				}
			}
		}
		vi[i][j] = false;
	}

	vector<string> ret;
	vector<vector<bool>> vi;
	int dirs[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

