/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/27 18:20:46 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include	<limits>
# include	"../Utils/utils.hpp"
# include	"./iterators/iterator_m.hpp"
# include	"./iterators/const_iterator_m.hpp"
# include	"./iterators/reverse_iterator_m.hpp"
# include	"./iterators/const_reverse_iterator_m.hpp"


template <class T>
struct node
{
	public:

		typedef T 	value_type;

		node		*parent;
		node		*left;
		node		*right;
		value_type	*value;

		node(void)
		{
			parent = NULL;
			left = NULL;
			right = NULL;
			value = NULL;
		}

		node(value_type *val)
		{
			value = val;
			parent = NULL;
			left = NULL;
			right = NULL;
		}
};

template <typename T>
node<T>	*get_left(node<T> *node)
{
	return	node->left;
}

template <typename T>
node<T>	*get_right(node<T> *node)
{
	return	node->right;
}

template <typename T>
node<T>	*get_parent(node<T> *node)
{
	return	node->parent;
}

template <typename T>
node<T>	*last_right(node<T> *node)
{
	while (node->right != NULL)
		node = node->right;
	return	node;
}

template <typename T>
node<T>	*last_left(node<T> *node)
{
	while (node->left != NULL)
		node = node->left;
	return	node;
}

namespace ft
{
	//-------- MAP CLASS --------

	template <class Tkey, class Tvalue, class Compare = ft::less<Tkey>, class Alloc = std::allocator<pair<const Tkey, Tvalue> > >
	class map
	{
		public:

			typedef Tkey												key_type;
			typedef Tvalue												map_value;
			typedef ft::pair<const key_type, map_value>					value_type;
			typedef node<value_type>									node_type;
			typedef Compare												key_compare;
			typedef std::allocator<value_type>							allocator_type;
			typedef std::allocator<node_type> 								nodeAlloc;
			typedef typename Alloc::template rebind<node_type>::other	new_alloc;

			typedef value_type							&reference;
			typedef reference							const_reference;
			typedef value_type							*pointer;
			typedef const pointer						const_pointer;
			
			typedef iterator_m<value_type, node_type>				iterator;
			typedef const_iterator_m<value_type, node_type>			const_iterator;
			typedef reverse_iterator_m<value_type, node_type>		reverse_iterator;
			typedef const_reverse_iterator_m<value_type, node_type>	const_reverse_iterator;

			typedef size_t			size_type;
			typedef	std::ptrdiff_t	difference_type;

		private:

			node<value_type>	*_map;
			public:
			node<value_type>	*_upper;
			node<value_type>	*_lower;
			node<value_type>	*_fake_begin;
			node<value_type>	*_fake_end;
			private:
			size_type			_size;
			allocator_type		_alloc;
			nodeAlloc			_node_alloc;
			key_compare			_key_cmp;

			void	clear_tree(node_type *m)
			{
				if (m == NULL)
					return ;
				clear_tree(m->left);
				clear_tree(m->right);
				delete m;
			}

			void	copy_tree(map &m)
			{
				this->clear();
				node_type	*tmp = _map;

				_map = m._map;
				_size = m._size;
				_alloc = m._alloc;
				_key_cmp = m._key_cmp;
				m._map = tmp;
				m._size = 0;
				tmp = NULL;
			}

			node_type		*find_node(key_type key)
			{
				node_type	*tmp = _map;
				if (_size == 0)
					return (NULL);
				while (true)
				{
					if (tmp->value->first == key)
						return (tmp);
					if (key < tmp->value->first)
					{
						if (tmp->left)
							tmp = tmp->left;
						else
							break;
					}
					else
					{
						if (tmp->right)
							tmp = tmp->right;
						else
							break;
					}
				}
				return (NULL);
			}

			void		erase_leaf(node_type *leaf)
			{
				if (_size == 1)
				{
					delete leaf;
					leaf = NULL;
					_map = NULL;
					delete _fake_end;
					_fake_end = _fake_begin;
					_fake_begin->parent = NULL;
					_upper = _fake_begin;
					_lower = _fake_begin;
					_size = 0;
					return ;
				}
				if (leaf->parent && leaf->parent->left == leaf)
					leaf->parent->left = NULL;
				else if (leaf->parent && leaf->parent->right == leaf)
				{
					leaf->parent->right = NULL;
				}
				delete leaf;
				leaf = NULL;
				set_upper();
				set_lower();
				_size--;
			}

			void		erase_single(node_type *node)
			{
				node_type *replace;
			
				if (node->right && node->right != _fake_end)
					replace = node->right;
				else if (node->left && node->left != _fake_begin)
					replace = node->left;
				if (node == _map)
				{
					_map = replace;
					// if (replace == node->right)
					// 	_upper = _map;
					// else
					// 	_lower = _map;
					//set_lower();
				}
				else
				{
					// if (node == _lower)
					// 	_lower = node->parent;
					// if (node == _upper)
					// 	_upper = node->parent;
					if (node == node->parent->right)
						node->parent->right = replace;
					if (node == node->parent->left)
						node->parent->left = replace;
				}
				replace->parent = node->parent;
				delete node;
				node = NULL;
				set_lower();
				set_upper();
				_size--;
			}

