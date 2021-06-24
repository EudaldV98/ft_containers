/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/24 18:21:55 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "./includes/pair.hpp"
# include "./includes/iterator_m.hpp"
# include "./includes/ReverseBidirectionalIterator_m.hpp"
# include <utility>
# include <climits>
# include <iostream>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key> >	
	class map
	{
		public:

			//values
			typedef Key							key_type;
			typedef	T							mapped_type;
			typedef	Pair<key_type, mapped_type>	value_type;
			typedef	Compare						key_compare;
			
			//refs & ptr
			typedef value_type			& reference;
			typedef	const value_type	& const_reference;
			typedef value_type			* pointer;
			typedef const value_type	* const_pointer;
			
			//iterators
			typedef Iterator_m <value_type>					iterator;
			typedef const Iterator_m <value_type>			const_iterator;
			typedef	ReverseIterator_m <value_type>			reverse_iterator;
			typedef const ReverseIterator_m <value_type>	const_reverse_iterator;

			//aux types
			typedef	ptrdiff_t	diff_type;
			typedef	size_t		size_type;

			class	value_compare : std::binary_function<value_type, value_type, bool>
			{
				public:
					bool operator()(const value_type &x, const value_type &y) const
					{
						return	comp(x.first, y.first);
					}
				
				private:
					Compare comp:
					value_compare(Compare c)
					{
						this->comp = c;
					}
					friend class map;
			};
		
		private:

			typedef node_m<value_type>	node_m;
			key_compare					_comp;
			node_m						*_top;
			node_m						*_lower;
			node_m						*_higher;
			size_type					_size;

			node_m	*find_node(key_type	key)
			{
				node_m		*tmp = _top;
				value_type	value;

				value.first = key;
				value.second = 0;
				if (_size == 0)
					return NULL;
				while (true)
				{
					if (tmp->value.first == value.first)
						return tmp;
					if (value_comp() (value, tmp->value))
					{
						tmp->left ? tmp = tmp->right : break;
					}
					else
					{
						tmp->right ? tmp = tmp->right : break;
					}
				}
				return NULL;
			}

			void	erase_leaf(node_m *leaf)
			{
				if (_size == 1)
				{
					delete	leaf;
					leaf = NULL;
					_top = NULL;
					delete _higher;
					delete _lower;
					_higher = NULL;
					_lower = NULL;
					_size = 0;
					return ;
				}
				if (leaf->parent && value_comp()(leaf->value, leaf->parent->value))
					leaf->parent->left = NULL;
				else if (leaf->right == _higher)
					leaf->parent->right = _higher;
				else
					leaf->parent->right = NULL;
				delete ;
				leaf = NULL;
				_size--;
				set_higher();
				set_lower();
			}

			void	del_one(node_m *node)
			{
				if (node->left && (!node->right || node->right == _higher))
				{
					if (node->parent && value_comp()(node->value, node->parent->value))
						node->parent->left = node->left;
					else if (node->parent)
						node->parent->right = node->left;
					if (_top == node)
					{
						_top = node->left;
						node->left->parent = NULL;
					}
					else
						node->left->parent = node->parent;
				}
				else if (node->right && node->right != _higher && !node->left)
				{
					if (node->parent && value_comp()(node->value, node->parent->value))
						node->parent->left = node->right;
					else if (node->parent)
						node->parent->right = node->right;
					node->right->parent = node->parent;
					if (_top == node)
						_top = node->right;
				}
				delete node;
				node = NULL;
				set_higher();
				set_lower();
				_size--;
			}

			void	del_two()
			{
				
			}

		public:
			
			explicit map(const key_compare &comp = key_compare())
			{
				_top = NULL;
				_size = 0;
				_comp = comp;
				_higher = NULL;
				_lower = NULL;
			}

			map (const map &m)
			{
				_top = new node_m(m._top);
				_size = m._size;
				_comp = m._comp;
				_lower = m._bottom;
				_higher = new node_m(m._up);
			}

			~map()
			{
				clear();
			}

			

	};
}

#endif
