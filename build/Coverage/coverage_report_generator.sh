#!/bin/bash
../TESTS/test_suite
find .. -name *.gcno | xargs gcov
lcov -c -d .. -o coverage.info
genhtml coverage.info  --output-directory out
rm -rf *.gcov
