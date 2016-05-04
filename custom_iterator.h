//
// Created by Ivo Georgiev on 5/3/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
#define UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H

// Naive partial implementation of a custom iterator.
// After Jeet Sukumaran https://github.com/jeetsukumaran

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace CS2312 {

    template <typename T>
    class fixed_array {

    public:

        typedef std::size_t size_type;

        class iterator {

        public:

            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            iterator(pointer ptr);
            self_type operator++();
            self_type operator++(int junk);
            reference operator*();
            pointer operator->();
            bool operator==(const self_type& rhs) const;
            bool operator!=(const self_type& rhs) const;

        private:

            pointer __ptr;

        };

        class const_iterator {

        public:

            typedef const_iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            const_iterator(pointer ptr);
            self_type operator++();
            self_type operator++(int junk);
            const value_type& operator*() const;
            const value_type* operator->() const;
            bool operator==(const self_type& rhs) const;
            bool operator!=(const self_type& rhs) const;

        private:

            pointer __ptr;

        };


        fixed_array(size_type size);

        fixed_array(std::initializer_list<T> list);

        ~fixed_array();

        size_type size() const;

        T& operator[](size_type index);

        const T& operator[](size_type index) const;

        iterator begin();

        iterator end();

        const_iterator begin() const;

        const_iterator end() const;

    private:

        T* __data;
        size_type __size;

    };

}

#endif //UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
