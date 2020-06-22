#!/bin/bash
../TESTS/test_suite
find .. -name *.gcno | xargs gcov
lcov -c -d .. -o coverage.info
lcov --remove coverage.info '/usr/local/include/*' '/usr/include/*' '*/TESTS/*' -o coverage.info
genhtml coverage.info  --output-directory out
rm -rf *.gcov
