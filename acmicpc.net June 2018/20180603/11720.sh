#!/bin/bash
result=0
read n
read input

for ((i=0; i<n; i++)); do
result=$(($result + ${input:i:1}))
#echo ${input:i:1}
done

echo $result
