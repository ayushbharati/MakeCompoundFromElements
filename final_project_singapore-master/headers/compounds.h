#ifndef COMPOUNDS_H
#define COMPOUNDS_H
#include <iostream>
using namespace std;

class Compound
{
private:
    string compoundsymbol;
public :
    Compound()
    {

    }
    Compound( string _compoundsymbol)
    {
        compoundsymbol = _compoundsymbol ;
    }   
};
#endif