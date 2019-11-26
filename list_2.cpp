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

	T& operator[](const unsigned int index);
private:
	template <typename T>
	class Elem
	{

	public:
		Elem* nextElem;
		Elem* prevElem;

		T data;
		Elem(T data = T(), Elem* nextElem = nullptr, Elem* prevElem = nullptr)
		{
			this->data = data;
			this->nextElem = nextElem;
			this->prevElem = prevElem;
		}
	};
	int size;

	Elem<T>* head;
	Elem<T>* tail;
};


template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::~List()
{
	this->clear();
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
	if (head==nullptr)
		tail = nullptr;
	else
		head->prevElem = nullptr;

	delete temp;
	size--;
}

template<typename T>
void List<T>::pop_back()
{
	if (size == 0)
	{
		cout << "List is not created" << endl;
		return;
	}

	Elem<T>* temp = tail;
	tail = tail->prevElem;
	if (tail == nullptr)
		head = nullptr;
	else
		tail->nextElem = nullptr;
	delete temp;
	size--;
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
		if (index <= (size / 2))
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
		else
		{
			Elem<T>* next = this->tail;
			for (int i = index - 1; i >= 0; i--)
			{
				next = next->prevElem;
			}
			Elem<T>* Delete = next->prevElem;
			delete Delete;
			size--;
		}
	}
}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Elem<T>(data);
		tail = head;
	}
	else
	{
		tail->nextElem = new Elem<T>(data, nullptr, tail);
		tail = tail->nextElem;
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Elem<T>(data, head);
	if (this->size == 0)
		tail = head;
	else
		head->nextElem->prevElem = head;
	size++;
}

template<typename T>
void List<T>::clear()
{
	while (head!=nullptr)
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
		if (index <= (size / 2))
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
		else
		{
			Elem<T>* current = this->tail;
			cout << "Element " << index << ": ";
			int i = size - 1;
			while (i != index)
			{
				current = current->prevElem;
				i--;
			}
			cout << current->data << endl;
		}
	}
}


template<typename T>
void List<T>::insert(T value, int index)
{
	if ((index < 0) || (index > size))
	{
		cout << "Invalid index" << endl;
		return;
	}
	if (index == 0)
		push_front(value);
	if (index == size)
		push_back(value);
	else
	{
		if (index <= (size / 2))
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
		else
		{
			Elem<T>* next = this->tail;
			for (int i = size; i > index; i--)
			{
				next = next->prevElem;
			}
			Elem<T>* newElem = new Elem<T>(value, next->nextElem ,next->prevElem);
			next->nextElem->prevElem = newElem;
			next->nextElem = newElem;
			size++;
		}
	}
}

template<typename T>
T& List<T>::operator[](const unsigned int index)
{
	int counter = 0;
	Elem<T>* current = this->head;
	while (current!= nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->nextElem;
		counter++;
	}
	cout << "ERROR" << endl;
	abort();
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
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);

	lst.insert(80211, 4);
	
	for (int i = 0; i < lst.Getsize(); i++)
		cout << lst[i] << endl;
	

}
int main()
{
	std::cout << "started"<<endl;
	
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

	*/

	return 0;
}
