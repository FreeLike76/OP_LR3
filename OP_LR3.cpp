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
	strList();
	~strList();
	int getlsize();
	void push_back(string word, string data);
	void pop_front();
	string operator[](const string find);
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
	cout << a["Hash"];
}

strList::strList()
{

	lsize = 0;
	head = nullptr;

}

strList::~strList()
{
}

int strList::getlsize()
{
	return lsize;
}

void strList::push_back(string word, string data)
{


	if (head == nullptr)
	{
		head = new Node(word, data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(word, data);
	}
	lsize++;

}

void strList::pop_front()
{
}

string strList::operator[](const string find)
{
	Node* current = this->head;
	while (current->pNext != nullptr)
	{
		if (current->word == find)
		{
			return current->data;
		}
		current = current->pNext;
	}
	return "Can't find required data! Maybe you misspelled the word or this vocabulary is missing this word. Please try again.\n";
}
