#! /bin/bash

our_dir=$1
files_extension=$2
name_dir=$3
name_archive=$4

start_dir=$(pwd)
mkdir $name_dir

cd $our_dir
our_files=$(find -name "*.$files_extension")

for file in $our_files
do
    cp --parent $file "$start_dir/$name_dir"
done

cd $start_dir
tar -acf $name_archive $name_dir
echo done
