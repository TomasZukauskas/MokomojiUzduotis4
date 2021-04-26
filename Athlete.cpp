#include "Athlete.hpp"
#include <iostream>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#define DEFAULT "Default"
#define DEFAULT_0 0

using namespace std;

namespace ATH
{
    int Athlete::ID = 0;
    Athlete::Athlete()
    {
        setName(DEFAULT);
        setSurname(DEFAULT);
        setSport(DEFAULT);
        setHeight(DEFAULT_0);
        setWeight(DEFAULT_0);
        thisID = ++ID;
    }
    Athlete::Athlete(string inputName, string inputSurname, string inputSport, unsigned int inputHeight, unsigned int inputWeight)
    {
        setName(inputName);
        setSurname(inputSurname);
        setSport(inputSport);
        setHeight(inputHeight);
        setWeight(inputWeight);
        thisID = ++ID;
    }
    Athlete::~Athlete()
    {
        cout << "Destroyed!" << endl;
    }
    void Athlete::setName(string inputName)
    {
        if(isName(inputName))
        {
            name = inputName;
        }
        else
        {
            throw invalid_argument ("Wrong name input..");
        }
    }
    void Athlete::setSurname(string inputSurname)
    {
        if(isSurname(inputSurname))
        {
            surname = inputSurname;
        }
        else
        {
            throw invalid_argument ("Wrong surname input..");
        }
    }
    void Athlete::setSport(string inputSport)
    {
        if(isSport(inputSport))
        {
            sport = inputSport;
        }
        else
        {
            throw invalid_argument ("Wrong shoes input..");
        }
    }
    void Athlete::setHeight(unsigned int inputHeight)
    {
        if (inputHeight >= 0 && inputHeight <= 250)
        {
            height = inputHeight;
        }
        else
        {
            throw invalid_argument ("Wrong height input..");
        }
    }
    void Athlete::setWeight(unsigned int inputWeight)
    {
        if (inputWeight >= 0 && inputWeight <= 300)
        {
            weight = inputWeight;
        }
        else
        {
            throw invalid_argument ("Wrong weight input..");
        }
    }
    string Athlete::getName()
    {
        return name;
    }
    string Athlete::getSurname()
    {
        return surname;
    }
    string Athlete::getSport()
    {
        return sport;
    }
    unsigned int Athlete::getHeight()
    {
        return height;
    }
    unsigned int Athlete::getWeight()
    {
        return weight;
    }
    bool operator< (const Athlete &a1, const Athlete &a2)
    {
        return a1.height < a2.height && a1.weight < a2.weight;
    }
    bool operator== (const Athlete &a1, const Athlete &a2)
    {
        return a1.height == a2.height && a1.weight == a2.weight;
    }
    bool operator!= (const Athlete &a1, const Athlete &a2)
    {
        return !(a1 == a2);
    }
    bool operator> (const Athlete &a1, const Athlete &a2)
    {
        return !(a1 < a2);
    }
    bool operator<= (const Athlete &a1, const Athlete &a2)
    {
        return (a1 < a2 || a1 == a2);
    }
    bool operator>= (const Athlete &a1, const Athlete &a2)
    {
        return (!(a1 < a2) || a1 == a2);
    }
    Athlete& Athlete::operator++()
    {
        this->weight++;
        return *this;
    }
    Athlete Athlete::operator++(int)
    {
        Athlete temp = *this;
        this->weight++;
        return temp;
    }
    ostream& operator<<(std::ostream& output, const Athlete& a)
    {
        output << a.thisID << ". " << a.name << " " << a.surname << " " << a.sport << " player " <<endl;
        output << "Height: " << a.height << " Weight: " <<  a.weight << endl;
		return output;
    }
    istream& operator>>(std::istream& input, Athlete& a)
    {
		string stringInput;
		int numberInput;
		cout << "Input name of athlete: ";
		input >> stringInput;
		a.setName(stringInput);
		cout << "Input surname of athlete: ";
        input >> stringInput;
		a.setSurname(stringInput);
		cout << "Input sport of athlete: ";
        input >> stringInput;
		a.setSport(stringInput);
		cout << "Input height of athlete: ";
        input >> numberInput;
		a.setHeight(numberInput);
		cout << "Input weight of athlete: ";
        input >> numberInput;
		a.setWeight(numberInput);

		return input;
    }
    string Athlete::toString()
    {
        stringstream athlete;

        athlete << thisID << ". " << name << " " << surname << " " << sport << " player " <<endl;
        athlete << "Height: " << height << " Weight: " <<  weight << endl;

        return athlete.str();
    }
    bool Athlete::isName(string name)
    {
        for (size_t i = 1; i < name.length(); i++)
        {
            if (!islower(name[i]))
            {
                return false;
            }
        }
        if (!isupper(name[0]))
        {
            return false;
        }
        return true;
    }
    bool Athlete::isSurname(string surname)
    {
        for (size_t i = 1; i < surname.length(); i++)
        {
            if (!islower(surname[i]))
            {
                return false;
            }
        }
        if (!isupper(surname[0]))
        {
            return false;
        }
        return true;
    }
    bool Athlete::isSport(string sport)
    {
        for (size_t i = 1; i < sport.length(); i++)
        {
            if (!isalpha(sport[i]))
            {
                return false;
            }
        }
        if (sport.length() < 1)
        {
            return false;
        }
        return true;
    }
}
