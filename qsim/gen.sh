#!/bin/bash

for d in ../benchmark/*/*; do
    ln -s ../dataset dataset
    if [[ -x $d ]]; then
	cp $d .
	bench=`basename $d`
	sed "s/TEST/$bench/g" runme_orig.sh > runme.sh;
	tar -cf $bench.tar $bench runme.sh dataset/small;
	rm -f $bench
    fi;
    rm -f dataset runme.sh
done
