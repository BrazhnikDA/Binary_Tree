#include "CNode.h"
#include <locale>

#define SizeArr 8

void CreateExample(CNode<std::string> str);
void CreateExample(CNode<int> num);
void CreateExample(CNode<double> num);

int main()
{
	setlocale(LC_ALL, "Rus");

	std::cout << "Char: \n";
	char tmp[5] = { '1','2', 'd', 'd','f' };
	CNode<char> ch(tmp[0], nullptr, nullptr);
	
	ch.addNode(&ch, tmp[0]);
	ch.addNode(&ch, tmp[1]);
	ch.addNode(&ch, tmp[2]);
	ch.addNode(&ch, tmp[3]);
	ch.addNode(&ch, tmp[4]);
	
	ch.PrintTree(&ch);
	
	ch.min(&ch);
	ch.max(&ch);
	std::cout << std::endl << std::endl;

	CNode<std::string> str;
	CNode<int>		   num;
	CNode<double>	   dbl;

	std::cout << "String: \n";
	CreateExample(str);
	std::cout << std::endl << std::endl << "Int: \n";
	CreateExample(num);
	std::cout << std::endl << std::endl << "Double: \n";
	CreateExample(dbl);

	system("pause");
	return 0;
}

void CreateExample(CNode<std::string> str)
{
	std::string in = "шло 20 апреля. я всё ещё не знал программирование.";

	str.InputData(in);

	str.PrintTree(&str);
	std::cout << std::endl;

	str.min(&str);
	str.max(&str);

	int count_ = 0;

	str.find(&str, "я", &count_);

	str.deleteNode(&str, "я");

	str.PrintTree(&str);
}

void CreateExample(CNode<int> num)
{
	int val[SizeArr];

	srand(time(NULL));
	for (int i = 0; i < SizeArr; i++)
		val[i] = 0 + rand() % 20;

	num.InputData(val, SizeArr);
	num.PrintTree(&num);

	std::cout << std::endl;
	num.min(&num);
	num.max(&num);
}

void CreateExample(CNode<double> num)
{
	double val[SizeArr];

	srand(time(NULL));
	for (int i = 0; i < SizeArr; i++)
		val[i] = (double)(rand() % (300) + (0)) / 10;
	;

	num.InputData(val, SizeArr);
	num.PrintTree(&num);

	std::cout << std::endl;
	num.min(&num);
	num.max(&num);
}
