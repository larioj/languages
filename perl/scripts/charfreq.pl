#! /usr/bin/perl -w

use Cwd;

@names = @ARGV;
%chars = ();

while ($name = pop (@names)) {
	if (-f $name) {
		open (FILE, $name);
		while ($c = getc (FILE)) {
			if ($c =~ /[A-Z]/) {
				$c =~ tr/A-Z/a-z/;
			}
			if ($c eq "\n") {
				$c = "\\n";
			}
			if ($c eq "\t") {
				$c = "\\t";
			}
			if ($c eq " ") {
				$c = "space";
			}
			unless ($chars{$c}) {
				$chars{$c} = 0;
			}
			$chars{$c}++;
		}
	}
	if (-d $name) {
		@files = glob $name . "/*";
		foreach my $file (@files) {
			push (@names, $file);
		}
	}
}

foreach $char (sort {$chars{$b} <=> $chars{$a}} keys %chars) {
	printf ("%-8s %d\n", $char, $chars{$char});
}
