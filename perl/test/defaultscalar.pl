#! /usr/bin/perl -w
# At times things get assigned to
# the default scalar $_
while(<>) {
	# These should produce the same thing
	print $_;
	print;
}
