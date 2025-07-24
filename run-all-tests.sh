#!/bin/bash

echo "Running wcat tests..."
cd test-wcat && bash test-wcat.sh && cd ..

echo "Running wgrep tests..."
cd test-wgrep && bash test-wgrep.sh && cd ..

echo "Running wzip tests..."
cd test-wzip && bash test-wzip.sh && cd ..

echo "Running wunzip tests..."
cd test-wunzip && bash test-wunzip.sh && cd ..

echo "All tests completed."

