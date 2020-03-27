//	LR3
//	Dmytro Geleshko
//	Var 2

#include <iostream>
#include <fstream>
#include <string>
#define HSIZE 100000


using namespace std;

class strList
{
	class Node
	{
	public:
		Node* pNext;
		string word;
		string data;
		Node(string word,string data,Node* pNext=nullptr)
		{
			this->word = word;
			this->data = data;
			this->pNext = pNext;
		}

	};
	int lsize;
	Node* head;
public:
	strList()
	{
		lsize = 0;
		head = nullptr;
	}
	~strList() {};
	int getlsize() 
	{
		return lsize;
	};
	void push_back(string word,string data)
	{
		if (head==nullptr)
		{
			head = new Node(word, data);
		}
		else
		{
			Node* current = this->head;
			while (current->pNext!=nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(word, data);
		}
		lsize++;
	}
};

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
	strList a;
	cout<<a.getlsize();
	a.push_back("Hash", "My work");
	cout << a.getlsize();
	a.push_back("look", "at this");
	cout << a.getlsize();
}