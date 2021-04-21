#pragma once
#include <string>
#include <iostream>

#define SizeSlovar 20

template<typename T>
class CNode
{
private:
	int count;				// Сколько раз встречается данное значение
	T value;				// Элемент
	CNode* left, * right;	// Указатели на лево и право в дереве
public:
	CNode(T val, CNode* l, CNode* r);		// Конструктор с параметрами

	CNode* InputData(std::string val);		// Разбор строки на звенья
	CNode* InputData(int* val);
	CNode* InputData(double* val);
	CNode* InputData(bool* val);

	CNode* addNode(CNode* tree, T val);		// Добавление звена

	void deleteNode(CNode* tree, T node);	// Удаление звена
	void deleteSubTree(CNode* subTreee);	// Удаление ветки

	CNode* min(CNode* tree);				// Поиск минимума 
	CNode* max(CNode* tree);				// Поиск максимума

	CNode* find(CNode* start, T findVal, int* count);	// Поиск элемента в дереве

	bool isBinaryTree(CNode* tree);						// Проверка является ли это дерево бинарным 
	bool check(CNode* node, int min, int max);			// Реализация проверки

	void PrintTree(CNode* root);						// Вывести дерево в консоль с слева на право 
};

template<typename T>
inline CNode<T>::CNode(T val, CNode* l, CNode* r)
{
	value = val;
	left = l;
	right = r;
	count = 1;
}

template<typename T>
inline CNode<T>* CNode<T>::InputData(std::string in)
{
	char slovar[SizeSlovar] = { ',', '.', '?', '!', ':', '(', ')', ';', '{', '}', '1','2','3','4','5','6','7','8','9','0' };

	int count = 0;
	int countNum = 0;
	std::string res[100];

	bool IsGood = true;
	for (int i = 0; i < in.size(); i++)
	{
		IsGood = true;
		if (in[i] == ' ') { count++; continue; }
		for (int j = 0; j < SizeSlovar; j++)
		{
			if (in[i] == slovar[j])
			{
				if (j > 10 && countNum < 1) { count--; countNum++; }
				IsGood = false;
				break;
			}
		}
		if (IsGood)
		{
			countNum = 0;
			res[count] += in[i];
		}
	}

	CNode<std::string> c(res[0], nullptr, nullptr);
	for (int i = 1; i < count + 1; i++)
	{
		c.addNode(&c, res[i]);
	}
	c.PrintTree(&c);

	*this = c;

	return &c;
	
}

template<typename T>
inline CNode<T>* CNode<T>::addNode(CNode<T>* tree, T val)
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

template<typename T>
inline void CNode<T>::deleteNode(CNode<T>* tree, T node)
{
	CNode<T>* tmp;
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
					if (tree->left->left == nullptr)
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
						if (tree->right->right == nullptr)
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

template<typename T>
inline void CNode<T>::deleteSubTree(CNode<T>* start)
{
	if (start != nullptr)
	{
		deleteSubTree(start->left);
		deleteSubTree(start->right);
		delete start;
	}
}

template<typename T>
inline CNode<T>* CNode<T>::min(CNode<T>* tree)
{
	T res;
	if (tree != nullptr)
	{
		if (tree->left == nullptr)
		{
			res = tree->value;
		}
		while (tree->left != nullptr)
		{
			tree = tree->left;
			res = tree->value;
		}
	}
	std::cout << "MIN: " << res << "\n";
	return tree;
}

template<typename T>
inline CNode<T>* CNode<T>::max(CNode<T>* tree)
{
	T res;
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

template<typename T>
inline CNode<T>* CNode<T>::find(CNode<T>* start, T findVal, int* count)
{
	if (start != nullptr)
	{
		if (findVal == start->value) 
		{ 
			*count = (*count) + start->count;
			std::cout << "Slovo: '" << findVal << "' Find: " << *count << " raz" << "\n";
			return start;
		}
		find(start->right, findVal, count);
		find(start->left, findVal, count);
	}
	return start; 
}

template<typename T>
inline bool CNode<T>::isBinaryTree(CNode<T>* tree)
{
	return check(tree, 0, 0);
}

template<typename T>
inline bool CNode<T>::check(CNode<T>* node, int min, int max)
{
	return false;
}

template<typename T>
inline void CNode<T>::PrintTree(CNode<T>* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << " ";
		PrintTree(root->right);
		PrintTree(root->left);
	}
}