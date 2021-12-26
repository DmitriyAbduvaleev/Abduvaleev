#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Rectangles 
{
private:
    double x1_bottom_left, y1_bottom_left, x1_top_right, y1_top_right;
    double x2_bottom_left, y2_bottom_left, x2_top_right, y2_top_right;
    
public:
    Rectangles(double value_x1_bottom_left, double value_y1_bottom_left, double value_x1_top_right, double value_y1_top_right,
               double value_x2_bottom_left, double value_y2_bottom_left, double value_x2_top_right, double value_y2_top_right)
    {                            
        x1_bottom_left = value_x1_bottom_left;
        y1_bottom_left = value_y1_bottom_left;
        x1_top_right =  value_x1_top_right;
        y1_top_right = value_y1_top_right;
        x2_bottom_left = value_x2_bottom_left;
        y2_bottom_left = value_y2_bottom_left;
        x2_top_right =  value_x2_top_right;
        y2_top_right = value_y2_top_right;
    }

    void check_intersection ()
    {
        if (x1_bottom_left >= x2_bottom_left && x1_bottom_left <= x2_top_right 
        && y1_bottom_left >= y2_bottom_left && y1_bottom_left <= y2_top_right)
        {
            cout << "Rectangles intersect\n" << endl;
        }
        else if (x1_bottom_left >= x2_bottom_left && x1_bottom_left <= x2_top_right 
        && y1_top_right >= y2_bottom_left && y1_top_right <= y2_top_right)
        {
            cout << "Rectangles intersect\n" << endl;
        }
        else if (x1_top_right >= x2_bottom_left && x1_top_right <= x2_top_right
        && y1_top_right >= y2_bottom_left && y1_top_right <= y2_top_right)
        {
            cout << "Rectangles intersect\n" << endl;
        }
        else if (x1_top_right >= x2_bottom_left && x1_top_right <= x2_top_right
        && y1_bottom_left >= y2_bottom_left && y1_bottom_left <= y2_top_right)
        {
            cout << "Rectangles intersect\n" << endl;
        }
        else
        {
            cout << "Rectangles don't intersect\n" << endl;
        }
    }

};

int main ()
{
    double rect1_x1, rect1_y1, rect1_x2, rect1_y2, rect2_x1, rect2_y1, rect2_x2, rect2_y2;
    
    ifstream outfile ("Coordinates.txt");
	outfile >> rect1_x1 >> rect1_y1 >> rect1_x2 >> rect1_y2 >> rect2_x1 >> rect2_y1 >> rect2_x2 >> rect2_y2;
	outfile.close();
    Rectangles rect(rect1_x1, rect1_y1, rect1_x2, rect1_y2, rect2_x1, rect2_y1,rect2_x2, rect2_y2);
    rect.check_intersection();
    
	system("pause");
	return 0;
}