			void		erase_double(node_type *node)
			{
				node_type *next = node;
				node_type *tmp;

				if (next->left && next->left != _fake_begin)
					next = next->left;
				while (next->right && next->right != _fake_end)
					next = next->right;
				if (node->parent)
				{
					if (node->parent && node->parent->left == node)
						node->parent->left = next;
					else
						node->parent->right = next;
					next->parent = node->parent;
					node->parent = NULL;
				}
				next->right = node->right;
				next->right->parent = next;
				node->right = NULL;
				if (next->parent->value->first != node->value->first)
				{
					if (next->left && next->left != _fake_begin)
					{
						tmp = next->left;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = node->right;
						node->left->parent = tmp;
					}
				}
				if (node == _map)
				{
					_map = next;
					next->parent = NULL;
				}
				delete node;
				node = NULL;
				set_upper();
				set_lower();
				_size--;
			}

			void	set_upper()
			{
				node_type *node = _map;

				while (node->right && node->right != _fake_end)
					node = node->right;
				_upper = node;
				if (_upper != _fake_end->parent)
				{
					
					_upper->right = _fake_end;
					_fake_end->parent = _upper;
				}
			}

			void	set_lower()
			{
				node_type *node = _map;
				while (node->left && node->left != _fake_begin)
					node = node->left;

				_lower = node;

				if (_lower != _fake_begin->parent)
				{
					
					_lower->left = _fake_begin;
					_fake_begin->parent = _lower;
				}
			}

		public:

			//CONSTRUCTORS
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_map = NULL;
				_size = 0;
				_alloc = alloc;
				_key_cmp = comp;

				_fake_begin = _node_alloc.allocate(1);
				_node_alloc.construct(_fake_begin, node_type());
				_fake_end = _fake_begin;

				_lower = _fake_begin;
				_upper = _fake_end;
			}

			template <class InputIt>
			map(InputIt first, typename ft::enable_if<InputIt::is_iterator, InputIt>::type last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_map = NULL;
				_size = 0;
				_alloc = alloc;
				_key_cmp = comp;
				insert(first, last);
			}

			map &operator=(map const &m)
			{
				if (_size > 0)
					clear();
				if (m.size() > 0)
					this->insert(m.begin(), m.end());
				return	*this;
			}

			map(const map &x)
			{
				_map = NULL;
				_size = 0;
				_alloc = allocator_type();
				_key_cmp = key_compare();
				
				_fake_begin = _node_alloc.allocate(1);
				_node_alloc.construct(_fake_begin, node_type());
				_fake_end = _fake_begin;

				_lower = _fake_begin;
				_upper = _fake_end;

				*this = x;
			}

			virtual	~map()
			{
				// if (empty() == 0)
				// 	clear();
			}

			//ITERATORS
			iterator				begin()
			{
				return	iterator(_lower);
			}

			const_iterator			begin() const
			{
				return	const_iterator(_lower);
			}

			iterator				end()
			{
				return	iterator(_fake_end);
			}

			const_iterator			end() const
			{
				return	const_iterator(_fake_end);
			}

			reverse_iterator 		rbegin()
			{
				return	reverse_iterator(_upper);
			}

			const_reverse_iterator	rbegin() const
			{
				return	const_reverse_iterator(_upper);
			}

			reverse_iterator		rend()
			{
				return	reverse_iterator(_fake_begin);
			}

			const_reverse_iterator	rend() const
			{
				return	const_reverse_iterator(_fake_begin);
			}

			//CAPACITY
			bool		empty() const
			{
				if (_size > 0)
					return	0;
				return	1;
			}

			size_type	size() const
			{
				return	_size;
			}

