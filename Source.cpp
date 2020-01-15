#include <iostream>
using namespace std;
struct Tree
{
	int key;
	Tree* leftElem;
	Tree* rightElem;
	Tree* prevElem;
	Tree(int key, Tree* left = nullptr, Tree* previos = nullptr, Tree* right = nullptr)
	{
		this->key = key;
		this->leftElem = left;
		this->rightElem = right;
		this->prevElem = previos;
	}
};
class List
{
private:
	Tree* head;
	void print_all(Tree* current)
	{
		if (current != nullptr)
		{
			cout << current->key << endl;
			print_all(current->leftElem);
			print_all(current->rightElem);
		}
	}
public:
	List()
	{
		head = nullptr;
	}
	~List()
	{
		remove_all();
	}
	void add(int key)
	{
		Tree* newElem = new Tree(key);
		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Tree* current = head;
			while (current != nullptr)
			{
			    if (key < current->key)
				{
					if (current->leftElem != nullptr)
					{
						current = current->leftElem;
					}
					else
					{
						break;
					}
				}
				else
				{
					if (current->rightElem != nullptr)
					{
						current = current->rightElem;
					}
					else
					{
						break;
					}
				}
			}
			if (current->key != newElem->key)
			{
				newElem->prevElem = current;
				newElem->leftElem = nullptr;
				newElem->rightElem = nullptr;
				if (key < current->key)
				{
					current->leftElem = newElem;
				}
				else
				{
					current->rightElem = newElem;
				}
			}
			else
			{
				delete newElem;
			}
		}
	}
	void remove(int key)
	{
		Tree* current = head;
		if (head != nullptr)
		{
			if (key != head->key)
			{
				while (current->key != key)
				{
					if (key > current->key)
					{
						if (current->rightElem != nullptr)
						{
							current = current->rightElem;
						}
						else
						{
							cout << "Element isn`t found" << endl;
							return;
						}
					}
					else
					{
						if (current->leftElem != nullptr)
						{
							current = current->leftElem;
						}
						else
						{
							cout << "Element isn`t found" << endl;
							return;
						}
					}
				}
				Tree* Del = current;

				if (current->rightElem != nullptr && current->leftElem != nullptr)
				{
					current = current->leftElem;
					if (current->rightElem != nullptr)
					{
						while (current->rightElem != nullptr)
						{
							current = current->rightElem;
						}
						if (current->leftElem != nullptr)
						{
							current->leftElem->prevElem = current->prevElem;
							current->prevElem->rightElem = current->leftElem;
						}
						else
						{
							current->prevElem->rightElem = nullptr;
						}
						current->rightElem = Del->rightElem;
						current->leftElem = Del->leftElem;
						current->prevElem = Del->prevElem;
						current->rightElem->prevElem = current;
						current->leftElem->prevElem = current;
						if (current->key > Del->prevElem->key)
						{
							Del->prevElem->rightElem = current;

						}
						else if (current->key < Del->prevElem->key)
						{
							Del->prevElem->leftElem = current;
						}
						delete Del;

					}
					else
					{
						current->rightElem = Del->rightElem;
						current->prevElem = Del->prevElem;
						current->rightElem->prevElem = current;
						if (current->key > Del->prevElem->key)
						{
							Del->prevElem->rightElem = current;

						}
						else if (current->key < Del->prevElem->key)
						{
							Del->prevElem->leftElem = current;
						}
						delete Del;
					}

				}
				else if (current->rightElem == nullptr && current->leftElem == nullptr)
				{
					if (current->prevElem->key < Del->key)
					{
						current->prevElem->rightElem = nullptr;
					}
					else
					{
						current->prevElem->leftElem = nullptr;
					}
					delete Del;
				}
				else if (current->rightElem != nullptr && current->leftElem == nullptr)
				{
					current = current->rightElem;
					current->prevElem = Del->prevElem;
					if (current->key > Del->prevElem->key)
					{
						Del->prevElem->rightElem = current;

					}
					else if (current->key < Del->prevElem->key)
					{
						Del->prevElem->leftElem = current;
					}
					delete Del;
				}
				else if (current->rightElem == nullptr && current->leftElem != nullptr)
				{
					current = current->leftElem;
					current->prevElem = Del->prevElem;
					if (current->key > Del->prevElem->key)
					{
						Del->prevElem->rightElem = current;

					}
					else if (current->key < Del->prevElem->key)
					{
						Del->prevElem->leftElem = current;
					}
					delete  Del;
				}
			}
			else
			{
				if (current->leftElem == nullptr && current->rightElem == nullptr)
				{
					delete current;
				}
				else if (current->leftElem != nullptr && current->rightElem != nullptr)
				{
					head = head->leftElem;
					if (head->rightElem != nullptr)
					{
						while (head->rightElem != nullptr)
						{
							head = head->rightElem;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head->prevElem;
							head->prevElem->rightElem = head->leftElem;
						}
						else
						{
							head->prevElem->rightElem = nullptr;
						}
						head->rightElem = current->rightElem;
						head->leftElem = current->leftElem;
						head->prevElem = nullptr;
						if (head->rightElem != nullptr)
						{
							head->rightElem->prevElem = head;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head;
						}
						delete current;
					}
					else
					{
						head->rightElem = current->rightElem;
						head->prevElem = nullptr;
						if (head->rightElem != nullptr)
						{
							head->rightElem->prevElem = head;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head;
						}
						delete current;
					}
				}
				else if (current->rightElem != nullptr && current->leftElem == nullptr)
				{
					head = head->rightElem;
					head->prevElem = nullptr;
					delete current;
				}
				else if (current->rightElem == nullptr && current->leftElem != nullptr)
				{
					head = head->leftElem;
					head->prevElem = nullptr;
					delete current;
				}
			}
		}
		else
		{
			cout << "Element isn`t found" << endl;
		}
	}
	void find(int key)
	{
		Tree* current = head;
		if (head == nullptr)
		{
			cout << "Element isn`t found" << endl;
		}
		else
		{
			while (current != nullptr)
			{
				if (key == current->key)
				{
					break;
				}
				else if (key > current->key)
				{
					if (current->rightElem != nullptr)
					{
						current = current->rightElem;
					}
					else
					{
						cout << "Element isn`t found" << endl;
						break;
					}
				}
				else if (key < current->key)
				{
					if (current->leftElem != nullptr)
					{
						current = current->leftElem;
					}
					else
					{
						cout << "Element isn`t found" << endl;
						break;
					}
				}
			}
		}
	}
	void remove_all()
	{
		if (head != nullptr)
		{
			while (head != nullptr)
			{
				Tree* current = head;
				if (head->leftElem == nullptr && head->rightElem == nullptr)
				{
					delete head;
					head = nullptr;
				}
				else if (current->leftElem != nullptr && current->rightElem != nullptr)
				{
					head = head->leftElem;
					if (head->rightElem != nullptr)
					{
						while (head->rightElem != nullptr)
						{
							head = head->rightElem;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head->prevElem;
							head->prevElem->rightElem = head->leftElem;
						}
						else
						{
							head->prevElem->rightElem = nullptr;
						}
						head->rightElem = current->rightElem;
						head->leftElem = current->leftElem;
						head->prevElem = nullptr;
						if (head->rightElem != nullptr)
						{
							head->rightElem->prevElem = head;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head;
						}
						delete current;
					}
					else
					{
						head->rightElem = current->rightElem;
						head->prevElem = nullptr;
						if (head->rightElem != nullptr)
						{
							head->rightElem->prevElem = head;
						}
						if (head->leftElem != nullptr)
						{
							head->leftElem->prevElem = head;
						}
						delete current;
					}
				}
				else if (current->rightElem != nullptr && current->leftElem == nullptr)
				{
					head = head->rightElem;
					head->prevElem = nullptr;
					delete current;
				}
				else if (current->rightElem == nullptr && current->leftElem != nullptr)
				{
					head = head->leftElem;
					head->prevElem = nullptr;
					delete current;
				}
			}
		}
		else
		{
			cout << "Tree is empty" << endl;
		}
	}
	void print_all()
	{
		Tree* current = head;
		print_all(current);
	}
};


void test1()
{
	List tr;
	tr.add(20);
	tr.add(10);
	tr.add(5);
	tr.add(3);
	tr.add(7);
	tr.add(15);
	tr.add(13);
	tr.add(17);
	tr.add(30);
	tr.add(25);

	tr.remove(10);
	tr.print_all();
}

int main()
{
	test1();
	return 0;
}