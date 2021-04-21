#include "CNode.h"
#include <locale>

int main()
{
	setlocale(LC_ALL, "Rus");
	
	char slovar[SizeSlovar] = { ',', '.', '?', '!', ':', '(', ')', ';', '{', '}', '1','2','3','4','5','6','7','8','9','0' };
	std::string in = "шло 20 апреля. я всё ещё не знал программирование.";

	CNode<std::string> c("", nullptr, nullptr);

	c.InputData(in);

	c.PrintTree(&c);
	std::cout << std::endl;

	c.min(&c);
	c.max(&c);

	int count_ = 0;

	c.find(&c, "якрутой", &count_);

	c.deleteNode(&c, "я");

	c.PrintTree(&c);


	system("pause");
	return 0;
}