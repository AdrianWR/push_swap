#!/usr/bin/perl -w

use strict;
use warnings;
use List::Util 'shuffle';
use IPC::Run3 qw(run3);		# Install libperlipc3

sub usage {
    return "$0 <stack_size>
$0 <stack_size> [--debug]
$0 <stack_size> [--count]
$0 <stack_size> [--checker]
";
}

# List of arguments
if (@ARGV < 1 || $ARGV[0] !~ /^\d+$/)
{
	die usage();
}
my @numbers = join(' ', shuffle(0..($ARGV[0] - 1))); 

# Push Swap
my ($in);
run3 ['./push_swap', @numbers], undef, \$in, undef;

# Checker Test
if (grep { $_ eq '--checker' } @ARGV)
{
	my ($out, $err);
	run3 ['./checker', @numbers], \$in, \$out, \$err;
	print $out;
}
elsif (grep { $_ eq '--count' } @ARGV)
{
	my ($out);
	run3 ['wc', '-l'], \$in, \$out;
	print $out;
}
else
{
	if (grep { $_ eq '--debug' } @ARGV)
	{
		print "ARG: @numbers\n";
	}
	print $in;
}
