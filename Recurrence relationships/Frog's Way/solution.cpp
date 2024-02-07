#include <iostream>
#include <set>

using namespace std;

int main()
{
	int numb;
	cin >> numb;

	int* mas = new int[numb+1];
	set<int> index;

	for (int i = 1; i < numb+1; i++) {
		cin >> mas[i];
	}

	if (numb == 1)
	{
		cout << mas[1] << endl;
		cout << "1";
		return 0;
	}
	else if (numb == 2)
	{
		cout << -1;
		return 0;
	}
	else if (numb == 3) {
		cout << mas[1] + mas[3] << endl;
		index.insert(1);
		index.insert(3);
		for (int a : index) {
			cout << a << " ";
		}
		return 0;
	}
	else if (numb == 4) {
		cout << mas[1] + mas[4] << endl;
		index.insert(1);
		index.insert(4);
		for (int a : index) {
			cout << a <<" ";
		}
		return 0;
	}
	else if (numb == 5) {
		cout << mas[1] + mas[3] + mas[5] << endl;
		index.insert(1);
		index.insert(3);
		index.insert(5);
		for (int a : index) {
			cout << a << " ";
		}
		return 0;
	}
	else {
		int* ma = new int[numb + 1];
		ma[1] = mas[1];
		ma[3] = mas[1] + mas[3];
		ma[4] = mas[1] + mas[4];
		ma[5] = mas[1] + mas[3] + mas[5];
		for (int i = 6; i <= numb; i++) {
			if (ma[i - 2] > ma[i - 3]) {
				ma[i] = mas[i] + ma[i - 2];
				
			}
			else {
				ma[i] = mas[i] + ma[i -3];
			}

		}
		int n = numb;
		index.insert(n);

		while (n != 0) {
			if (n == 3) {
				index.insert(3);
				index.insert(1);
				break;
			}
			else if (n == 4) {
				index.insert(4);
				index.insert(1);
				break;
			}
			else if (n == 5) {
				index.insert(5);
				index.insert(3);
				index.insert(1);
				break;
			}
			else {
				if (ma[n - 2] > ma[n - 3]) {
					index.insert(n - 2);
					n = n - 2;

				}
				else {
					index.insert(n - 3);
					n = n - 3;
				}
			}
		}
		cout << ma[numb];
		cout << endl;
		for (int a : index) {
			cout << a << " ";
		}

		return 0;
	}
}
