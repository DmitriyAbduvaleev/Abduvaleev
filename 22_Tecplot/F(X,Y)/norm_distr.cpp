#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile("norm_distr.dat");

    outfile << "TITLE = \"Normal distribution\"" << endl;
    outfile << "VARIABLES = \"X\", \"Y\", \"Z\"" << endl;
    outfile << "ZONE T = \"ZONE1\", I = 100 J = 100, F = POINT" << endl;

    double x, y, h;
	h = 6.0/100;

	for(double x = -3.0; x <= 3.0; x += h)
	{
		for(double y = -3.0; y <= 3.0; y += h)
		{
			outfile << x << ", " << y << ", " << exp(-(y * y + x * x / 2.0)) / 2.0 * acos(-1) << "\n";
		}
	}

    outfile.close();
	return 0;
}