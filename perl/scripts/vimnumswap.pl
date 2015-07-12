#! /usr/bin/perl -w
@nums = qw(1 2 3 4 5 6 7 8 9 0);
@syms = ('!','@','#','$','%','^','&','*','(',')');

for ($i = 0; $i < @syms; $i++) {
	print "inoremap $nums[$i] $syms[$i]", "\n";
	print "inoremap $syms[$i] $nums[$i]", "\n";
}
