#!/bin/bash

# Removes every a.out from every subfolder where the 
# script is executed;

# Set the filename;
file='a.out'

# The path where 'file' is gonna be looked for;
subfolders=./**/$file
currentdir=./$file

# First checks  if the file exist in the current directory
# or in any sub-folder, if exist removes it from everywhere;
if [ -e $currentdir ] || [ -e $subfolders ];
then
		rm -v -f ./**/"$file" 
		rm -v -f "$file"
		echo "everithing cleaned succesfully"

# if doesn't exist then does nothing;
else
		echo "everything seems clean"
		echo "there is nothing to do"
fi
