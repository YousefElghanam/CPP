#!/bin/bash

make re CXXFLAGS='-DCHECK_RES=1 -O3'

test_number=0
log_file="pmerge_failures.log"
 
> "$log_file"
 
for count in $(seq 25000 70000); do
    for run in $(seq 1 5); do
        test_number=$((test_number + 1))
        prompt=$(shuf -i 1-200000 -n "$count" | tr '\n' ' ')
        ./PmergeMe $prompt > /dev/null
        if [ $? -eq 1 ]; then
            echo "Test $test_number (count=$count, run=$run): FAIL -- ./PmergeMe $prompt"
            echo "Test $test_number (count=$count, run=$run): FAIL -- ./PmergeMe $prompt" >> "$log_file"
        else
            echo "Test $test_number (count=$count, run=$run): PASS"
        fi
    done
done
 
echo ""
echo "Done. Failures saved to $log_file"
 