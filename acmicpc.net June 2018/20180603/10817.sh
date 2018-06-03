#!/bin/bash
read a b c
secondMax() {
	if (( $1 >= $2 && $2 >= $3 )); then
		ret=$2
	elif (( $3 >= $2 && $2 >= $1 )); then
		ret=$2
	elif (( $1 >= $3 && $3 >= $2 )); then
		ret=$3
	elif (( $2 >= $3 && $3 >= $1 )); then
		ret=$3
	elif (( $2 >= $1 && $1 >= $3 )); then
		ret=$1
	elif (( $3 >= $1 && $1 >= $2 )); then
		ret=$1
	fi
	return $ret
}
secondMax $a $b $c
echo $?
