#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<char> braces;
	string str;

	cin >> str;

	int i = 0;
	while (i < str.size())
	{
		if (str[i] == '(')
			braces.push_back('(');
		if (str[i] == ')')
			if (braces.size() > 0)
				braces.pop_back();
			else
			{
				cout << "Nope!" << endl;
				return 0;
			}
		i++;
	}

	if (braces.size() > 0)
		cout << "Nope!" << endl;
	else
		cout << "Great!" << endl;

	return 0;
}