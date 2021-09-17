/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/17 17:20:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include	<limits>
# include	"../utils.hpp"
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
	while (node->right)
		node = node->right;
	return	node;
}

template <typename T>
node<T>	*last_left(node<T> *node)
{
	while (node->left)
		node = node->left;
	return	node;
}

template <typename Tpair>
std::ostream	&operator<<(std::ostream &o, node<Tpair> const &p)
{
	std:: cout << \
	"curr = " << p.get_curr() << std::endl << \
	"top = " << p.get_top() << std::endl << \
	"left = " << p.get_left() << std::endl << \
	"right = " << p.get_right() << std::endl << \
	"value = " << p.get_pair() << std::endl;
	return	o;
}

namespace ft
{
	template <class T>
	struct	less
	{
		bool	operator()(const T &lhs, const T &rhs) const
		{
			return lhs < rhs;
		}
	};

	//-------- PAIR CLASS --------

	template <typename Tkey, typename Tval>
	class	pair
	{
		public:

			pair(void)
			{
			}

			template <class X, class Y>
			pair (const pair<X, Y> &p)
			{
				this->first = p.first;
				this->second = p.second;
			};

			pair(const Tkey &k, const Tval &v): first(k), second(v)
			{
			}

			~pair()
			{
			}

			pair	&operator=(const pair &p)
			{
				this->first = p.first;
				this->second = p.second;				
				return	*this;
			}

			Tkey	first;
			Tkey	second;
	};

	template <typename Tkey, typename Tvalue>
	std::ostream	&operator<<(std::ostream &o, pair <Tkey, Tvalue> const &p)
	{
		std::cout << "Key = " << p.first << ", Value = " << p.second << " ";
		return	o;
	}

	template <class T1, class T2>
	bool			operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool			operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(lhs == rhs);
	}

	template <class T1, class T2>
	bool			operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool			operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	rhs < lhs;
	}

	template <class T1, class T2>
	bool			operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(rhs < lhs);
	}

	template <class T1, class T2>
	bool			operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(lhs > rhs);
	}

	//-------- MAP CLASS --------

	template <class Tkey, class Tvalue, class Compare = ft::less<Tkey>, class Alloc = std::allocator<pair<const Tkey, Tvalue> > >
	class map
	{
		public:

			typedef Tkey								key_type;
			typedef Tvalue								map_value;
			typedef ft::pair<key_type, map_value>		value_type;
			typedef node<value_type>					node_type;
			typedef Compare								key_compare;
			typedef std::allocator<value_type>			allocator_type;
			
			typedef value_type							&reference;
			typedef reference						const_reference;
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
			size_type			_size;
			allocator_type		_alloc;
			key_compare			_key_cmp;

			void	add_node(node_type	*n)
			{
				node_type	**parent = &_map;
				node_type	**node = &_map;
				node_type	*right = last_right(_map);
				bool		left = -1;
				
				while (*node && *node != right)
				{
					parent = node;
					left = _key_cmp(n->value.first, (*node)->value.first);
					if (left)
						node = &(*node)->left;
					else
						node = &(*node)->right;
				}
				if (*node == NULL)
				{
					n->parent = (*parent);
					*node = n;
				}
				else
				{
					*node = n;
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

		public:

			//CONSTRUCTORS
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_map = new node_type();
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
				_size = 0;
				_alloc = alloc;
				_key_cmp = comp;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(), 
				typename ft::enable_if<InputIterator::is_iterator, InputIterator>::type = NULL)
			{
				_map = new node_type();
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
				_size = 0;
				_alloc = 0;
				_key_cmp = comp;
				insert(first, last);
			}

			map &operator=(map const &m)
			{
				if (_size > 0)
					clear();
				if (m.size() > 0)
					insert(m.begin(), m.end());
				return	*this;
			}

			map(const map &x)
			{
				_map = new node_type();
				_map->left = NULL;
				_map->right = NULL;
				_map->parent = NULL;
				_size = 0;
				_alloc = allocator_type();
				_key_cmp = key_compare();
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
				return	(insert(value_type(k, map_value()))).first->second;
			}

			//MODIFIERS
			pair<iterator, bool>	insert(const value_type &val)
			{
				ft::pair<iterator, bool>	ret;
				value_type					new_pair(val);
				node_type					*new_node = new node_type();

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
	};
}

#endif
