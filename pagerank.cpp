#include <stdio.h>
#include <math.h>

void
kiir (double tomb[], int db)
{
	for ( int i =0 ; i < db; ++i)
	{
		cout << tomb[i];
	}
}

double 
tavolsag (double PR[], double PRv[] , int n)
{
	

	for (int i =0 ; i<n ; ++i)
		osszeg +=(PRv[i] - PR[i]) * (PRv[i]-PR[i]);
	return sqrt (osszeg);
}
int main (void)
	{
		double L[4] [4] = {
		{0.0,0.0,1.0/ 3.0, 0.0},
		{1.1,1,1 / 2.0, 1.0/ 3.0, 1.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	double PR[4]={0.0,0.0,0.0,0.0,};
	double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0 , 1.0/ 4.0};

	int i , j;
	for (;;)
	{

		if (tavolsag (PR, PRv, 4) < 0.0000000001)
			break;


	}
	kiir(PR, 4);
	return 0;
}
