//
// Created by Ivo Georgiev on 5/2/16.
//

#include <iostream>
#include <cassert>
#include <limits>
#include <vector>


#include "TemplateTests.h"

#include "less_functor.h"

#include "custom_iterator.h"

using namespace Testing;

#define DESC(x) desc(x, __LINE__)  // ugly hack, but saves some time

using namespace CS2312;

// - - - - - - - - - - T E S T S - - - - - - - - - -

// - - - - - - - - - - L E S S - - - - - - - - - -

// less: smoke test
void test_less_smoketest(ErrorContext &ec) {
    bool pass;

    ec.DESC("--- Test - less - Smoketest ---");

    ec.DESC("instantiation, constructor, destructor");
    pass = true;

    class Widget {};

    for (int i = 0; i < 10; i++) {
        less<int> iless;
        less<unsigned> uless;
        less<float> fless;
        less<double> dless;
        less<const char *> cless;
        less<std::string> sless;
        less<Widget> wless;
    }
    ec.result(pass);
}

// less: usage
void test_less_usage(ErrorContext &ec, unsigned int numRuns) {
    bool pass;

    // Run at least once!!
    assert(numRuns > 0);

    ec.DESC("--- Test - less - Usage ---");

    for (int run = 0; run < numRuns; run ++) {

        ec.DESC("primitives");

        {
            less<int> iless;
            less<unsigned> uless;
            less<float> fless;
            less<double> dless;

            pass = true;
            pass = pass && iless(4, 5);
            pass = pass && uless(0, 50);
            pass = pass && fless(4.6, 5.3);
            pass = pass && dless(std::numeric_limits<double>::min(),
                                 std::numeric_limits<double>::max());

            ec.result(pass);
        }

        ec.DESC("C-strings");

        {
            less<const char *> cless;
            char c1[] = "efforts", c2[] = "goals";

            pass = true;
            pass = pass && cless(c1, c2);
            pass = pass && !cless("amalgama", "amaglama");

            ec.result(pass);
        }

        ec.DESC("std::string");

        {
            less<std::string> sless;
            std::string s1("alamosa"), s2("dolores");

            pass = true;
            pass = pass && sless(s1, s2);
            pass = pass && !sless(std::string("romel"), std::string("powell"));

            ec.result(pass);
        }

        ec.DESC("Widget");

        {
            class Widget {
                unsigned int __id;
            public:
                Widget(unsigned int id) : __id(id) {}
                bool operator<(const Widget &other) const {
                    return __id < other.__id;
                }
            };

            less<Widget> wless;
            Widget w1(345), w2(456), w3(98);

            pass = wless(w1, w2) && !wless(w2, w3);

            ec.result(pass);
        }
    }
}

// iterator: smoke test
void test_iterator_smoketest(ErrorContext &ec) {
    bool pass;

    ec.DESC("--- Test - iterator - Smoketest ---");

    ec.DESC("instantiation, constructor, destructor");
    pass = true;

    for (int i = 0; i < 10; i++) {

        // mutable object + iterator
        fixed_array<double> point3d(3);
        point3d[0] = 2.3;
        point3d[1] = 3.2;
        point3d[2] = 4.2;

        for (fixed_array<double>::iterator it = point3d.begin(); it != point3d.end(); ++it)
            ;

        for (auto it = point3d.begin(); it != point3d.end(); ++it)
            ;

        // const object + const_iterator
        const fixed_array<double> cpoint3d = { 2.3, 3.2, 4.2 };

        for (fixed_array<double>::const_iterator it = cpoint3d.begin(); it != cpoint3d.end(); ++it)
            ;

        for (auto it = cpoint3d.begin(); it != cpoint3d.end(); ++it)
            ;

    }
    ec.result(pass);
}

