#!/bin/bash

# script for tests

program="proj1"
numbers="empty colon_no_space Id_with_number"
diffopts=" -a -i -b -w -B "  # ignore whitespace
testdir="tests"

g++ -Wall -std=c++17 -g *.cpp -o $program

for number in $numbers ; do
 
    echo "Running input" $number

    inputfile=$testdir/$number.txt
    answerfile=$testdir/EXPECT_$number.txt
    outputfile=actual$number.txt

    ./$program $inputfile > $outputfile

    diff $diffopts $answerfile $outputfile || echo "diff failed on test" $number

    rm $outputfile

done

rm $program

