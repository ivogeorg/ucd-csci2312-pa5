//
// Created by Taylor on 5/2/2016.
//

#ifndef UCD_CSCI2312_PA5_IMPL_LESS_FUNCTOR_H
#define UCD_CSCI2312_PA5_IMPL_LESS_FUNCTOR_H

#include <string>

namespace CS2312{

    template <typename T>
    class less {
    public:
        bool operator() (const T &a, const T &b){
            return (a < b);         //true if first item passed is less than second item
        }
    };

    //specialized templates for c-strings and strings.
    template <>
    class less<string> {
    public:
        bool operator() (const string &a, const string &b){
            return (a < b);
        }
    };
    template<>
    class less<const char *>{
    public:
        bool operator() (const char *a, const char *b){
            string s1 = a, s2 = b;  //can't compare char *'s
            return (s1 < s2);
        }
    };

}
#endif //UCD_CSCI2312_PA5_IMPL_LESS_FUNCTOR_H
