/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:19:05 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/24 18:19:10 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "node.hpp"
# include "../../includes/BidirectionalIterator.hpp"
# include "../../includes/ReverseBidirectionalIterator.hpp"

namespace ft
{
	template <typename T>
	class BidirectionalIterator;

	template <typename T>
	class ReverseBidirectionalIterator;

	template <class T, class Allocator = std::allocator<T> >
	class list
	{

		public:

			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef T											&reference;
			typedef const T										&const_reference;
			typedef T											*pointer;
			typedef const T										*const_pointer;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			typedef BidirectionalIterator <value_type>				iterator;
			typedef const BidirectionalIterator <value_type>		const_iterator;
			typedef ReverseBidirectionalIterator <value_type>		reverse_iterator;
			typedef const ReverseBidirectionalIterator <value_type>	const_reverse_iterator;

		private:

			typedef node<T>		node;
			node				*_head;
			node				*_tail;
			size_type			_size;
			allocator_type		_alloc;

			void	init(void)
			{
				_head = new node;
				_tail = new node;
				_head->_next = _tail;
				_head->_previous = _tail;
				_tail->_next = _head;
				_tail->_previous = _head;
			}

			node	*find(iterator pos)
			{
				node	*find = _head;

				for (iterator it = begin(); it != pos && it != end(); it++)
					find = find->_next;
				return	find;
			}

		public:

			explicit	list(const	allocator_type &alloc = allocator_type()):
				_alloc(alloc)
			{
				init();
				_tail = _head;
				_size = 0;
			}

			explicit	list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()):
				_size(0), _alloc(alloc)
			{
				if (n > 0)
				{
					init();
					_tail = _head;
					for (size_type i = 0; i < n; i++)
						push_back(val);
				}
			}

