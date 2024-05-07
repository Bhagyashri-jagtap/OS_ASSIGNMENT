#!/bin/bash


echo "Enter a year to check - "

read y

year=$y

ans=`expr $year % 4`

if [ $ans -eq 0 ]

then

    echo "Leap Year"

else

	echo "Not a Leap Year"
fi
