//
// Created by HosZul on 5/6/2016.
//

// Complete

#ifndef UCD_CSCI2312_PA5_LESS_FUNCTOR_H
#define UCD_CSCI2312_PA5_LESS_FUNCTOR_H

namespace CS2312
{
    // Less Template
    template<typename T>
    class less
    {
    public:
        bool operator()(const T &one, const T &two)
        {
            return(one < two);
        }
    };

    // Specialize
    template<>
    class less <const char *>
    {
    public:
        bool operator()(const char *one, const char *two)
        {
            string stringOne, stringTwo;

            stringOne = one;
            stringTwo = two;

            return (stringOne < stringTwo);
        };
    };

}
#endif //UCD_CSCI2312_PA5_LESS_FUNCTOR_H
