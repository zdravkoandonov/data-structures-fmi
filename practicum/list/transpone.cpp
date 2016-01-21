#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<list<int> > matrix;
	list<int> temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.push_back(rand() % 10);
		}
		matrix.push_back(temp);
		temp = list<int>();
	}

	list<list<int> > transposedMatrix;
	for (int i = 0; i < matrix.size(); i++)
	{
		transposedMatrix.push_back(list<int>());
	}
	list<list<int> >::iterator iter0 = matrix.begin();
	list<int>::iterator iter1 = iter0->begin();
	list<list<int> >::iterator iter2 = transposedMatrix.begin();
	while (iter2 != transposedMatrix.end())
	{
		while (iter1 != iter0->end())
		{
			iter2->push_back(*iter1);
			iter1++;
			iter2++;
		}
		iter0 = matrix.begin();
		iter1 = iter0->begin();
		iter2 = transposedMatrix.begin();
	}

	return 0;
}