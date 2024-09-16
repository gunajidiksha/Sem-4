#!/bin/bash
gcd() {
  a=$1
  b=$2
  while [ $b -ne 0 ]; do
    temp=$b
    b=$(($a % $b))
    a=$temp
  done
  echo $a
}

lcm() {
  a=$1
  b=$2
  gcd_value=$(gcd $a $b)
  echo $((($a * $b) / gcd_value))
}

echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2

gcd_value=$(gcd $num1 $num2)
echo "GCD of $num1 and $num2 is: $gcd_value"

lcm_value=$(lcm $num1 $num2)
echo "LCM of $num1 and $num2 is: $lcm_value"
