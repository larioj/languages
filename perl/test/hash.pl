#! /usr/bin/perl -w

# regular usage
%hash = qw(key1 donkey key2 4);
print $hash{"key1"}, "\n";

# Keys
@keys = keys(%hash);
print @keys, "\n";

# values
@values = values(%hash);
print @values, "\n";

# each
printhash();
sub printhash {
	while (($key, $value) = each(%hash)) {
		print "$key $value\n";
	}
}

# note that order is not guaranteed

# removing elements
delete $hash{"key1"};
printhash();

# slices
@hash{"color", "mood", "temp"} = ("red", "good", 58);
printhash();

#example
@score{"fred", "barney", "dyno"} = (10, 20, 30);
@players = qw(fred barney dyno);

# This manner the hash prints with spaces
print "scores are: @score{@players}\n";

# All elements without spaces
print %hash;

# Arrays as values
@arr1 = qw(a b c);
@arr2 = qw(d e f);
$val = "hello";
%ahash = ();
$ahash{"arr1"} = [@arr1];
$ahash{"arr2"} = [@arr2];
$ahash{"val"} = $val;

# apparently we have to convert
@arr3 = @{$ahash{"arr1"}};
print "\n", @arr3, "\n";
