#!/bin/bash

cd $(dirname "${0}");
cat "${1}" | while IFS="|" read rname clone_uri;
do
    error=0;
    echo "------------------------"
    ru="${rname%/*}";
    rn="${rname#*/}";
    echo "> testing for exists clone ${rname}";
    if [[ -d "mirror/${rname}" ]];
    then 
	echo "> alredy cloned";
    else
	if [[ -n "${clone_uri}" ]];
	then
	    echo "> starting clone ${ru}/${rn} from ${clone_uri}";
	    (mkdir -p "mirror/${ru}" && cd "mirror/${ru}" && git clone "${clone_uri}" && echo "+++ sucesfully cloned($ru/$rn) from ${clone_uri}") || (error=1; echo "!!! error occured ($rname) from ${clone_uri}");
	else
	    echo "> starting clone ${ru}/${rn} from github.com";
	    (mkdir -p "mirror/${ru}" && cd "mirror/${ru}" && git clone "git://github.com/${ru}/${rn}.git" && echo "+++ sucesfully cloned($ru/$rn)") || (error=1; echo "!!! error occured ($rname)");
	fi;
    fi;
    echo "> starting fetch ${rname}";
    (cd "mirror/${rname}" && git fetch --all && echo "+++ sucesfully fetched ($rname)") || echo "!!! error occured ($rname)";
    echo "> starting pull ${rname}";
    (cd "mirror/${rname}" && git pull && echo "+++ sucesfully pulled ($rname)") || echo "!!! error occured ($rname)";
    echo "------------------------"
done;
