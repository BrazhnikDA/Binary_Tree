#pragma once
#include <string>

class CNode
{
private:
	int count;
	std::string value;
	CNode* left, * right;
public:
	CNode(std::string val, CNode* l, CNode* r);
	CNode* addNode(CNode* tree, std::string val);

	CNode* deleteNode(CNode* tree, CNode* node);

	CNode* min(CNode* tree);
	CNode* max(CNode* tree);

	void PrintTree(CNode* root);
};

inline CNode::CNode(std::string val, CNode* l, CNode* r)
{
	value = val;
	left = l;
	right = r;
	count = 1;
}

inline CNode* CNode::addNode(CNode* tree, std::string val)
{
	if (tree == nullptr)
	{
		tree = new CNode(val, nullptr, nullptr);
		tree->value = val;
		tree->left = nullptr;
		tree->right = nullptr;
		tree->count = 1;
	}
	else
	{
		if (tree->value > val)
		{
			tree->left = addNode(tree->left, val);
		}
		else
		{
			if (tree->value < val)
			{
				tree->right = addNode(tree->right, val);
			}
		}
	}

	return tree;
}

inline CNode* CNode::deleteNode(CNode* tree, CNode* node)
{
	return NULL;
}

inline CNode* CNode::min(CNode* tree)
{
	if (tree != nullptr)
	{
		while (tree->left != nullptr)
		{
			tree = tree->left;
		}
	}
	std::cout << "\nMIN: " << tree->value << "\n";
	return tree;
}

inline CNode* CNode::max(CNode* tree)
{
	if (tree != nullptr)
	{
		while (tree->right != nullptr)
		{
			tree = tree->right;
		}
	}
	std::cout << "\nMAX: " << tree->value << "\n";
	return tree;
}

inline void CNode::PrintTree(CNode* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << " ";
		PrintTree(root->right);
		PrintTree(root->left);
	}
}