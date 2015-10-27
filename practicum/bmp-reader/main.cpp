#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream img("test.bmp");
	char* size = new char[4];
	char* width = new char[4];
	char* height = new char[4];

	img.seekg(2 * sizeof(char), img.cur);
	// bfSize
	img.read(size, 4 * sizeof(char));

	img.seekg(12 * sizeof(char), img.cur);
	// biWidth
	img.read(width, 4 * sizeof(char));
	// biHeight
	img.read(height, 4 * sizeof(char));

	cout << *((int*)size) << endl;
	cout << *((int*)width) << endl;
	cout << *((int*)height) << endl;

	img.close();

	return 0;
}
