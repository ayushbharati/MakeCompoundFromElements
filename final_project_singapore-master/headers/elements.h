#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <iostream>
using namespace std;

// a class that includes all the elements from the periodic table
class Elements
{
private: 
    string elementName ;
    string elementSymbol;
    string atomicnumber ;
    string atomicmass;
    string charge ;
    bool sign = true ; 
public :
    // empty constructor
    Elements()
    {

    }
    // constructor overload
    Elements(string _elementName, string _elementSymbol, string _atomicnumber, string _atomicmass , string _charge)
    {
        elementName = _elementName ;
        elementSymbol = _elementSymbol ;
        atomicnumber = _atomicnumber;
        atomicmass = _atomicmass ;
        charge = _charge ;
    }
    // getter and setter functions
    void setelementname(string n)
    {
        elementName = n ;
    }
    string getElementName()
    {
        return elementName ;
    }
    void setelementsymbol(string e)
    {
        elementSymbol = e ;
    }
    void setatomicnumber(int a)
    {
        atomicnumber = a;
    }
    string getElementSymbol()
    {
        return elementSymbol;
    }
    string getatomicnumber()
    {
        return atomicnumber;
    }
    void setatomicmass(double m)
    {
        atomicmass = m;
    }
    string getatomicmass()
    {
        return atomicmass ;
    }
    void setcharge(double c)
    {
        charge = c ;
    }
    string getcharge()
    {
        return charge ;
    }
    void setsign()
    {
        if (charge.find("-") != string::npos ) // if the charge of the element is negative then it is assigned a false value
        {
            sign = false;
            charge = charge.erase(0,1);
        }

        
    }
    bool getsign()
    {
        return sign;
    }

    // print function for the members of the elements class
    void printDetailofElements()
    {
        
        cout << " Details of your element : " <<endl;
        cout << endl;
        cout << " Name : " << elementName << endl;
        cout << endl; 
        cout << " Symbol : " << elementSymbol <<endl;
        cout << endl;
        cout << " Atomic Mass: " <<atomicmass <<endl;
        cout << endl; 
        cout << " Atomic Number : " << atomicnumber <<endl; 
        cout << endl; 
        cout << " Charge : " << charge <<endl;
        cout << endl; 
    }   
    


    
};

#endif