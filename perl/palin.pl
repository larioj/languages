#! /usr/bin/perl -w
chomp($loops = <STDIN>);
while ($loops-- != 0) {
	chomp($num = <STDIN>);
	if (nines($num)) {
		print (lol($num));
	} elsif (incresable($num)) {
		
	} else {
	}
}

sub nines {
	my($num) = @_;
	$num =~ /9+/;
}

sub lol {
	my($num) = @_;
	$num =~ s/^9/1/;
	$num =~ tr/9/0/;
	$num . "1";
}

sub incresable {
}
