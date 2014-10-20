

#include <cfloat>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>



#define cls system("cls")
#define frz system("PAUSE")
#define yl system("color 0e")

using namespace std;
//******************************Type definitions
ofstream print("c:\\das.txt");
//****************************** Function Prototypes
//******************************Main functions
int main() {
    
        time_t t;
        time(&t);
        yl;
        int num;
        double radwheel, radrod, lenrod, volume, pi = 3.14159;
    double lenwheel, lencone;
cout <<"Jeff Hamlin " << ctime(&t) <<endl <<endl;
print <<"Jeff Hamlin " << ctime(&t) <<endl <<endl;
cout << fixed << showpoint << setprecision(3);
print << fixed << showpoint << setprecision(3);
cls;
cout <<" Volume Calculation Program" << endl <<endl;
cout << "1. Dumbbell" <<endl;
cout <<"2. Axle" <<endl;
cout <<"3. Spear" <<endl;
cout <<"4. Exit" <<endl <<endl;
cout <<"Select an object's number or exit: ";
cin >> num;
switch(num)
{
    case 1:
    cls;
        cout<<"Enter Radius of the ball: ";
        cin >> radwheel;
        cout <<"Enter radious of the rod: ";
        cin >> radrod;
            if(radrod > radwheel/2.)
                {
                cout <<"Radius of the rod is too large. "<<endl;
                frz;
                exit(1);
                }
        cout <<"Enter length of rod: ";
        cin >> lenrod;
        volume = 2.*(4./3.*pi*radwheel*radwheel*radwheel)+(pi*radrod*radrod*lenrod);

        cout <<" The volume of the dumbell is " << volume <<" cubic inches." <<endl;
        print <<" The volume of the dumbell is " << volume <<" cubic inches." <<endl;

        break;
    
    case 2:
    cls;
        cout <<" Enter radius of the wheel: ";
        cin >> radwheel;
        cout <<" Enter width of wheel: ";
        cin >> radrod;
            if(radrod > radwheel/2.)
                {
                cout<<" Radius of the rod is too large." <<endl;
                frz;
                exit(1);
                }

        cout <<"Enter length of the rod: ";
        cin >> lenrod;
        cout << "Enter width of the wheel: ";
        cin >> lenwheel;
        volume = 2.*(pi*radwheel*radwheel*lenwheel)+(pi*radrod*radrod*lenrod);
       
        cout <<" The volume of the axle is " <<volume <<" cubic inches "<<endl;
        print <<" The volume of the axle is " <<volume <<" cubic inches "<<endl;
        
        break;

    case 3:
    cls;
        cout <<"Enter radius of the rod: ";
        cin >> radrod;
        cout << "Enter the length of the rod: ";
        cin >> lenrod;
        cout <<" Enter the length of the cone: ";
        cin >> lencone;
        volume = 2.*(1./3.*pi*radrod*radrod*lencone)+(pi*radrod*radrod*lenrod);

        cout <<" The volume of the spear is " << volume <<" cubic inches " <<endl;
        print <<" The volume of the spear is " << volume <<" cubic inches " <<endl;

        break;        
}
print.close();
frz;   
return 0;
}

