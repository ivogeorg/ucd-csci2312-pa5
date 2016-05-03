//
// Created by Ivo Georgiev on 5/2/16.
//

#include <iostream>
#include <cassert>
#include <limits>

#include "TemplateTests.h"
#include "less_functor.h"

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

    ec.DESC("--- Test - less - usage ---");

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

            pass = true;
            pass = pass && cless("efforts", "goals");
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

