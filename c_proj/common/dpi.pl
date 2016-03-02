#!/bin/env perl

use strict;
use FileHandle;

my $path = "/home/informix/huxq/Data/";

my @fileList = (
	"/home/informix/huxq/Data/20160301110118.txt",
	"/home/informix/huxq/Data/20160301110854.txt",
	"/home/informix/huxq/Data/20160301111617.txt",
	"/home/informix/huxq/Data/20160301112340.txt",
	"/home/informix/huxq/Data/20160301113117.txt",
	"/home/informix/huxq/Data/20160301110510.txt",
	"/home/informix/huxq/Data/20160301111237.txt",
	"/home/informix/huxq/Data/20160301112000.txt",
	"/home/informix/huxq/Data/20160301112719.txt",
	"/home/informix/huxq/Data/20160301113506.txt"
);

for(my $i = 0; $i < 10; $i++)
{
	my $start = time();

	open(FILE, "<", $fileList[$i]) || die "connot open the file: $!\n";
	while(<FILE>)
	{

	}
	close(FILE);

	my $end = time();

	my $the_time = $end - $start;
	print("file: $fileList[$i] is ready: $the_time\n");
}