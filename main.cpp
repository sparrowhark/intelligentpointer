/**
 * @file main.cpp
 * @synopsis:
 * @author stone
 * @version 1.0
 * @date 2016-10-17
 * Copyright(C) 2016 <stone>All right reserved
 */

#include <stdlib.h>
#include "./unittest/example_test.h"

#ifdef DEBUG
int test() {
// Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that colllects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  // Add a listener that print dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);
  return result.wasSuccessful() ? 0 : 1;
}

#endif

int main(int argc , char **argv) {
#ifdef DEBUG
  return test();
#else
  return 0;
#endif
}



