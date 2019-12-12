#include <exception>
#include <iostream>

template <typename T>
class List
{
  public:
	class ItList;

  private:
	class Cell
	{
	  private:
		T _data;
		Cell *_next;

	  public:
		Cell(T data, Cell *next);

		void setNext(Cell *o);

		friend List;
		friend ItList;
	};

	size_t _count;
	Cell *_first;
	Cell *_last;

  public:
	class ItList
	{
	  private:
		Cell *_cell;

	  public:
		class NullIteratorException : public std::exception
		{
			virtual const char *what() const noexcept;
		};

		ItList();
		ItList(Cell *cell_ptr);

		bool equals(const ItList &other) const;
		bool operator!=(const ItList &other) const;
		T &operator*();
		ItList &operator++();	// prefixed version
		ItList operator++(int); // postfixed version

		friend List;
	};

	List();
	~List();

	bool empty();
	size_t size();

	void push_back(T data);
	void push_front(T data);
	T front();
	T back();
	T pop_front();
	T pop_back();

	void display(std::ostream &stream) const;

	ItList begin();
	ItList end();
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const List<T> &l);

#include "List.hxx"