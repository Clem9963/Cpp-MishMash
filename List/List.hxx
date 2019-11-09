#include <iostream>

/*------*/
/* Cell */
/*------*/

template <typename T>
List<T>::Cell::Cell(T data, List<T>::Cell *next)
	: _data(data), _next(next)
{}

template <typename T>
void List<T>::Cell::setNext(List<T>::Cell *o) { _next = o; }

/*------*/
/* List */
/*------*/

template <typename T>
List<T>::List()
	: _count(0), _first(nullptr), _last(nullptr)
{}

template <typename T>
List<T>::~List()
{
	Cell *cour = _first;
	Cell *temp;

	while (cour)
	{
		temp = cour;
		cour = cour->_next;
		delete temp;
	}
}

template <typename T>
bool List<T>::empty()
{
	if (_first)
		return false;

	return true;
}

template <typename T>
size_t List<T>::size() { return _count; }

template <typename T>
void List<T>::push_back(T data)
{
	List<T>::Cell *new_cell = new List<T>::Cell(data, nullptr);
	if (!_last)
		_first = new_cell;
	else
		_last->_next = new_cell;

	_last = new_cell;
	++_count;
}

template <typename T>
void List<T>::push_front(T data)
{
	List<T>::Cell *new_cell = new List<T>::Cell(data, _first);
	if (!_first)
		_last = new_cell;

	_first = new_cell;
	++_count;
}

template <typename T>
T List<T>::front() { return _first; }

template <typename T>
T List<T>::back() { return _last; }

template <typename T>
T List<T>::pop_front()
{
	List<T>::Cell *tmp = _first;
	T res = _first->_data;
	_first = _first->_next;

	if (!_first)
		_last = nullptr;

	delete tmp;
	--_count;

	return res;
}

template <typename T>
T List<T>::pop_back()
{
	List<T>::Cell *prec = _first;
	List<T>::Cell *cour = _first;
	T res = _last->_data;

	while (cour->_next)
	{
		prec = cour;
		cour = cour->_next;
	}
	if (!_first->_next)
		_first = nullptr;

	_last = prec;
	delete prec->_next;
	prec->_next = nullptr;
	--_count;

	return res;
}

template <typename T>
void List<T>::display(std::ostream &stream) const
{
	List<T>::Cell *cour = _first;

	std::cout << "~~ DISPLAYING THE LIST ~~" << std::endl;
	std::cout << "Number of elements : " << _count << std::endl;
	std::cout << "Pointer on first : " << _first << std::endl;
	std::cout << "Pointer on last : " << _last << std::endl;
	std::cout << "Content of the list : ";

	while (cour)
	{
		stream << cour->_data << ", ";
		cour = cour->_next;
	}
	std::cout << "\b\b " << std::endl;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const List<T> &l)
{
	l.display(stream);
	return stream;
}

template <typename T>
typename List<T>::ItList List<T>::begin() { return ItList(_first); }

template <typename T>
typename List<T>::ItList List<T>::end() { return ItList(); }

/*--------*/
/* ItList */
/*--------*/

template <typename T>
const char *List<T>::ItList::NullIteratorException::what() const noexcept
{
	return "Cannot dereference a null iterator";
}

template <typename T>
List<T>::ItList::ItList()
	: _cell(nullptr)
{}

template <typename T>
List<T>::ItList::ItList(Cell *cell_ptr)
	: _cell(cell_ptr)
{}

template <typename T>
bool List<T>::ItList::equals(const ItList &other) const { return _cell == other._cell; }

template <typename T>
bool List<T>::ItList::operator!=(const ItList &other) const
{
	return !this->equals(other);
}

template <typename T>
T &List<T>::ItList::operator*()
{
	if (!_cell)
		throw NullIteratorException();
	else
		return _cell->_data;
}

template <typename T>
typename List<T>::ItList &List<T>::ItList::operator++()
{
	_cell = _cell->_next;
	return *this;
}

template <typename T>
typename List<T>::ItList List<T>::ItList::operator++(int)
{
	ItList tmp = *this;
	++*this;
	return tmp;
}
