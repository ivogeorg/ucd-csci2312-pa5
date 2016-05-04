//
// Created by Ivo Georgiev on 5/2/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_TEMPLATETESTS_H
#define UCD_CSCI2312_PA5_IMPL_TEMPLATETESTS_H

#include "ErrorContext.h"

using namespace Testing;

// - - - - - - - - - Tests: class less - - - - - - - - - -

// less: smoke test
void test_less_smoketest(ErrorContext &ec);

// less: usage
void test_less_usage(ErrorContext &ec, unsigned int numRuns);

// - - - - - - - - - Tests: class iterator - - - - - - - - - -

// iterator: smoke test
void test_iterator_smoketest(ErrorContext &ec);

// iterator: usage
void test_iterator_usage(ErrorContext &ec, unsigned int numRuns);

#endif //UCD_CSCI2312_PA5_IMPL_TEMPLATETESTS_H
