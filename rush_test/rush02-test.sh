#!/bin/bash

red=$(tput setaf 1)
reset=$(tput sgr0)


nums=()
rush="$1"

if [ $# -eq 0 ]
then
	echo "${red}Usage: $0 <rush binary> <all | bignum | invalid>${reset}"
	exit 1
fi

[[ "$1" == */* ]] && rush="$1" || rush="./$1"

if [ "$2" == "all" ]
then
	nums+=(42 0 1 2 10000 20 666 13 420000 1000000000 20000000000)
fi

if [ "$2" == "bignum" ] || [ "$2" == "all" ]
then
	nums+=(1000000000000 1000000000000000 1000000000000000000 1000000000000000000000 1000000000000000000000000 \
 	1000000000000000000000000000 1000000000000000000000000000000000 1000000000000000000000000000000000000)
fi

if [ "$2" == "invalid" ] || [ "$2" == "all" ]
then
	nums+=(0.5 -5 "hello" "0")
fi

for i in "${nums[@]}"; do
	echo "${red}" Current input: "$i" "${reset}"
	"$rush" "$i" | cat -e
done