#pragma once
#include <string>

class CNode
{
private:
	int count;
	std::string value;
	CNode* left, * right;
};