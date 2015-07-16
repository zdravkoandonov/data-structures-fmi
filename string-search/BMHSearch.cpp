#include "BMHSearch.h"
#include <iostream>

int BMHSearch::search(char *needle, int needleLength, char *haystack, int haystackLength)
{
	int operationsCount = 0;

	// preprocess
	int skipLengths[256];
	for (int i = 0; i < 256; i++)
	{
		skipLengths[i] = needleLength;
	}
	for (int i = 0; i < needleLength; i++)
	{
		skipLengths[needle[i]] = needleLength - i - 1;
	}

	// search
	int i = 0, matchedSymbolsCount = 0;
	while (i < haystackLength - needleLength + 1)
	{
		for (int j = needleLength - 1; j >= 0; j--)
		{
			operationsCount++;
			if (haystack[i+j] == needle[j])
			{
				matchedSymbolsCount++;
				if (matchedSymbolsCount == needleLength)
				{
					std::cout << "BMH search - operations count - " << operationsCount << std::endl;
					return i;
				}
			}
			else
			{
				matchedSymbolsCount = 0;
				i += skipLengths[haystack[i+j]];
				break;
			}
		}
	}

	std::cout << "BMH search - operations count - " << operationsCount << std::endl;
	return -1;
}