#!/bin/bash

gcc jodufour.c -o jodufour
gcc wlo.c -o wlo

echo -e "\n\e[32mjodufour's one\e[0m"
time ./jodufour
echo ''
echo -e "\e[33mwlo's one\e[0m"
time ./wlo
rm jodufour wlo
