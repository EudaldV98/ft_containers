/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 18:30:41 by jvaquer          ###   ########.fr       */
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


template <typename Tpair>
struct node
{
	public:

		Tpair	value;
		node	*parent;
		node	*left;
		node	*right;

	//CONSTRUCTORS
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
			typedef ft::pair<key_type, map_value>						value_type;
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
			node<value_type>	*_upper;
			node<value_type>	*_lower;
			node<value_type>	*_fake_begin;
			node<value_type>	*_fake_end;
			size_type			_size;
			allocator_type		_alloc;
			nodeAlloc			_node_alloc;
			key_compare			_key_cmp;

			void	add_node(node_type	*n)
			{
				node_type	**parent = &_map;
				node_type	**ptr = &_map;
				node_type	*right = last_right(_map);
				bool		left = -1;
				
				while (*ptr && *ptr != right)
				{
					parent = ptr;
					left = _key_cmp(n->value.first, (*ptr)->value.first);
					if (left)
						ptr = &(*ptr)->left;
					else
						ptr = &(*ptr)->right;
				}
				if (*ptr == NULL)
				{
					n->parent = (*parent);
					*ptr = n;
				}
				else
				{
					*ptr = n;
					n->parent = right->parent;
					right->parent = last_right(n);
					last_right(n)->right = right;
				}
				_size++;
			}

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
				value_type	val;

				val.first = key;
				val.second = 0;
				if (_size == 0)
					return (NULL);
				while (true)
				{
					if (tmp->value.first == val.first)
						return (tmp);
					if (value_comp()(val, tmp->value))
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
					_size = 0;
					return ;
				}
				if (leaf->parent && value_comp()(leaf->value, leaf->parent->value))
					leaf->parent->left = NULL;
				else
				{
					if (leaf->right == last_right(_map))
						leaf->parent->right = last_right(_map);
					else
						leaf->parent->right = NULL;
				}
				delete leaf;
				leaf = NULL;
				// set_upper();
				// set_lower();
				_size--;
			}

			void		erase_single(node_type *single)
			{
				if (single->left && (!single->right || single->right == last_right(_map)))
				{
					if (single->parent && value_comp()(single->value, single->parent->value))
						single->parent->left = single->left;
					else if (single->parent)
						single->parent->right = single->left;
					if (_map == single)
					{
						_map = single->left;
						single->left->parent = NULL;
					}
					else
						single->left->parent = single->parent;
				}
				else if (single->right && single->right != last_right(_map) && !single->left)
				{
					if (single->parent && value_comp()(single->value, single->parent->value))
						single->parent->left = single->right;
					else if (single->parent)
						single->parent->right = single->right;
					single->right->parent = single->parent;
					if (single == _map)
						_map = single->right;
				}
				delete single;
				single = NULL;
				// set_upper();
				// set_lower();
				_size--;
			}

			void		erase_double(node_type *node)
			{
				node_type *near = node;
				node_type *traverser;
				value_type	tmp;

				near = near->left;
				while (near->right)
					near = near->right;
				if (node->parent)
				{
					if (value_comp()(node->value, node->parent->value))
						node->parent->left = near;
					else
						node->parent->right = near;
					near->parent = node->parent;
					node->parent = NULL;
				}
				near->right = node->right;
				near->right->parent = near;
				node->right = NULL;
				if (near->parent->value.first != node->value.first)
				{
					if (near->left)
					{
						traverser = near->left;
						while (traverser->left)
							traverser = traverser->left;
						traverser->left = node->right;
						node->left->parent = traverser;
					}
				}
				if (node == _map)
				{
					_map = near;
					near->parent = NULL;
				}
				delete node;
				node = NULL;
				_size--;
			}

		public:

			//CONSTRUCTORS
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_map = NULL;
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
				_size = 0;
				_alloc = alloc;
				_key_cmp = comp;

				_fake_begin = new node_type();
				_fake_begin->left = NULL;
				_fake_begin->right = NULL;
				_fake_end = _fake_begin;

				_lower = _fake_begin;
				_upper = _fake_end;
			}

			template <class InputIt>
			map(InputIt first, typename ft::enable_if<InputIt::is_iterator, InputIt>::type last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_map = new node_type();
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
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
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
				_size = 0;
				_alloc = allocator_type();
				_key_cmp = key_compare();
				
				_fake_begin = new node_type();
				_fake_begin->left = NULL;
				_fake_begin->right = NULL;
				_fake_end = _fake_begin;

				_lower = _fake_begin; //ou NULL?
				_upper = _fake_end; //ou NULL?

				*this = x;
			}

			virtual	~map()
			{
				if (empty() == 0)
					clear();
			}

			//ITERATORS
			iterator				begin()
			{
				return	iterator(last_left(_map));
			}

			const_iterator			begin() const
			{
				return	const_iterator(last_left(_map));
			}

			iterator				end()
			{
				return	iterator(last_right(_map));
			}

			const_iterator			end() const
			{
				return	const_iterator(last_right(_map));
			}

			reverse_iterator 		rbegin()
			{
				return	reverse_iterator(--end());
			}

			const_reverse_iterator	rbegin() const
			{
				return	const_reverse_iterator(rbegin());
			}

			reverse_iterator		rend()
			{
				return	reverse_iterator(begin());
			}

			const_reverse_iterator	rend() const
			{
				return	const_reverse_iterator(begin());
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

			//ELEMENT ACCESS
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
				ft::pair<iterator, bool> ret;
				value_type new_pair(val);
				node_type *new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, node_type());
				//node_type					*new_node = new node_type();

				if (_size > 0 && count(val.first) == 1)
				{
					ret.second = false;
					return	ret;
				}

				new_node->value = new_pair;
				new_node->left = NULL;
				new_node->right = NULL;
				new_node->parent = NULL;

				add_node(new_node);
				ret.first = find(val.first);
				return	ret;
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
					if ((!tmp->left && !tmp->right) ||
										(!tmp->left && tmp->right == last_right(_map)))
						erase_leaf(tmp);
					else if ((tmp->left && (!tmp->right || tmp->right == last_right(_map))) ||
							(tmp->right && tmp->right != last_right(_map) && !tmp->left))
						erase_single(tmp);
					else
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
				node_type *right = last_right(_map);

				if (_size == 0)
					return ;
				right->parent->right = NULL;
				clear_tree(_map);
				_map = right;
				_size = 0;
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
					if (!_key_cmp((*it).first, k) && !_key_cmp(k, (*it).first))
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
					if (!_key_cmp(k, (*it).first))
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
	};
}

#endif
