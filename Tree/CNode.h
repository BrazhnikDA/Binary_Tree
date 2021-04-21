#pragma once
#include <string>
#include <iostream>

class CNode
{
private:
	int count;				// Сколько раз встречается данное значение
	std::string value;		// Элемент
	CNode* left, * right;	// Указатели на лево и право в дереве
public:
	CNode(std::string val, CNode* l, CNode* r);		// Конструктор с параметрами

	CNode* addNode(CNode* tree, std::string val);	// Добавление звена

	void deleteNode(CNode* tree, std::string node);	// Удаление звена
	void deleteSubTree(CNode* subTreee);			// Удаление ветки

	CNode* min(CNode* tree);						// Поиск минимума 
	CNode* max(CNode* tree);						// Поиск максимума

	CNode* find(CNode* start, std::string findVal, int* count);	// Поиск элемента в дереве

	bool isBinaryTree(CNode* tree);					// Проверка является ли это дерево бинарным 
	bool check(CNode* node, int min, int max);

	void PrintTree(CNode* root);					// Вывести дерево в консоль с слева на право 
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
		if (val == tree->value)
		{
			tree->count++;
		}
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

inline void CNode::deleteNode(CNode* tree, std::string node)
{
	CNode* tmp;
	if (tree != nullptr)
	{
		if (tree->value > node)
		{
			while (tree->left != nullptr)
			{
				tmp = tree;
				tree = tree->left;
				if (tree->value == node)
				{
					tree = tmp;
					delete tree->left;
					if (tree->left->left != nullptr)
					{
						tree->left = tree->left->left;
						return;
					}
					else
					{
						// Если удалили последний элемент в дереве
						tree->left = nullptr;
						return;
					}
				}
			}
		}
		else
		{
			if (tree->value < node)
			{
				while (tree->right != nullptr)
				{
					tmp = tree;
					tree = tree->right;
					if (tree->value == node)
					{
						tree = tmp;
						delete tree->right;
						if (tree->right->right != nullptr)
						{
							tree->right = tree->right->right;
							return;
						}
						else
						{
							// Если удалили последний элемент в дереве
							tree->right = nullptr;
							return;
						}
					}
				}
			}
		}
	}
}

inline void CNode::deleteSubTree(CNode* start)
{
	if (start != nullptr)
	{
		deleteSubTree(start->left);
		deleteSubTree(start->right);
		delete start;
	}
}

inline CNode* CNode::min(CNode* tree)
{
	std::string res;
	if (tree != nullptr)
	{
		if (tree->left == nullptr)
		{
			res = tree->value;
		}
		while (tree->left != nullptr)
		{
			res = tree->value;
			tree = tree->left;
		}
	}
	std::cout << "MIN: " << res << "\n";
	return tree;
}

inline CNode* CNode::max(CNode* tree)
{
	std::string res;
	if (tree != nullptr)
	{
		if (tree->right == nullptr)
		{
			res = tree->value;
		}
		while (tree->right != nullptr)
		{
			tree = tree->right;
			res = tree->value;
		}
	}
	std::cout << "MAX: " << res << "\n";
	return tree;
}

inline CNode* CNode::find(CNode* start, std::string findVal, int* count)
{
	if (start != nullptr)
	{
		if (findVal == start->value) 
		{ 
			*count = (*count) + start->count;
			std::cout << "Slovo: '" << findVal << "' Find: " << *count << " raz" << "\n"; 
		}
		find(start->right, findVal, count);
		find(start->left, findVal, count);
	}
	return start; 
}

inline bool CNode::isBinaryTree(CNode* tree)
{
	return check(tree, 0, 0);
}

inline bool CNode::check(CNode* node, int min, int max)
{
	return false;
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