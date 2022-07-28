#include "list.h"

int change_val(Node object) {
	object._val += 10;
	object._val *= 2;
	return object._val;
}

int main() {
	int num, val;
	std::cin >> num;
	List lst;
	for (int i = 0; i < num; i++) {
		std::cin >> val;
		lst.push_back(val);
	}
	std::cout<<"\n";
	lst.print_list();
	lst.remove_after_last_min();
	lst.print_list();
	lst.change_list(change_val);
	lst.print_list();
	lst.remove_after_last_min();
	lst.print_list();
	return 0;
}