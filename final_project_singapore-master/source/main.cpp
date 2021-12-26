// Ayush Bharati
// Class - CS 172-2
// Project - Final Project
// Date - 05/20/2021
// License - Copyright <2021> <Ayush Bharati>
// Description - This project is a minor user interface chemical periodic table which uses the periodic table from the internet to get details
// of each elements listed in the periodic table. In addition, by the principle of charge this program will make a compound from 2 elements.
// Reference - Periodic table from https://ptable.com/#Properties & https://www.data-explorer.com/data/ 

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <windows.h>
#include <Algorithm>
#include "../headers/compounds.h"
#include "../headers/elements.h"
using namespace std;

/* steps : //
// - For UI interactive periodic table : 
        - ask the name of the compound and search for the compound in the file
        - print the detail of the compound
    - For the chemical mixer :
        - ask for the chemicals and search them in the text file
        - if found find the charge of the elements
        - criss-cross the charge according to the symbol
        - make the compound
        
// - 
*/

// The basic idea of the program is to create a vector object for every element listed in the periodic table. I did that by using dynamic memory allocation
// of pointers.

// a function that gives the index of the vector of the element that the user is asking for.
void getindex(int &a, int &b, string firstelement, string secondelement, vector<Elements *> &E)
{
    for (int i = 0; i < E.size(); i++)
    {
        if (firstelement == E[i]->getElementName()) // finds the first element int the vector list ;
        {
            a = i; // assigns the index if first element is found
        }
        else if (secondelement == E[i]->getElementName()) // finds the second element
        {
            b = i; // assign the index if second element is found
        }
    }
}

// a function that does chemical criss cross and makes the compound
void getcompound(int x, int y, int a, int b, vector<Elements *> &E)
{
    if (x == y) // x and y are integers that represent the charge in a compound. so if the charges of the two elements are equal simply the charge cancel each other
    {
        cout << " Your compound is : " << E[a]->getElementSymbol() << E[b]->getElementSymbol() << endl; // print the chemical formula
    }
    else
    {
        if (x < y) // if the charge of the first element is less than the second, this conditional will swap the values so that the ratio is always possible
        {
            swap(a, b);
        }
        if (x % y == 0) // if the charge of the first element is a multiple of the second then the ratio of the charges will cancel each other
        {
            cout << " Your compound is : " << E[a]->getElementSymbol() << E[b]->getElementSymbol() << x / y <<endl;
        }
        else // is the charge is not the same, the compound formed is just
        {
            cout << " Your compound is : " << E[a]->getElementSymbol() << y << E[b]->getElementSymbol() << x <<endl;
        }
    }
}

// a function that generates the chemical formula and asks for print statements.
void startprogram(vector<Elements *> &E)
{
    // print statement to ask user their selection
    cout << " Welcome to the Chemistry Balance your equation table . " << endl;
    int c = 1;
    cout <<endl ;
    cout << endl;

    cout << " What do you want to do here ? " << endl;
    cout << endl;
    cout << c << " Detailed Information of an element : " << endl;
    cout << ++c << " Derive a chemical formula of a compound. " << endl;
    int choice;
    cout << endl; 
    cout << "Enter a choice (1 / 2) : ";
    cin >> choice;

    // if made a first choice i.e. to get details of a periodic table
    if (choice == 1)
    {
        string s;
        cout << " Enter the name of the element. ";
        cin >> s;
        if (islower(s[0])) // since the periodic table has the first letter starting with a small letter, the first one is capitalized
        {
            s[0] = toupper(s[0]);
        }
        for (int i = 0; i < E.size(); i++)
        {
            // this conditional statement will serach the whole list of periodic table until it finds the name of the element
            if (E[i]->getElementName() == s)
            {
                E[i]->printDetailofElements();
            }
        }
    }

    else if (choice = 2)
    {
        // print statements to ask user the elements
        cout << " Enter the name of the first element : ";
        string firstelement;
        cin >> firstelement;

        cout << " Enter the name of the second element : ";
        string secondelement;
        cin >> secondelement;

        int a, b; // position of the element

        // calls the get index function to find the index of the vector of all the elements which is passed by reference
        getindex(a, b, firstelement, secondelement, E);

        // condtional statement if the user inputs same compound twice
        if (E[a]->getsign() == E[b]->getsign())
        {
            cout << " You can't form a compound between these elements. ";
        }
        else
        {
            // assign x and y integer value to the charges so that itis easier for calculations
            int x = stoi(E[a]->getcharge());
            int y = stoi(E[b]->getcharge());
            getcompound(x, y, a, b, E); // here it calls the function to get the compound that has been formed after criss cross
        }
    }
}

int main()
{
    char selection; 
    system("CLS");
    system("CLS");
    while (selection != 'N' || selection != 'n')
    {
        // fstream to open the files.
        string periodictable = "PeriodicTable.txt";
        fstream fin(periodictable, ios::in | ios ::out);
        string polyatomicions = "polyatomic.txt";
        fstream fin2(polyatomicions, ios::in | ios ::out);

        vector<Elements *> E;   // a vector of pointer pointing to an object in E
        vector<string> details; // a vector of details that includes the variables of element class in order
        string line, line2;
        while (getline(fin, line)) // reads each string line by line
        {
            int count = 0;
            for (int i = 0, j = 0; i < line.length(); i++)
            {
                if (line[i] == ' ') // the loop runs until a whitespace is found so that each word is categoried as a attribute of the class
                {
                    details.push_back(line.substr(count, i - count));
                    count = i + 1;
                    j++;
                }
            }
            details.push_back(line.substr(count, line.length() - count));
            E.push_back(new Elements(details[0], details[1], details[2], details[3], details[4])); // creates a new pointer dynamically where everything is stored
            E[E.size() - 1]->setsign();                                                            // sets the sign which is the charge poistiive
            details.clear();                                                                       // clears the detail vector for another use.
        }

        startprogram(E); // calls the function to run the actual program.
        cout << " Do you want to go again ? (Y / N) ? : " ; 
        cin >>  selection ; 
    }
}
