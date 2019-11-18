#include <iostream>
#include <string>


using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data); //добавление в конец
	void push_front(T data); //добавление в начало
	void insert(T value, int index); //добавить элемент под индексом
	void pop_front(); //удаление первого элемента
	void pop_back(); //удаление последнего элемента
	void remove(int index); //удаление конкретного элемента
	void clear(); //удаление всего вписка
	void print(int index); //вывод элементов

	int Getsize() { return size; }

	T& operator[](const int index);
private:
	template <typename T>
	class Elem
	{

	public:
		Elem* nextElem;
		T data;
		Elem(T data = T(), Elem* nextElem = nullptr)
		{
			this->data = data;
			this->nextElem = nextElem;
		}
	};
	int size;

	Elem<T>* head;
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
	if (size == 0)
	{
		cout << "List is not created" << endl;
		return;
	}

	Elem<T>* temp = head;
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
	if (size == 0)
	{
		cout << "List is not created" << endl;
		return;
	}
	if ((index < 0) || (index > size - 1))
	{
		cout << "Invalid index" << endl;
		return;
	}
	if (index == 0)
	{
		pop_front();
	}

	else
	{
		Elem<T>* previous = this->head;
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
		cout << "There is no elements" << endl;
	if ((index < 0) || (index > size - 1))
	{
		cout << "Invalid index" << endl;
		return;
	}
	else
	{
		Elem<T>* current = this->head;
		cout << "Element " << index << ": ";
		int i = 0;
		while (i != index)
		{
			current = current->nextElem;
			i++;
		}
		cout << current->data << endl;

	}
}


template<typename T>
void List<T>::insert(T value, int index)
{
	if ((index < 0) || (index > size - 1))
	{
		cout << "Invalid index" << endl;
		return;
	}
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
		Elem<T>* newElem = new Elem<T>(value, previous->nextElem);
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

/*
	ошибка при удалении элемента при отсутствующем списке
*/
void test_1() {
	List<int> lst;
	lst.remove(0);
}

/*
	ошибка при добавлении элемента при отсутствующем списке
*/
void test_2() {
	List<int> lst;
	lst.insert(123, 123);
	lst.remove(-1);
}
/*
	ошибка при добавлении элемента при указании индекса большем, чем число элементов в списке.
*/
void test_3() {
	List<int> lst;
	lst.push_back(231);
	lst.push_back(231);
	lst.push_back(231);
	lst.remove(123);
	int num;
	cin >> num;
	lst.print(num);
	lst.insert(1, 123);
	lst.pop_front();
}
int main()
{
	char com = ' ';
	std::cin >> com;
	std::cout << "started:\n";
	test_3();
	/*int number;
	cin >> number;
	cout << endl;

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

	cin >> number;
	lst.remove(number);

	for (int i = 0; i < lst.Getsize(); i++)
	{
		cout << lst[i] << endl;
	}*/

	return 0;
}
