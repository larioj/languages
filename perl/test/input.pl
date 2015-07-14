#! /usr/bin/perl -w

# <STDIN>
print ("Enter your name: ");
chomp ($name = <STDIN>);
print ("Hello $name!\n");

# Diamond operator
print "Enter whatever you want: ";
while ($line = <>) {
	print $line;
}

# Reading from files
print "reading from files: \n";
@ARGV = qw(chars.pl hash.pl);
while ($line = <>) {
	print "output: ", $line;
}

# formated output
printf "%s %d", "hello", 45;
