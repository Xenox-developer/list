#include "list.h"
#include <bits/stdc++.h>

// Создание указателя на элемент
Node* List::create_node(int inf) {
	Node* el = new Node;
	el->_val = inf;
	el->_next = 0;
	return el;
}

// Вывод списка
void List::print_list() {
	if (_first == 0) return;
	Node* curr = _first;
	while (curr != 0) {
		std::cout << curr->_val << ' ';
		curr = curr->_next;
	}
	std::cout << '\n';
}

// Добавление элемента в конец списка
void List::push_back(int inf) {
	if (_first == 0) {
		_first = create_node(inf);
		return;
	}
	Node* curr = _first;
	while (curr->_next != 0) curr = curr->_next;
	Node* new_el = create_node(inf);
	curr->_next = new_el;
}

// Добавление элемента в начало списка
void List::push_front(int inf) {
	Node* new_el = create_node(inf);
	new_el->_next = _first;
	_first = new_el;
}

// Вставка перед элементом
void List::insert_before(Node* cur, int inf) {
	if (_first == cur) {
		this->push_front(inf);
		return;
	}
	Node* tmp = _first;
	while (tmp->_next != cur and tmp->_next != 0) tmp = tmp->_next;
	Node* new_el = create_node(inf);
	new_el->_next = cur;
	tmp->_next = new_el;
}

// Указатель на последний элемент
Node* List::back() {
	if (_first == 0) return 0;
	Node* curr = _first;
	while (curr->_next != 0) curr = curr->_next;
	return curr;
}

// Поиск значения минимального элемента
int List::search_min() {
	Node* curr = _first;
	int min = INT_MAX;
	while (curr != 0) {
		if (curr->_val < min) min = curr->_val;
		curr = curr->_next;
	}
	return min;
}

// Удаление первого элемента
void List::remove_first() {
	if (_first == 0) return;
	Node* curr = _first;
	_first = curr->_next;
	delete curr;
}

// Удаление последнего элемента
void List::remove_last() {
	if (_first == 0) return;
	if (_first->_next == 0) {
		remove_first();
		return;
	}
	Node* curr = _first;
	while (curr->_next != 0) curr = curr->_next;
	delete curr;
}

// Позиция последнего минимального элемента(если список пуст возвращает -1).
int List::pos_last_min() {
	int min, pos_last_min = -1, count = 0;
	min = search_min();
	if (_first == 0) return -1;
		Node* curr = _first;
	while (curr != 0) {
		while ((curr->_val != min) and (curr->_next != 0)) {
			curr = curr->_next;
			count++;
		}
		if (curr->_val == min) 
			pos_last_min = count;
		if (curr->_next == 0)
			break;
		curr = curr->_next;
		count++;
		if (curr->_val == min) 
			pos_last_min = count;
	}
	return pos_last_min;
}

// Удаление элемента после последнего минимального.
void List::remove_after_last_min() {
	int pos_min = pos_last_min();
	if (pos_min == -1) 
		return;
	Node* curr = _first;
	Node* tmp = curr->_next;
	for (int i = 0; i < pos_min - 1; i++) {
		tmp = tmp->_next;
		curr = curr->_next;
	}
	if ((tmp == 0) or (tmp->_next == 0)) 
		return;
	else {
		if (pos_min != 0) {
		curr = curr->_next;
		tmp = tmp->_next;
		}
		curr->_next = tmp->_next;
		delete tmp;
		tmp = curr->_next;
	}
}

// Изменение всех минимальных элементов с помощью функции change_val. Указатель на функцию преобразования передается в качестве параметра
void List::change_list(func_ptr change_val) {
	int min = search_min();
	if (min == -1) 
		return; 
	Node* curr = _first;
	while (curr != 0) {
		if(curr->_val == min)
			curr->_val = change_val(*curr);
		curr = curr->_next;
	}
}

// Деструктор
List::~List() {
	Node* cur = _first;
	while (cur != 0) {
		Node* temp = cur->_next;
		delete cur;
		cur = temp;
	}
}