#include <stdarg.h>	//  For variables number of arguments
#include <stdio.h>	//  For printf
#include <climits>	//  For MIN_INT
#include <Math.h>	//  For pow, Sqrt

int sum (int first, ...)
{
	register int i = first;
	int sum = 0;
	
	//  declare a variable argument list
	va_list arg_list;
	
	//  initialize the arglist
	va_start (arg_list, first);
	
	//  Sum all arguments
	while(i != INT_MIN)
	{
		sum += i;
		i = va_arg (arg_list, int);
	}
	
	//  End the argument list
	va_end(arg_list);
	
	return sum;
}

double avg (int first, ...)
{
	register int i = first;
	int sum = 0, count = 0;
	
	va_list arg_list;
	va_start (arg_list, first);
	
	//  sum and count all arguments
	while(i != INT_MIN)
	{
		sum += i;
		count++;
		i = va_arg (arg_list, int);
	}
	
	va_end(arg_list);
	
	return (double) sum / count;
}

int min (int first, ...)
{
	register int i = first;
	int min = first;
	
	va_list arg_list;
	va_start(arg_list, first);
	
	//  Search for any other argument that is less than the first
	//  If you find one, then assign it to min
	while(i != INT_MIN)
	{
		if(i < min)
			min = i;

		i = va_arg(arg_list, int);
	}
	
	va_end(arg_list);
	
	return min;
}

int max (int first, ...)
{
	register int i = first;
	int max = first;
	
	va_list arg_list;
	va_start(arg_list, first);
	
	//  Search for any other argument that is greater than the first
	//  If you find one, then assign it to max
	while(i != INT_MIN)
	{
		if(i > max)
			max = i;

		i = va_arg(arg_list, int);
	}
	
	va_end(arg_list);
	
	return max;
}

double stdev (int first, ...)
{
	register int i = first;
	int count = 0;
	int sum = 0;
	double mean = 0;
	double deviation = 0;
	va_list arg_list;

	//  Calculate the mean (average)
	va_start(arg_list, first);
	
	while(i != INT_MIN)
	{
		sum += i;
		count++;
		i = va_arg (arg_list, int);
	}
	
	va_end(arg_list);
	mean = (float) sum / count;

	//  Calculate the standard deviation
	i = first;
	va_start(arg_list, first);
	
	while(i != INT_MIN)
	{
		deviation += pow((i - mean), 2);
		i = va_arg (arg_list, int);
	}

	deviation /= count;
	deviation = sqrt(deviation);

	va_end(arg_list);
	
	return deviation;
}

double var (int first, ...)
{
	register int i = first;
	int count = 0;
	int sum = 0;
	double mean = 0;
	double variance = 0;
	va_list arg_list;

	//  Calculate the mean (average)
	va_start(arg_list, first);
	
	while(i != INT_MIN)
	{
		sum += i;
		count++;
		i = va_arg (arg_list, int);
	}
	
	va_end(arg_list);
	mean = (float) sum / count;

	//  Calculate the variance
	i = first;
	va_start(arg_list, first);
	
	while(i != INT_MIN)
	{
		variance += pow((i - mean), 2);
		i = va_arg (arg_list, int);
	}

	variance /= (count - 1);

	va_end(arg_list);
	
	return variance;
}

int main ()
{
	//  Testing sum
	printf ("Sum of (1, 2, 3, 4, 5) = %d\n", sum (1, 2, 3 , 4, 5, INT_MIN));
	
	//  Testing avg
	printf ("Average of (1, 2, 3, 4, 5) = %.2f\n", avg (1, 2, 3 , 4, 5, INT_MIN));
	
	//  Testing min
	printf ("Minimum of (10, 23, 3, 41, 15) = %d\n", min (10, 23, 3, 41, 15, INT_MIN));
	
	//  Testing max
	printf ("Maximum of (10, 23, 3, 41, 15) = %d\n", max (10, 23, 3, 41, 15, INT_MIN));

	//  Testing standard deviation
	printf ("Standard Deviation of (2, 4, 4, 4, 5, 5, 7, 9) = %.2f\n", stdev (2, 4, 4, 4, 5, 5, 7, 9, INT_MIN));

	//  Testing variance
	printf ("Variance of (1, 2, 3, 4, 5, 6) = %.2f\n", var (1, 2, 3, 4, 5, 6, INT_MIN));

	printf ("\n");

	return 0;
}