// iterator: usage
void test_iterator_usage(ErrorContext &ec, unsigned int numRuns) {
    bool pass;

    // Run at least once!!
    assert(numRuns > 0);

    ec.DESC("--- Test - iterator - Usage ---");

    for (int run = 0; run < numRuns; run++) {

        ec.DESC("T=double, mutable, explicit instantiation");

        {
            const size_t SIZE = 100;
            fixed_array<double> centenarray(SIZE);
            for (unsigned u = 0; u < SIZE; u++) centenarray[u] = 10.0 * u + 3.14;

            for (fixed_array<double>::iterator it = centenarray.begin(); it != centenarray.end(); ++it) {
                *it = *it + 10;
            }

            pass = true;
            unsigned u = 0;
            for (fixed_array<double>::iterator it = centenarray.begin(); it != centenarray.end(); ++it) {
                pass = pass && *it == 10.0 * (u++) + 13.14;
            }

            ec.result(pass);
        }

        ec.DESC("T=double, mutable, auto");

        {
            const size_t SIZE = 100;
            fixed_array<double> centenarray(SIZE);
            for (unsigned u = 0; u < SIZE; u++) centenarray[u] = 10.0 * u + 3.14;

            for (auto it = centenarray.begin(); it != centenarray.end(); ++it) {
                *it = *it + 10;
            }

            pass = true;
            unsigned u = 0;
            for (auto it = centenarray.begin(); it != centenarray.end(); ++it) {
                pass = pass && *it == 10.0 * (u++) + 13.14;
            }

            ec.result(pass);
        }

        ec.DESC("T=double, const, explicit instantiation");

        {
            const fixed_array<double> elevensies =
                    {3.14, 13.14, 23.14, 33.14, 43.14, 53.14, 63.14, 73.14, 83.14, 93.14, 103.14};

            pass = true;
            unsigned u = 0;
            for (fixed_array<double>::const_iterator it = elevensies.begin(); it != elevensies.end(); ++it) {
                pass = pass && *it == 10.0 * (u++) + 3.14;
            }

            ec.result(pass);
        }

        ec.DESC("T=double, const, auto");

        {
            const fixed_array<double> elevensies =
                    {3.14, 13.14, 23.14, 33.14, 43.14, 53.14, 63.14, 73.14, 83.14, 93.14, 103.14};

            pass = true;
            unsigned u = 0;
            for (auto it = elevensies.begin(); it != elevensies.end(); ++it) {
                pass = pass && *it == 10.0 * (u++) + 3.14;
            }

            ec.result(pass);
        }

        ec.DESC("compare with vector");

        {
            const size_t SIZE = 100;
            fixed_array<unsigned> mockarray(SIZE); // note: uninitialized

            // copy the values
            std::vector<unsigned> vectory;
            std::copy(mockarray.begin(), mockarray.end(), std::back_inserter(vectory));

            // compare
            pass = true;
            unsigned u = 0;
            for (auto mockelem: mockarray) {
                pass = pass && mockelem == vectory[u++];
            }

            // compare
            u = 0;
            for (auto vecelem: vectory) {
                pass = pass && mockarray[u++] == vecelem;
            }

            ec.result(pass);
        }

        ec.DESC("prefix vs postfix");

        {
            const size_t SIZE = 100;
            fixed_array<unsigned> mockarray(SIZE);
            for (auto &mockelem: mockarray) mockelem = 5;

            // test prefix
            auto it = mockarray.begin();
            auto last = mockarray.begin();
            for (unsigned u = 0; u < SIZE - 1; u++) last++;
            do {
                *(++it) = 3;
            } while (it != last);

            pass = mockarray[0] == 5;

            // test postfix
            mockarray[0] = 3;
            mockarray[SIZE - 1] = 7;

            it = mockarray.begin();
            last = mockarray.begin();
            for (unsigned u = 0; u < SIZE - 1; u++) last++;
            while (it != last) {
                pass = pass && *(it++) == 3;
            }

            ec.result(pass);
        }

        ec.DESC("Widgets");

        {
            class Widget {
                unsigned __id;
            public:
                Widget() {}
                void setId(unsigned id) { __id = id; }
                unsigned getId() const { return __id; }
            };

            const size_t SIZE = 10;
            fixed_array<Widget> figets(SIZE);

            unsigned u = 0;
            for (auto it=figets.begin(); it != figets.end(); ++it)
                it->setId(u);

            pass = true;
            u = 0;
            for (auto it=figets.begin(); it != figets.end(); ++it)
                pass = pass && it->getId() == u;

            ec.result(pass);
        }
    }
}
