#include "CNode.h"
#include <locale>

#define SizeSlovar 20

int main()
{
	setlocale(LC_ALL, "Rus");
	
	char slovar[SizeSlovar] = { ',', '.', '?', '!', ':', '(', ')', ';', '{', '}', '1','2','3','4','5','6','7','8','9','0' };
	std::string in = "кто будет будет будет зиж ава ооповезло тебе якрутой якрутой якрутой";//"шло 20 апреля. абоба всё ещё не знал программирование. шло ава, не, ура, не, шло";

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

	CNode c(res[0], nullptr, nullptr);
	for (int i = 1; i < count + 1; i++)
	{
		c.addNode(&c, res[i]);
	}

	c.PrintTree(&c);
	std::cout << std::endl;

	c.min(&c);
	c.max(&c);

	int count_ = 0;

	c.find(&c, "якрутой", &count_);

	c.deleteNode(&c, "ава");


	system("pause");
	return 0;
}