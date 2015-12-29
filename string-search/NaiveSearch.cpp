#include "NaiveSearch.h"
#include <iostream>

int NaiveSearch::search(char *needle, int needleLength, char *haystack, int haystackLength)
{
	int operationsCount = 0;

	int matchedSymbolsCount = 0;
	for (int i = 0; i < haystackLength - needleLength + 1; i++)
	{
		for (int j = 0; j < needleLength; j++)
		{
			operationsCount++;
			if (haystack[i+j] == needle[j])
			{
				matchedSymbolsCount++;
				if (matchedSymbolsCount == needleLength)
				{
					std::cout << "Naive search - operations count - " << operationsCount << std::endl;
					return i;
				}
			}
			else
			{
				matchedSymbolsCount = 0;
				break;
			}
		}
	}

	std::cout << "Naive search - operations count - " << operationsCount << std::endl;
	return -1;
}