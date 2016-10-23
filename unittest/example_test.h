/**
 * @file example_test.h
 * @synopsis:
 * @author stone
 * @version 1.0
 * @date 2016-10-17
 * Copyright(C) 2016 <stone> All right reserved
 */
#ifndef UNITTEST_EXAMPLE_TEST_H_
#define UNITTEST_EXAMPLE_TEST_H_

#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class Test : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testHelloWorld);
    CPPUNIT_TEST_SUITE_END();

 public:
    void setUp(void) {}
    void tearDown(void) {}

 protected:
    void testHelloWorld(void) { std::cout << "Hello, world!" << std::endl; }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test);

#endif   // UNITTEST_EXAMPLE_TEST_H_
