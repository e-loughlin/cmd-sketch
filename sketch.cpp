#include <iostream>
#include <vector>

using namespace std;

void render(int cursorX, int cursorY, vector< vector<int> > drawnCellsMatrix)
{
	for (int y = 0; y < drawnCellsMatrix.size(); y++)
	{
		for(int x = 0; x < drawnCellsMatrix[y].size(); x++)
		{
			if(x == cursorX && y == cursorY)
				cout << "o";
			else if (drawnCellsMatrix[y][x])
				cout << "#";
			else 
				cout << " ";
		}

		cout << "\n";
	}
}


int main()
{
	vector< vector <int> > drawnCellsMatrix;
	int boxHeight = 30;
	int boxWidth = 100;
	int cursorX = 10;
	int cursorY = 10;
	bool drawActivated = false;

	for(int y = 0; y < boxHeight; y++)
	{
		vector<int> newColumn;
		drawnCellsMatrix.push_back(newColumn);
		for(int x = 0; x < boxWidth; x++)
		{
			drawnCellsMatrix[y].push_back(0);
		}
	}

	while(1)
	{
		render(cursorX, cursorY, drawnCellsMatrix);
		char input;
		cin >> input;
		switch(input)
		{
			case 'w':
				cursorY--;
				break;
			case 's':
				cursorY++;
				break;
			case 'd':
				cursorX++;
				break;
			case 'a':
				cursorX--;
				break;
			case ';':
				drawActivated = !drawActivated;
				break;
		}

		if (cursorY < 0)
			cursorY = 0;
		if (cursorX < 0)
			cursorX = 0;
		if (cursorY >= boxHeight)
			cursorY = boxHeight - 1;
		if (cursorX >= boxWidth)
			cursorX = boxWidth - 1;

		if (drawActivated)
			drawnCellsMatrix[cursorY][cursorX] = 1;
	}
}

