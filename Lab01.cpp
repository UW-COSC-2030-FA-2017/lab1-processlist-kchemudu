//Krishna Sai Chemudupati
//COSO 2030
//9/11/2017
// Lab 01

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;
	string numbers;
	int counter = 0;
	int finalCount;
	string n1, n2, n3, n4;
	cout << "Enter a file name: ";
	cin >> filename;
	ifstream myfile(filename);
	if (myfile.is_open())
	{

		while (!myfile.eof())
		{
			if (myfile.fail())
			{
				myfile.ignore();
				myfile.clear();
			}
			else
			{
				counter++;
				myfile >> numbers;
				if (counter == 1)
				{
					n1 = numbers;
				}
				else if (counter == 2)
				{
					n2 = numbers;
				}
			}
		}
		finalCount = counter;
		counter = 0;
		myfile.close();
		myfile.open(filename);
		while (!myfile.eof())
		{
			if (myfile.fail())
			{
				myfile.ignore();
				myfile.clear();
			}
			else
			{
				counter++;
				myfile >> numbers;
				if (counter == (finalCount - 1))
				{
					n3 = numbers;
				}
				else if (counter == finalCount)
				{
					n4 = numbers;
				}
			}
		}
	}
	else
	{
		cout << "Error! Cannot open the file. Please check the file name." << endl;
	}
	cout << "The total number of numbers in the file are: " << finalCount << endl;
	cout << "The first two numbers are: " << n1 << ", " << n2 << endl;
	cout << "The last two numbers are: " << n3 << ", " << n4 << endl;
	return 0;
}