			template <class InputIt>
			list (InputIt first, InputIt last, const allocator_type &alloc = allocator_type(), typename InputIt::difference_type * = nullptr)
			{
				_alloc = alloc;
				init();
				_tail = _head;
				_size = 0;
				if (first == last)
					return ;
				_head->_value = *first++;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			list(const list &l): _size(0), _alloc(l.get_allocator())
			{
				init();
				_tail = _head;
				if (l.size() > 0)
					_head->_value = l._head->_value; 
				for (iterator it = l.begin(); l.size() > 0 && it != l.end(); it++)
					push_back(*it);
			}

			~list()
			{
				clear();
				delete _head;
			}

			list		&operator=(const list &l)
			{
				clear();
				insert(begin(), l.begin(), l.end());
				return	*this;
			}

			//ITERATORS

			iterator				begin()
			{
				return	iterator(_head);
			}

			const_iterator			begin() const
			{
				return	const_iterator(_head);
			}

			iterator				end()
			{
				return	iterator(_tail);
			}

			const_iterator			end() const
			{
				return	iterator(_tail);
			}

			reverse_iterator		rbegin()
			{
				return	reverse_iterator(_tail);
			}

			const_reverse_iterator	rbegin() const
			{
				return	const_reverse_iterator(_tail);
			}

			//CAPACITY
		
			bool		empty() const
			{
				return	(_size == 0 ? true : false);
			}

			size_type	size() const
			{
				return	_size;
			}

			size_type	max_size() const
			{
				return	(SIZE_T_MAX / sizeof(node));
			}

			//ElEMENT ACCESS
			
			reference		front()
			{
				return	_head->_value;
			}

			const_reference	front() const
			{
				return	_head->_value;
			}

			reference		back()
			{
				return	_tail->_previous->_value;
			}

			const_reference	back() const
			{
				return	_tail->_previous->_value;
			}

			//MODIFIERS

			template <class InputIt>
			void		assign(InputIt first, InputIt last, typename InputIt::difference_type * = nullptr)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void		assign(size_type n, const value_type &val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			void		push_front(const value_type	&val)
			{
				node	*n = new node;

				n->_value = val;
				n->_next = _head;
				n->_previous = _tail;
				_head = n;
				_size++;
			}

			void		pop_front()
			{
				erase(begin());
			}

			void		push_back(const value_type &val)
			{
				node	*n = new node;

				_tail->_value = val;
				_tail->_next = n;
				n->_previous = _tail;
				_tail = n;
				_tail->_next = _head;
				_size++;
			}

			void		pop_back()
			{
				erase(--end());
			}

			iterator	insert(iterator position, const value_type &val)
			{
				node	*f = find(position);
				node	*n = new node(val);

				n->_previous = f->_previous;
				n->_next = f;
				n->_previous->_next = n;
				f->_previous = n;
				if (f == _head)
					_head = n;
				_size++;
				return	position;
			}

			void		insert(iterator position, size_type n, const value_type &val)
			{
				for (size_type i = 0; i < n; i++)
					insert(position, val);
			}

			template <class InputIt>
			void		insert(iterator position, InputIt first, InputIt last, typename InputIt::difference_type * = nullptr)
			{
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
			}

			iterator	erase(iterator position)
			{
				node	*del;
				
				if (_size == 0)
					return	position;
				del = find(position);
				if (del == _tail)
					return	position;
				if (del == _head)
				{
					if (del->_next == _tail)
					{
						_tail = _head;
						_size--;
						return	position;
					}
					_head = del->_next;
				}
				if (_head != _tail)
				{
					del->_previous->_next = del->_next;
					del->_next->_previous = del->_previous;
				}
				if (del != _head && del != _tail)
					delete	del;
				_size--;
				return	position;
			}

			iterator	erase(iterator first, iterator last)
			{
				for(iterator it = first; it != last; it++)
					erase(it);
				return	first;
			}

			void		swap(list &x)
			{
				list<value_type> tmp(x);

				x = *this;
				*this = tmp;
			}

			void		resize(size_type n, value_type val = value_type())
			{
				iterator it = begin();
				
				if (n <= 0)
					clear();
				else if (n > _size)
					for (size_type i = _size; n > i; i++)
						push_back(val);
				else if (n < _size)
				{
					for (size_type j = 0; j < n; j++)
						it++;
					erase(it, end());
				}
				_size = n;
			}

			void		clear()
			{
				erase(begin(), end());
			}

			//OPERATIONS
			//
			void		splice(iterator position, list &x)
			{
				for(iterator it = x.begin(); it != x.end(); it++)
					insert(position, *it);
				x.clear();
			}

			void		splice(iterator position, list& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			void		splice(iterator position, list& x,
								iterator first, iterator last)
			{
				iterator tmp = first;

				for ( ; first != last; first++)
					insert(position, *first);
				x.erase(tmp, last);
			}


			void		remove(const value_type &val)
			{
				iterator	it = begin();

				while (it != end())
				{
					if (*it == val)
					{
						erase(it);
						it = begin();
					}
					else
						it++;
				}
			}

			template <class Predicate>
			void		remove_if(Predicate pred)
			{
				iterator it = begin();

				while (it != end())
				{
					if (pred(*it))
					{
						erase(it);
						it = begin();
					}
					else
						it++;
				}

			}

			void		unique()
			{
				iterator test = begin();
				iterator tmp;

				for (iterator it = begin(); it != end(); it++)
				{
					test = it;
					test++;
					for ( ; test != end(); test++)
						if (* test == *it)
						{
							tmp = test;
							tmp++;
							erase(test);
							test = it;
						}
				}
			}

			template <class BinaryPredicate>
			void		unique(BinaryPredicate binary_pred)
			{
				iterator test = begin();
				iterator tmp;

				for (iterator it = begin(); it!= end(); it++)
				{
					test = it;
					test++;
					for ( ; test != end(); test++)
						if (binary_pred(*it, *test))
						{
							tmp = test;
							tmp++;
							erase(test);
							test = it;
						}
				}
			}

			void		merge(list &x)
			{
				bool is_sort = true;
				iterator test = x.begin();

				test++;
				for (iterator it = x.begin(); test != x.end(); it++, test++)
					if (*test < *it)
						is_sort = false;

				test = begin();
				test++;
				for (iterator it = begin(); test != end(); it++, test++)
					if (*test < *it)
						is_sort = false;

				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);

				x.clear();
				if (is_sort)
					sort();
			}

			template <class Compare>
			void		merge(list &x, Compare comp)
			{
				bool is_sort[] = {true, true, true, true};
				iterator test = ++x.begin();

				if (this == &x)
					return ;
				for (iterator it = x.begin(); test != x.end(); it++)
				{
					if (!comp(*it, *test))
						is_sort[0] = false;
					if (*test < *it)
						is_sort[1] = false;
					test++;
				}

				test = ++begin();
				for (iterator it = begin(); test != end(); it++, test++)
				{
					if (!comp(*it, *test))
						is_sort[2] = false;
					if (*test < *it)
						is_sort[3] = false;
				}

				if (is_sort[2] && is_sort[1])
					x.sort();
				if (is_sort[3] && is_sort[0])
					for (iterator it = x.begin(); it != x.end(); it++)
					{
						if (comp(*it, *begin()))
							push_front(*it);
						else
							push_back(*it);
					}
				else
					for (iterator it = x.begin(); it != x.end(); it++)
						push_back(*it);
				x.clear();
				if (is_sort[0] && is_sort[2])
					sort(comp);
			}

			void		sort()
			{
				iterator b = 	begin();
				iterator nxt = 	begin();
				node 			*tmp = new node;

				while (++b != end())
				{
					if (*b < * nxt)
					{
						tmp->_value = *nxt;
						*nxt = *b;
						*b = tmp->_value;
						b = begin();
						nxt = begin();
					}
					else
						nxt++;
				}
				delete tmp;
			}

			template <class Compare>
			void					sort(Compare comp)
			{
				iterator	b = begin();
				iterator	nxt = begin();
				node		*tmp = new node;

				while (++b != end())
				{
					if (comp(*b, *nxt))
					{
						tmp->_value = *nxt;
						*nxt = *b;
						*b = tmp->_value;
						b = begin();
						nxt = begin();
					}
					else
						nxt++;
				}
				delete tmp;
			}

			void			reverse()
			{
				iterator 	b = begin();
				iterator	e = end();
				node		*tmp = new node;

				for (size_type i = 0; i < _size / 2; i++)
				{
					e--;
					tmp->_value = *b;
					*b++ = *e;
					*e = tmp->_value;
				}
				delete tmp;
			}

			//OBSERVERS
			//
			allocator_type		get_allocator() const
			{
				return	_alloc;
			}
	};

	//OVERLOADS
	//
	template <class T, class Alloc>
	bool	operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (typename list<T>::iterator l = lhs.begin(), r = rhs.begin();
													l != lhs.end(); l++, r++)
		{
			if (*l != *r)
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool	operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if ((*(lhs.begin()) < *(rhs.begin())))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool	operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return ((rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void	swap(list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
