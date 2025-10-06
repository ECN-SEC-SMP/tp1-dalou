#!/bin/bash

this_dir=$(dirname "$(realpath "$0")")
error_flag=0

for test_file in "$this_dir"/../build/bin/test_*; do
    if [[ -x "$test_file" ]]; then
        "$test_file"
        if [ $? -ne 0 ]; then 
            error_flag=1
        fi
    fi
done

if [ $error_flag -ne 0 ]; then
    echo -e "\n\033[31mSome test has failed!\033[0m\n"
fi
