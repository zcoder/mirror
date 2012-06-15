#!/bin/bash

cd $(dirname "${0}");


while [ 1 ];
do
    ls -1 list/git.* | while read fname; 
    do
	echo "--- start ${fname} ---";
	./mirror.sh "${fname}";
	echo "--- stop  ${fname} ---";
    done;
    sleep 3600;
done;
