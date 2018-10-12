#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

void kiir(vector<double> tomb, int db)
{
	for (int i = 0; i < db; i++)
	{
		printf("%f\n", tomb[i]);
	}
}

double tavolsag(vector<double> PR,vector<double> PRv, int n)
{
	double osszeg = 0.0;

	for (int i = 0; i < n; i++)
	{
		osszeg += (PRv[i]-PR[i])*(PRv[i]-PR[i]);
	}
	return sqrt(osszeg);
}

int main(void)
{
	vector<vector<double>> L =
	{
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};
	//for ( int i=0;i<L.size();++i )
	//{
	//	kiir(L.at(i),4);
	//}
	vector<double> PR = {0.0, 0.0, 0.0, 0.0};
	vector<double> PRv = {1.0/4.0,1.0/4.0,1.0/4.0,1.0/4.0};

	int i,j;
	for (;;)
	{
		for (int i = 0; i<4; ++i)
		{
			PR[i] = 0.0;
			for (int j = 0; j<4; ++j)
			{
				PR[i] += (L.at(i).at(j)*PRv[j]);
			}
		} 
		if(tavolsag(PR, PRv, 4)<0.0001)
		{
			break;
		}
		for(int i = 0; i<4; i++)
		{
			PRv[i] = PR[i];
		}		
	}
	kiir(PR,4);
	return 0;
}