#include <iostream>
#include <string>

namespace StringList
{
	void init(void);
	void push(std::string str_in);
	std::string pop(void);

	void print(void);
	void sort(void);
	void reverse(void);

	struct ListEmpty
	{
		ListEmpty()
		{

		}
	};

	struct StringItem
	{
		StringItem* prev;
		StringItem* next;

		std::string str;
	};

	StringItem head;
	StringItem tail;
}

void StringList::init(void)
{
	head.next = &tail;
	tail.prev = &head;
}

// Add element to end of list, algorithm:
// - Start at tail.
// - Move to previous element.
// - Build new element, point to previous element and tail.
// - Update previous element (next) and tail (prev).
void StringList::push(std::string str_in)
{
	StringItem* prev_item = tail.prev;

	StringItem* new_item = new StringItem;
	new_item->prev = prev_item;
	new_item->next = &tail;
	new_item->str = str_in;

	prev_item->next= new_item;
	tail.prev = new_item;
}

// Remove element from end of list.
// Algorithm:
// 	- Start at tail.
// 	- Move to previous element.
// 	- If element is not 'head' remove element and return.
// 	- If element is 'head' throw an exception.
std::string StringList::pop(void)
{
	std::string str_out;

	StringItem* prev_item = tail.prev;

	if (prev_item != &head)
	{
		str_out = prev_item->str;

		prev_item->prev->next = &tail;
		tail.prev = prev_item->prev;

		delete prev_item;
	}
	else
	{
		throw ListEmpty();
	}

	return str_out;
}

// Print the elements of the list.
void StringList::print(void)
{
	std::cout << "List:" << std::endl;

	for (StringItem* item = head.next; item != &tail; item = item->next)
	{
		std::cout << "- " << item->str << std::endl;
	}

	std::cout << std::endl;
}

// Sort the list in alphabetical order.
// Algorithm:
// 	- Bubble sort.
void StringList::sort(void)
{
	bool swap;

	do
	{
		swap = false;

		for (StringItem* item2 = head.next; (item2->next != &tail) && (item2 != &tail); item2 = item2->next)
		{
//			std::cout << "Comparing '" << item2->str << "' and '" << item2->next->str << "'."  << std::endl;
			if (item2->str.compare(item2->next->str.c_str()) > 0)
			{
				StringItem* item1 = item2->prev;
				StringItem* item3 = item2->next;
				StringItem* item4 = item3->next;

				swap = true;
//				std::cout << "Swapping '" << item2->str << "' and '" << item3->str << "'."  << std::endl;

				item1->next = item3;
				item2->next = item4;
				item3->next = item2;

				item4->prev = item2;
				item3->prev = item1;
				item2->prev = item3;
			}
		}
//		std::cout << "Looped once!" << std::endl;
//		StringList::print();
	} while (swap);
}

// Reverse the order of elements in a list.
// Algorithm:
//	- Start at head
//  - Increment list and swap the head/tail of each element.
//	- The swap head/tail to point to new first/last element.
void StringList::reverse(void)
{
	// Note: net to increment to next element using item.prev since
	// prev and next swapped internal to loop.
	for (StringItem* item = head.next; item != &tail; item = item->prev)
	{
		StringItem* tmp = item->next;
		item->next = item->prev;
		item->prev = tmp;
	}

	head.next->next = &tail;
	tail.prev->prev = &head;

	StringItem* tmp = head.next;
	head.next = tail.prev;
	tail.prev = tmp;
}

//-------------------------------------------------------------------

int main()
{
	StringList::init();

	StringList::push("python");
	std::string tmp = StringList::pop();

	std::cout << "Poped string: " << tmp << std::endl;

	try
	{
		std::string tmp2 = StringList::pop();
	}
	catch(StringList::ListEmpty&)
	{
		std::cout << "Application failed successfully."<< std::endl << std::endl;
	}

	StringList::push("python");
	StringList::push("c");
	StringList::push("c++");
	StringList::push("java");
	StringList::push("assembly");

	std::cout << "Original:"<< std::endl;
	StringList::print();

	StringList::sort();
	std::cout << "Sorted:"<< std::endl;
	StringList::print();

	StringList::reverse();
	std::cout << "Reversed:"<< std::endl;
	StringList::print();

	return 0;
}
