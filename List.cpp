#include <iostream>
#include <string>


using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data); //äîáàâëåíèå â êîíåö
	void push_front(T data); //äîáàâëåíèå â íà÷àëî
	void insert(T value, int index); //äîáàâèòü ýëåìåíò ïîä èíäåêñîì
	void pop_front(); //óäàëåíèå ïåðâîãî ýëåìåíòà
	void pop_back(); //óäàëåíèå ïîñëåäíåãî ýëåìåíòà
	void remove(int index); //óäàëåíèå êîíêðåòíîãî ýëåìåíòà
	void clear(); //óäàëåíèå âñåãî âïèñêà
	void print(int index); //âûâîä ýëåìåíòîâ

	int Getsize() { return size; }

	T& operator[](const int index);
private:
	template <typename T>
	class Elem
	{

	public:
		Elem *nextElem;
		T data;
	    Elem(T data=T(), Elem* nextElem = nullptr)
		{
			this->data = data;
			this->nextElem = nextElem;
		}
	};
	int size;

	Elem<T> *head;
};


template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Elem<T> *temp = head;
	head = head->nextElem;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pop_back()
{
	remove(size - 1);
}

template<typename T>
void List<T>::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Elem<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->nextElem;
		}
		Elem<T>* Delete = previous->nextElem;
		previous->nextElem = Delete->nextElem;
		delete Delete;
		size--;
	}
}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Elem<T>(data);
	}
	else
	{
		Elem<T>* current = this->head;
		while (current->nextElem != nullptr)
		{
			current = current->nextElem;
		}
		current->nextElem = new Elem<T>(data);
	}

	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Elem<T>(data, head);
	size++;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::print(int index)
{
	List<int> lst;
	if (size == 0)
		cout << "There is no elements"<<endl;
	else
	{
		cout << "Amount of elements: " << size << endl << "Elements: " << endl;
		for (int i = 0; i < index; i++)
			cout << lst[i] << endl;
	}
}


template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Elem<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->nextElem;
		}
		Elem<T> *newElem = new Elem<T>(value, previous->nextElem);
		previous->nextElem = newElem;
		size++;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Elem<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->nextElem;
		counter++;
	}
}



int main()
{
	List<int> lst;

	int number;
	cin >> number;

	for (int i = 0; i < number; i++)
	{
		lst.push_back(rand() % 10);
	}

	lst.insert(99, 3);

	for (int i = 0; i < lst.Getsize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl;
	
	lst.remove(5);

	for (int i = 0; i < lst.Getsize(); i++)
	{
		cout << lst[i] << endl;
	}

	
	return 0;
}
