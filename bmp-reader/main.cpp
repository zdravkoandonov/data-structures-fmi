#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream img("test.bmp");
	char* size = new char[4];
	char* width = new char[4];
	char* height = new char[4];
	char* readSkipper = new char[100];
	img.read(readSkipper, 2 * sizeof(char));
	img.read(size, 4 * sizeof(char));
	img.read(readSkipper, 8 * sizeof(char));
	img.read(readSkipper, 4 * sizeof(char));
	img.read(width, 4 * sizeof(char));
	img.read(height, 4 * sizeof(char));

	cout << *((int*)size) << endl;
	cout << *((int*)width) << endl;
	cout << *((int*)height) << endl;

	img.close();

	return 0;
}
