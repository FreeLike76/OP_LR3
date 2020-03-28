//	LR3
//	Dmytro Geleshko
//	Var 2

#include <iostream>
#include <fstream>
#include <string>
#define HSIZE 100000
#define VOC_PATH "dict_processed.txt"


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
	string find_for(const string find);
	void clear();
};

int getHash(string a);



int main()
{
	strList Voc[HSIZE];
	readVoc(Voc, VOC_PATH);
	string input;
	do
	{
		cout << "Enter word: ";
		cin >> input;
		cout << Voc[getHash(input)].find_for(input);

	} while (input != "!stop");
}

strList::strList()
{

	lsize = 0;
	head = nullptr;

}

strList::~strList()
{
	clear();
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
		Node* current = head;
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
	if (lsize == 0) { cout << "List is clear, pop_front is excess\n"; }
	else
	{
		Node* current = head;
		head = head->pNext;
		delete current;
		lsize--;
	}
}

string strList::find_for(const string find)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->word == find)
		{
			return current->data;
		}
		current = current->pNext;
	}
	return "Can't find required data! Maybe you misspelled the word or this vocabulary is missing this word. Please try again.\n";
}

void strList::clear()
{
	while (lsize)
	{
		pop_front();
		lsize--;
	}
}

int getHash(string a)
{
	unsigned long hash = 5381;
	int c;

	for (int i = 0; i < a.length(); i++)
	{
		c = a[i];
		hash = ((hash << 5) + hash) + c;
	}
	return hash % HSIZE;
}

void readVoc(strList* Voc, string path)
{
	ifstream voc;
	voc.open(path);
	if (!voc.is_open())
	{
		cout << "Can't open word data file!\n";
	}
	else
	{
		cout << "File is loading, please wait...\n";
		while (!voc.eof())
		{
			string word, data;
			char ch;
			do
			{
				voc.get(ch);
				word += ch;

			} while (ch != ';');
			voc.get(ch);
			do
			{
				voc.get(ch);
				data += ch;

			} while (ch != '\n' && !voc.eof());
			Voc[getHash(word)].push_back(word, data);
		}
		voc.close();
		cout << "File is loaded!\n";
	}
}