#ifndef LIST_H
#define LIST_H

#include <iostream>
// Узел
class Node {
public:
	int _val;
	Node* _next;
};

typedef int (*func_ptr)(Node);

// Лист
class List {
private:
	Node* _first;
	Node* create_node(int val);
public:
	// Конструкторы
	List() { _first = 0; }
	List(int val) { _first->_val = val; }

	// Вывод списка
	void print_list const();
	// Добавление элемента в конец списка
	void push_back(int val);
	// Добавление элемента в начало списка
	void push_front(int val);
	// Вставка перед элементом
	void insert_before(Node* cur, int val);
	// Указатель на последний элемент
	Node* back();

	// Поиск значения минимального элемента
	int search_min();
	// Удаление первого элемента
	void remove_first();
	// Удаление последнего элемента
	void remove_last();
	// Позиция последнего минимального элемента(если список пуст возвращает -1)
	int pos_last_min();
	// Удаление элемента после последнего минимального
	void remove_after_last_min();
	// Изменение всех элементов с помощью функции change
	void change_list(func_ptr change_val);

	// Деструктор
	~List();
};

#endif // LIST_H