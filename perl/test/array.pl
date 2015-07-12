#! /usr/bin/perl -w

# Arrays

# regular usage
@ar = (1,2,3,4);

# Print all elements in the array without spaces.
print @ar;
print "\n";

# doesn't work? Treats array in scalar context
# ends up printing the length of array
print @ar . "\n";

# quote word
@br = qw(1 2 3 4);

# length, same as 'print @br . "\n";'
print scalar @br . "\n";

# last index
print $#br . "\n";

# assignment
@cr = (@ar, @br);
print @cr;
print "\n";

# indexing
@cr = @cr[(0,4,1,5,2,6,3,7)];
print @cr;
print "\n";

print $cr[3] . "\n";

# push pop
push(@cr, 20);
print @cr;
print "\n";

print pop(@cr);
print "\n";
print @cr;
print "\n";

# avoiding the concatenation scalar context
print (@cr, "\n");

# shift and unshift
unshift(@cr, "a");
print (@cr, "\n");

print (shift(@cr), "\n", @cr, "\n");

# reverse
print (reverse(@cr), "\n");

# <STDIN> array context
@input = <STDIN>;
print @input;
