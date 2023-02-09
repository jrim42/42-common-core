#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
// # include <vector>

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

namespace ft
{
    template <typename T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container                                   container_type;
            typedef typename container_type::value_type         value_type;
            typedef typename container_type::reference          reference;
            typedef typename container_type::const_reference    const_reference;
            typedef typename container_type::size_type          size_type;
        
        protected:
            container_type  c;

        public:
            // OCCF
            explicit stack(const container_type& container = container_type()) 
                : c(container) {}
            stack(const stack& ref) 
                : c(ref.c) {}
            ~stack(void) {}
            stack& operator=(const stack& ref) 
            {
                if (this != &ref)
                    c = ref.c;
                return (*this);
            }

            // operators
            reference       top(void)                       { return c.back(); }
            const_reference top(void) const                 { return c.back(); }
            bool            empty(void) const               { return c.empty(); }
            size_type       size(void) const                { return c.size(); }
            void            push(const value_type& val)     { c.push_back(val);}
            void            pop(void)                       { c.pop_back(); }

            // boolean operators
            friend bool operator==(const stack& a, const stack& b)  { return (a.c == b.c); }
            friend bool operator!=(const stack& a, const stack& b)  { return (a.c != b.c); }
            friend bool operator>(const stack& a, const stack& b)   { return (a.c > b.c); }
            friend bool operator>=(const stack& a, const stack& b)  { return (a.c >= b.c); }
            friend bool operator<(const stack& a, const stack& b)   { return (a.c < b.c); }
            friend bool operator<=(const stack& a, const stack& b)  { return (a.c <= b.c); }
    }; // end of class stack
}  // end of namespace ft

#endif