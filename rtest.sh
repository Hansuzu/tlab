#!/bin/bash
rm test/coverage_files/*.*
rm test/coverage_files/tmp/*.*

./test_usuffix.sh
./test_fastset.sh
./test_vector.sh
./test_bitset.sh
./test_pair.sh

mv test/coverage_files/*.* test/coverage_files/tmp

mv test/coverage_files/tmp/bitset.h.gcov test/coverage_files
mv test/coverage_files/tmp/vector.h.gcov test/coverage_files
mv test/coverage_files/tmp/fastset.h.gcov test/coverage_files
mv test/coverage_files/tmp/pair.h.gcov test/coverage_files
mv test/coverage_files/tmp/usuffix.h.gcov test/coverage_files
mv test/coverage_files/tmp/usuffix.cpp.gcov test/coverage_files
mv test/coverage_files/tmp/usuffixnode_vector.cpp.gcov test/coverage_files

echo "Code coverage raports are in test/coverage_files/[FILENAME].gcov"
echo " There is the number of times each line was executed"
echo " - means line is optimized away"
echo " ##### means line was not executed"
echo " check man page for gcov for more details."
