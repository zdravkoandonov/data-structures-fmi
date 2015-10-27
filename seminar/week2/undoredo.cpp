#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#define SIZE 10

struct Coords
{
	int x, y;
};

void clear()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "\n";
	}
}

void apply(int map[SIZE][SIZE], vector<Coords> commands)
{
	int count = commands.size();
	for (int i = 0; i < count; i++)
	{
		map[commands[i].x][commands[i].y] = 1;
	}
}

void print(int map[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	Coords currentCoords;
	vector<Coords> commands, undoedCommands;
	int map[SIZE][SIZE] = { 0 };
	while (cin >> currentCoords.x >> currentCoords.y)
	{
		clear();
		commands.push_back(currentCoords);
		int undoRedoRand = rand() % 5;
		if (undoRedoRand == 1)
		{
			cout << "UNDO!" << endl;
			if (commands.size() > 0)
			{
				undoedCommands.push_back(commands.back());
				commands.pop_back();
			}
		}
		else if (undoRedoRand > 1)
		{
			cout << "REDO!" << endl;
			if (undoedCommands.size() > 0)
			{
				commands.push_back(undoedCommands.back());
				undoedCommands.pop_back();
			}
		}
		apply(map, commands);
		print(map);
	}

	return 0;
}