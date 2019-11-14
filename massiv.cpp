#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void st()
{
	fstream f;
	f.open("123.txt", ios::app);
	f << "STATICHESKIY" << endl;
	cout << "massiv 1"<<endl;
	f << "masiiv 1" << endl;
	int arr1[2][3] = { {1,2,3},{1,2,3} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr1[i][j];
			f << arr1[i][j];
		}
		cout << endl;
		f << endl;
	}

	cout << "massiv 2"<<endl;
	f << "massiv 2" << endl;
	int arr2[3][2] = { {1,2},{1,2},{1,2} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr2[i][j];
			f << arr2[i][j];
		}
		cout << endl;
		f << endl;
	}

	cout << "rezul`tat"<<endl;
	f << "rezul`tat" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int s = 0;
			for (int k = 0; k < 2; k++)
			{
				s += arr1[k][i] * arr2[j][k];
			}
			cout << s << " ";
			f << s << " ";
		}
		cout << "\n";
		f << "\n";
	}
	f << "******************************************************************" << endl;
}

void dn()
{
	fstream f;
	f.open("123.txt", ios::app);
	f << "DINAMICHESKIY"<<endl;
	{
		cout << "vvodim razmeri\n";
		int x, y, z, s;
		cin >> x >> y >> z;
		int** a = new int* [x];
		for (int i = 0; i < x; i++)
			a[i] = new int[y];
		int** b = new int* [z];
		for (int i = 0; i < z; i++)
			b[i] = new int[x];
		cout << "vvodim elementi\n";
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				cin >> a[i][j];

		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < x; j++)
				cin >> b[i][j];

		}
		cout << "vivodim elementi\n";
		f << "massiv 1\n";

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cout << a[i][j] << " ";
				f << a[i][j] << " ";
			}
			cout << "\n";
			f << "\n";
		}

		f << "massiv 2\n";

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << b[i][j] << " ";
				f << b[i][j] << " ";
			}
			cout << "\n";
			f << "\n";
		}

		cout << "vivodim res\n";
		f << "vivodim res\n";

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < z; j++)
			{
				s = 0;
				for (int k = 0; k < x; k++)
				{
					s += a[k][j] * b[i][k];
				}
				cout << s << " ";
				f << s << " ";
			}
			cout << "\n";
			f << "\n";
		}
	}
	f << "******************************************************************" << endl;
}

void vk()
{
	fstream f;
	f.open("123.txt", ios::app);
	f << "VEKTORNIY"<<endl;
	int m, n, l;
	cout << "vvedite razmer massiva" << endl;
	cin >> n >> m >> l;
	cout << "vvedite znacheniya 1 massiva" << endl;
	vector < vector <int> > a(n, vector <int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cout << "vivodim elementi\n";
	f << "massiv 1\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j]<<" ";
			f << a[i][j] << " ";
		}
		cout << endl;
		f << endl;
	}

	cout << endl;
	cout << "vvedite znacheniya 2 massiva" << endl;
	vector < vector <int> > b(l, vector <int>(n));
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}

	cout << "vivodim elementi\n";
	f << "massiv 2\n";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j]<<" ";
			f << b[i][j] << " ";
		}
		cout << endl;
		f << endl;
	}

	cout << "vivodim res\n";
	f << "vivodim res\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			int s = 0;
			for (int k = 0; k < n; k++)
			{
				s += a[k][j] * b[i][k];
			}
			cout << s << " ";
			f << s << " ";
		}
		cout << "\n";
		f << "\n";
	}
	f << "******************************************************************";
}

int main() {
	fstream f;
	f.open("123.txt", ios::app);
	while (1)
	{
		cout << "1 - staticheskii massiv" << endl;
		cout << "2 - dinamicheskii massiv" << endl;
		cout << "3 - vektornii massiv" << endl;
		cout << "4 - exit" << endl;

		char s;
		cin >> s;
		switch (s)
		{
		case '1':
		{
			st();
			break;
		}
		case '2':
		{
			dn();
			break;
		}

		case '3':
		{
			vk();
			break;
		}
		case '4':
		{
			return 0;
		}
		}
	}
}
