/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/08 00:24:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include	"../utils.hpp"
# include	"./iterators/iterator_m.hpp"
# include	"./iterators/const_iterator_m.hpp"
# include	"./iterators/reverse_iterator_m.hpp"
# include	"./iterators/const_reverse_iterator_m.hpp"

# ifndef	__APPLE__
# 	define	__APPLE__ 0
# endif

template <typename Tpair>
struct	node
{
	private:
		
		bool	_unused;
		#if __APPLE__ == 0
			int	_unused_for_linux;
		#endif

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
node<T>	*far_right(node<T> *node)
{
	while (node->right)
		node = node->right;
	return	node;
}

template <typename T>
node<T>	*far_left(node<T> *node)
{
	while (node->left)
		node = node->left;
	return	node;
}

template <typename Tpair>
std::ostream	&operator<<(std::ostream &o, node<Tpair> const &i)
{
	std:: cout << \
	"curr = " << i.get_curr() << std::endl << \
	"top = " << i.get_top() << std::endl << \
	"left = " << i.get_left() << std::endl << \
	"right = " << i.get_right() << std::endl << \
	"value = " << i.get_pair() << std::endl;
	return	0;
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

			Tkey	first;
			Tkey	second;

			pair(void)
			{
			}

			template <class X, class Y>
			pair (const pair<X, Y> &src)
			{
				this->first = src.first;
				this->second = src.second;
			};

			pair(cosnt Tkey &k, const Tvalue &v): first(a), second(b)
			{
			}

			~pair()
			{
			}

			pair	&operator=(const pair &src)
			{
				this->first = src.first;
				this->scond = src.second;				
				return	*this;
			}
	};
}

#endif
