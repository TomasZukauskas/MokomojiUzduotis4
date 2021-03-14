#include "Athlete.hpp"
#include <iostream>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#define DEFAULT "Default"
#define DEFAULT_0 000

using namespace std;

int main()
{
    try
    {
        ATH::Athlete a3("Lebron", "James", "Basketball", 206, 113);
        ATH::Athlete a4("Arvydas", "Sabonis", "Basketball", 221, 132);
        ATH::Athlete a5("Name", "Surname", "Sport", 206, 113);

        cout << "\nOverloading comparison operator < test.\nValues: " << "a3 | height and weight = " << a3.getHeight() << " | " << a3.getWeight() << ", " << "a4 | height and weight = " << a4.getHeight() << " | " << a4.getWeight() << endl;
        if (a3 < a4)
        {
            cout << "(a3 < a4) | TRUE" << endl;
        }

        cout << "\nOverloading comparison operator == test.\nValues: " << "a3 | height and weight = " << a3.getHeight() << " | " << a3.getWeight() << ", " << "a5 | height and weight = " << a5.getHeight() << " | " << a5.getWeight() << endl;
        if (a3 == a5)
        {
            cout << "(a3 == a5) | HEIGHT AND WEIGHT IS THE SAME " << endl;
        }

        cout << "\nOverloading comparison operator != test.\nValues: " << "a3 | height and weight = " << a3.getHeight() << " | " << a3.getWeight() << ", " << "a4 | height and weight = " << a4.getHeight() << " | " << a4.getWeight() << endl;
        if (a3 != a4)
        {
            cout << "(a3 != a4) | HEIGHT AND WEIGHT IS NOT THE SAME " << endl;
        }

        cout << "\nOverloading comparison operator > test.\nValues: " << "a4 | height and weight = " << a4.getHeight() << " | " << a4.getWeight() << ", " << "a3 | height and weight = " << a3.getHeight() << " | " << a3.getWeight() << endl;
        if (a4 > a3)
        {
            cout << "(a4 > a3) TRUE" << endl;
        }

        cout << "\nOverloading comparison operator <= test.\nValues: " << "a3 | height and weight = " << a3.getHeight() << " | " << a3.getWeight() << ", " << "a5 | height and weight = " << a5.getHeight() << " | " << a5.getWeight() << endl;
        if (a3 <= a5)
        {
            cout << "(a3 <= a5) TRUE" << endl;
        }

        cout << "\nOverloading comparison operator >= test.\nValues: " << "a4 | height and weight = " << a4.getHeight() << " | " << a4.getWeight() << ", " << "a5 | height and weight = " << a5.getHeight() << " | " << a5.getWeight() << endl;
        if (a4 >= a5)
        {
            cout << "(a4 >= a5) TRUE" << endl;
        }

        cout << "\nInitial values: a5 weight = " << a5.getWeight() << ", a3 weight = " << a3.getWeight() << endl;
        a5 = a3++;
        cout << "(a5 = a3++) | " << a5.getWeight() << " | " << a3.getWeight() << endl;
        a5 = ++a3;
        cout << "(a5 = ++a3) | " << a5.getWeight() << " | " << a3.getWeight() << endl << endl;

        ATH::Athlete a1, a2;
        cin >> a1;
        cin >> a2;
        cout << endl << a1 << endl;
        cout << a2 << endl;

        return 0;
    }
    catch (invalid_argument &error)
        {
            cerr << "Error while trying to input athlete: " << error.what() << endl;
        }
    catch (runtime_error &error)
        {
            cerr << "Error while trying to input athlete: " << error.what() << endl;
        }
    catch(...)                  //In order to handle the error
    {
        cerr << "Unknown exeption occured.";
    }
}
