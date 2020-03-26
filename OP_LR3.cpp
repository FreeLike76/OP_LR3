//	LR3
//	Dmytro Geleshko
//	Var 2

#include <iostream>
#include <fstream>
#include <string>
#define HSIZE 200000


using namespace std;

int getHash(string a)
{
	unsigned long hash = 5381;
	int c;

	for (int i = 0; i < a.length(); i++)
	{
		c = a[i];
		hash = ((hash << 5) + hash) + c;
	}
	return hash%HSIZE;
}

int main()
{
	string name;
	do
	{
		cin >> name;
		cout << getHash(name)<<endl;
		
	} while (name != "quit");
	int* arr = new int[HSIZE];
	cin >> name;
	delete[] arr;
}