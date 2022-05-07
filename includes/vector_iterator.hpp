#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
    template <class T>
    class vector_iterator
    {
        /* Type define */
        public:
            typedef T                               value_type;
            typedef size_t                          size_type;
            typedef long int                        difference_type;
        
            typedef value_type*                     pointer;
            typedef value_type&                     reference;

            typedef std::random_access_iterator_tag iterator_category;

        /* Member variable */
        private:
            pointer node;

        /* Constructor & Destructor */
        public:
            vector_iterator(pointer node = 0): node(node) {}
            vector_iterator(const vector_iterator &cls): node(cls.node) {}
            ~vector_iterator() {}

            vector_iterator &operator=(const vector_iterator &cls)
            {
                this->node = cls.node;
                return *this->node;
            }

        /* Operator overloading */
        public:
            reference operator[](difference_type num) const { return *this->node[num]; }
            reference operator*() const { return *this->node; }
            pointer operator->() const { return this->node; }

            vector_iterator &operator++() { ++this->node; return *this; }
            vector_iterator operator++(int) { vector_iterator tmp(*this); ++(*this); return tmp; }
            vector_iterator &operator--() { --this->node; return *this; }
            vector_iterator operator--(int) { vector_iterator tmp(*this); --(*this); return tmp; }

            vector_iterator operator+(difference_type num) const { vector_iterator tmp(*this); tmp += num; return tmp; }
            vector_iterator &operator+=(difference_type num) { this->node += num; return *this; }
            vector_iterator operator-(difference_type num) const { return *this + (-num); }
            vector_iterator &operator-=(difference_type num) { *this += -num; return *this; }

            bool operator==(const vector_iterator &cls) const { return this->node == cls.node; }
            bool operator!=(const vector_iterator &cls) const { return this->node != cls.node; }
            bool operator<(const vector_iterator &cls) const { return this->node < cls.node; }
            bool operator>(const vector_iterator &cls) const { return this->node > cls.node; }
            bool operator<=(const vector_iterator &cls) const { return this->node <= cls.node; }
            bool operator>=(const vector_iterator &cls) const { return this->node >= cls.node; }
    };
}

#endif