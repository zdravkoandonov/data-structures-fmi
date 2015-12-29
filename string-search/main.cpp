#include <iostream>
#include "NaiveSearch.h"
#include "BMHSearch.h"
#include "SuffixTree.h"

using namespace std;

int main()
{
	/*char needle[1000], haystack[1000];
	cin >> needle >> haystack;
	
	cout << NaiveSearch::search(needle, strlen(needle), haystack, strlen(haystack)) << endl;
	cout << BMHSearch::search(needle, strlen(needle), haystack, strlen(haystack)) << endl;*/

	char *word = "What";

	SuffixTree t = SuffixTree(word, 4);
	t.print();

	cin.ignore();
	cin.clear();
	cin.get();

	return 0;
}