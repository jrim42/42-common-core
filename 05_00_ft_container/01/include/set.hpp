#ifndef SET_HPP
#define SET_HPP

# include <functional>
# include <memory>

# include "./compare.hpp"
# include "./pair.hpp"
# include "./rbtree.hpp"
# include "./reverse_iterator.hpp"

namespace ft 
{
	template <typename T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set 
	{
		public:
			typedef T 				key_type;
			typedef T 				value_type;
			typedef Compare 		compare_type;
			typedef Compare 		key_compare;
			typedef Compare 		value_compare;

			typedef Allocator 														allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other		type_allocator;
			typedef std::allocator_traits<type_allocator> 							type_traits;
			typedef typename type_traits::pointer 									pointer;
			typedef typename type_traits::const_pointer 							const_pointer;
			typedef value_type& 													reference;
			typedef const value_type& 												const_reference;

			typedef std::size_t 													size_type;
			typedef std::ptrdiff_t 													difference_type;

			typedef typename ft::rbtree<const value_type, key_type, value_compare, allocator_type>::iterator			iterator;
			typedef typename ft::rbtree<const value_type, key_type, value_compare, allocator_type>::const_iterator 		const_iterator;
			typedef ft::reverse_iterator<iterator> 																		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 																const_reverse_iterator;

		private:
			compare_type															_comp;
			allocator_type 															_alloc;
			ft::rbtree<const value_type, key_type, value_compare, allocator_type> 	_rbt;

		public:
			// constructor & destructor
			explicit set(const compare_type& comp = compare_type(),
						 const allocator_type& alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _rbt(comp, alloc) {}
			template <class iIter>
			set(iIter first, iIter last, const compare_type& comp = compare_type(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<iIter>::val>::type* = NULL)
				: _comp(comp), _alloc(alloc), _rbt(comp, alloc) 
			{
				insert(first, last);
			}
			set(const set& ref)
				: _comp(ref._comp), _alloc(ref._alloc), _rbt(ref._rbt) {}
			~set(void) {}

			// assignment operator
			set& operator=(const set& ref) 
			{
				if (this != &ref) 
				{
					_comp = ref._comp;
					_alloc = ref._alloc;
					_rbt = ref._rbt;
				}
				return *this;
			}

			// iterators
			iterator				begin(void)			{ return _rbt.begin(); }
			const_iterator			begin(void) const	{ return _rbt.begin(); }
			iterator 				end(void)			{ return _rbt.end(); }
			const_iterator 			end(void) const		{ return _rbt.end(); }
			reverse_iterator 		rbegin(void)		{ return reverse_iterator(end()); }
			const_reverse_iterator 	rbegin(void) const	{ return reverse_iterator(end()); }
			reverse_iterator 		rend(void)			{ return reverse_iterator(begin()); }
			const_reverse_iterator	rend(void) const	{ return reverse_iterator(begin()); }

			// size: size, max_size, empty
			bool		empty(void) const 				{ return _rbt.empty(); }
			size_type	size(void) const 				{ return _rbt.size(); }
			size_type	max_size(void) const			{ return _rbt.max_size(); }

			// modifiers: insert, erase, swap, clear
			ft::pair<iterator, bool>	insert(const value_type& val) 					{ return _rbt.insert(val); }
			iterator 					insert(iterator pos, const value_type& val) 	{ return _rbt.insert(pos, val); }
			template <class iIter>
			void						insert(iIter first, iIter last) 				{ _rbt.insert(first, last); }
			void 		erase(iterator pos)												{ _rbt.erase(pos); }
			void 		erase(iterator first, iterator last) 							{ _rbt.erase(first, last); }
			size_type 	erase(const value_type& val) 									{ return _rbt.erase(val); }
			void 		swap(set& s)													{ _rbt.swap(s._rbt); }
			void 		clear(void)														{ _rbt.clear(); }

			// comp & allocator
			key_compare		key_comp(void) const 		{ return _comp; }
			value_compare 	value_comp(void) const 		{ return _comp; }
			allocator_type 	get_allocator(void) const 	{ return _rbt.get_allocator(); }
			
			// 
			iterator 					find(const value_type& val) const 			{ return _rbt.find(val); }
			size_type 					count(const value_type& val) const 			{ return !(find(val) == end()); }
			iterator 					lower_bound(const value_type& val) const	{ return _rbt.lower_bound(val); }
			iterator 					upper_bound(const value_type& val) const	{ return _rbt.upper_bound(val); }
			pair<iterator, iterator>	equal_range(const value_type& val) const	{ return _rbt.equal_range(val); }
	}; // end of class set

	// comparison operators
	template <class T, class Compare, class Allocator>
	bool operator==(const ft::set<T, Compare, Allocator>& x,
					const ft::set<T, Compare, Allocator>& y) 
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class T, class Compare, class Allocator>
	bool operator!=(const ft::set<T, Compare, Allocator>& x,
					const ft::set<T, Compare, Allocator>& y) 
	{
		return !(x == y);
	}

	template <class T, class Compare, class Allocator>
	bool operator<(const ft::set<T, Compare, Allocator>& x,
				   const ft::set<T, Compare, Allocator>& y) 
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Compare, class Allocator>
	bool operator<=(const ft::set<T, Compare, Allocator>& x,
					const ft::set<T, Compare, Allocator>& y) 
	{
		return !(y < x);
	}

	template <class T, class Compare, class Allocator>
	bool operator>(const ft::set<T, Compare, Allocator>& x,
				   const ft::set<T, Compare, Allocator>& y) 
	{
		return y < x;
	}

	template <class T, class Compare, class Allocator>
	bool operator>=(const ft::set<T, Compare, Allocator>& x,
					const ft::set<T, Compare, Allocator>& y) 
	{
		return !(x < y);
	}

	template <typename T, class Compare, class Allocator>
	void swap(ft::set<T, Compare, Allocator>& x,
			  ft::set<T, Compare, Allocator>& y) 
	{
		x.swap(y);
	}

} // end of  namespace ft

#endif