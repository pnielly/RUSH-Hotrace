#!/bin/bash

#Colors
YELLOW="\e[33m"
NC="\e[0m"

DIR=new-tests

TEST1=example.htr
TEST2=example3.htr
TEST3=example3_10_000_not_found.htr
TEST4=overwrite_50_000_same.htr
TEST5=overwrite_50_000_different.htr
TEST6=store_long_string_10.htr
TEST7=search_long_string_20.htr

make re

printf "${YELLOW}$TEST1${NC}"
time ./hotrace < $DIR/$TEST1 > out/out1

printf "${YELLOW}$TEST2${NC}"
time ./hotrace < $DIR/$TEST2 > out/out2

printf "${YELLOW}$TEST3${NC}"
time ./hotrace < $DIR/$TEST3 > out/out3

printf "${YELLOW}$TEST4${NC}"
time ./hotrace < $DIR/$TEST4 > out/out4

printf "${YELLOW}$TEST5${NC}"
time ./hotrace < $DIR/$TEST5 > out/out5

printf "${YELLOW}$TEST6${NC}"
time ./hotrace < $DIR/$TEST6 > out/out6

printf "${YELLOW}$TEST7${NC}"
time ./hotrace < $DIR/$TEST7 > out/out7