			size_type	max_size() const
			{
				return	(std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ? : 1));
			}

			//valueENT ACCESS
			map_value	&operator[](const key_type &k)
			{
				iterator	it = find(k);
				if (it != end())
					return	((*it).second);
				return	((insert(value_type(k, map_value()))).first->second);
			}

			//MODIFIERS
			
			pair<iterator, bool>	insert(const value_type &val)
			{
				// node_type *new_node = _node_alloc.allocate(1);
				// _node_alloc.construct(new_node, node_type());

				node_type *tmp = _map;
				if (_size == 0)
				{
					value_type *value = _alloc.allocate(1);
					_alloc.construct(value, val);
					node_type *new_node = _node_alloc.allocate(1);
					_node_alloc.construct(new_node, value);
					_map = new_node;
					_upper = _map;
					_lower = _map;
					_fake_end = _node_alloc.allocate(1);
					_node_alloc.construct(_fake_end, node_type());
					_upper->right = _fake_end;
					_lower->left = _fake_begin;
					_fake_begin->parent = _map;
					_fake_end->parent = _map;
					_size++;
					return (ft::make_pair(find(new_node->value->first), true));
				}
				else
				{
					while(1)
					{
						if (val.first == tmp->value->first)
						{
							return (ft::make_pair(find(tmp->value->first), false));
						}
						if (val.first < tmp->value->first)
						{
							if (tmp->left == NULL || tmp->left == _fake_begin)
							{
								value_type *value = _alloc.allocate(1);
								_alloc.construct(value, val);
								node_type *new_node = _node_alloc.allocate(1);
								_node_alloc.construct(new_node, value);
								tmp->left = new_node;
								new_node->parent = tmp;
								set_lower();
								_size++;
								return (ft::make_pair(find(new_node->value->first), true));
							}
							tmp = tmp->left;
						}
						else if (val.first > tmp->value->first)
						{
							if (tmp->right == NULL || tmp->right == _fake_end)
							{
								value_type *value = _alloc.allocate(1);
								_alloc.construct(value, val);
								node_type *new_node = _node_alloc.allocate(1);
								_node_alloc.construct(new_node, value);
								tmp->right = new_node;
								new_node->parent = tmp;
								if (new_node->value->first > _upper->value->first)
								{
									_upper = new_node;
									_fake_end->parent = new_node;
									new_node->right = _fake_end;
								}
								_size++;
								return (ft::make_pair(find(new_node->value->first), true));
							}
							tmp = tmp->right;
						}
						else
							return (ft::make_pair(iterator(tmp), false));
					}
				}
			}

			iterator				insert(iterator position, const value_type &val)
			{
				(void)position;
				return	insert(val).first;
			}

			template <class InputIterator>
			void					insert(InputIterator first, InputIterator last, typename ft::enable_if<InputIterator::is_iterator, InputIterator>::type = NULL)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			//Erase

			size_type		erase(const key_type& k)
			{
				node_type *tmp = find_node(k);

				if (!tmp)
					return (0);
				if (tmp)
				{
					if ((!tmp->left && !tmp->right) || (!tmp->left && tmp->right == _fake_end) ||
						(!tmp->right && tmp->left == _fake_begin) || (tmp->right == _fake_end && tmp->left == _fake_begin))
						erase_leaf(tmp);
					else if ((tmp->left && (!tmp->right || tmp->right == _fake_end)) ||
							(tmp->right && (!tmp->left || tmp->left == _fake_begin)))
						erase_single(tmp);
					else if (tmp->right && tmp->left)
						erase_double(tmp);
				}
				return (_size);
			}

			void		erase(iterator position)
			{
				this->erase(position->first);
			}

			

			void erase (iterator first, iterator last)
			{
				for (iterator tmp = first; first != last; tmp++)
				{
					erase(first);
					first = tmp;
				}
			}

			void swap(map &x)
			{
				map tmp;

				tmp.copy_tree(x);
				x.copy_tree(*this);
				this->copy_tree(tmp);
			}

			void clear()
			{
				// node_type *right = last_right(_map);

				// if (_size == 0)
				// 	return ;
				// right->parent->right = NULL;
				// clear_tree(_map);
				// _map = right;
				// _size = 0;
				erase(this->begin(), this->end());
			}

			//OBSERVERS
			key_compare key_comp() const
			{
				return key_compare();
			}

			class value_compare
			{
				public:
					Compare comp;

					value_compare(Compare c): comp(c)
					{
					}

					virtual ~value_compare()
					{
					}

					bool operator()(const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}
			};

			value_compare value_comp() const
			{
				return value_compare(key_compare());
			}

			//MAP_OPERATIONS
			iterator find(const key_type &k)
			{
				iterator it = begin();
				iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp((*it).first, k) && !_key_cmp(k, (*it).first))
						break ;
					it++;
				}
				return it;
			}

			const_iterator find(const key_type &k) const
			{
				const_iterator it = begin();
				const_iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp((*it)->first, k) && !_key_cmp(k, (*it)->first))
						break ;
					it++;
				}
				return it;
			}

			size_type count(const key_type &k) const
			{
				size_t ret = 0;
				const_iterator it = begin();
				const_iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp((*it).first, k) && !_key_cmp(k, (*it).first))
					{
						ret++;
						break ;						
					}
					it++;
				}
				return ret;
			}

			iterator lower_bound(const key_type &k)
			{
				iterator it = begin();
				iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp((*it).first, k))
						break ;
					it++;
				}
				return it;
			}

			iterator lower_bound(const key_type &k) const
			{
				const_iterator it = begin();
				const_iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp((*it).first, k))
						break ;
					it++;
				}
				return it;
			}

			iterator upper_bound(const key_type &k)
			{
				iterator it = begin();
				iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp(k, (*it).first))
						break ;
					it++;
				}
				return it;
			}

			iterator upper_bound(const key_type &k) const
			{
				iterator it = begin();
				iterator it_end = end();

				while (it != it_end)
				{
					if (!_key_cmp(k, (*it)->first))
						break ;
					it++;
				}
				return it;
			}

			pair<iterator, iterator> equal_range(const key_type &k)
			{
				pair<iterator, iterator> ret;

				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}

			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				pair<const_iterator, const_iterator> ret;

				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}

			//ALLOCATOR
			allocator_type get_allocator() const
			{
				return	_alloc;
			}
	};
}

#endif
