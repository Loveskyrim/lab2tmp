#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/** \func int main(int argc, char* argv[]) */
int main(int argc, char* argv[])
{
	if (argc != 2) return 0;
	ifstream f1(argv[1]);
	if (!f1) return 0;
	string s1;
	size_t pos1, pos2;
	bool flag = false;
	while (!f1.eof())
	{
		getline(f1, s1);
		if (s1.find("/**") != string::npos || flag)
		{
			pos1 = s1.find("\\func");
			if (pos1 != string::npos)
			{
				pos2 = s1.find("*/");
				if (pos2 != string::npos)
				{
					cout << s1.substr(pos1 + strlen("\\func") + 1, pos2 - pos1 - strlen("\\func") - 2)  << endl;
				}
				else if (flag && s1[pos1 + strlen("\\func") + 1] == ' ')
				{
					cout << s1.substr(pos1 + strlen("\\func") + 1) << endl;
					flag = false;
				}
			}
			else
				flag = true;
		}
	}
	system("pause");
	return 0;
}