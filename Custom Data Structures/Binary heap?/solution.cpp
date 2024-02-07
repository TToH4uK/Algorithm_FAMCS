#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int count = 0;
	fin >> count;

	int* mas = new int[count + 1];

	int num = 0;
	int element = 1;

	while (fin >> num) {
		mas[element++] = num;
	}

	for (element = 1; element < count + 1; element++)
	{
		if (2 * element + 1 <= count)
		{
			if (mas[element] > mas[2 * element] || mas[element] > mas[2 * element + 1])
			{
				fout << "No";
				break;
			}
		}
		else if (2 * element <= count)
			if (mas[element] > mas[2 * element])
			{
				fout << "No";
				break;
			}
	}
	if (element == count + 1) {
		fout << "Yes";
	}

	delete[] mas;

	fin.close();
	fout.close();

	return 0;
}
