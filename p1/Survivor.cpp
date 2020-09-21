#include <fstream>
#include "Survivor.h"
using namespace std;

Survivor::Survivor()
{
    fname = "Wilson";
    lname = "WILLLLSOOOON";
    city = "";
    state = "";
    age = -1;
}

Survivor::Survivor(string f, string l)
{
    fname = f;
    lname = l;
    city = "";
    state = "";
    age = -1;
}

Survivor::Survivor(string f, string l, string ht, string st, int a)
{
    fname = f;
    lname = l;
    city = ht;
    state = st;
    age = a;
    round = 0;
    points = 0;
}

void Survivor::set_name(string fn, string ln)
{
    fname = fn;
    lname = ln;
}

// Function print
void Survivor::print(ostream &out) const
{
    out << fname << " " << lname << endl;
    if (city != "" && state != "")
        out << "hometown: " << city << ", " << state << endl;
    if (age != -1)
        out << "age: " << age << endl << endl;
}


// Function generate_next_survivor
// Input: ifstream object reference
// Returns: void
// Does: reads the next line of input from the file
//       assumed format: fname, lastname, gender, age
int Survivor::generate_next_survivor(ifstream &infile)
{
    string fn, ln;
    string ht, st;
    int a;
    
    infile >> fn;

    // better solution would use consts here 
    if (fn == "-1")
    {
        return -1;
    }

    infile >> ln;
    infile >> ht;
    infile >> st;
    infile >> a;

    fname = fn;
    lname = ln;
    city = ht;
    state = st;
    age = a;

    return 0;
}


bool operator < (const Survivor &s1, const Survivor &s2)
{
    if (s1.lname < s2.lname)
        return true;
    else if (s1.lname > s2.lname)
        return false;
    else if (s1.fname < s2.fname)
        return true;
    return false;
}


bool operator > (const Survivor &s1, const Survivor &s2)
{
    if (s1.lname > s2.lname)
        return true;
    else if (s1.lname < s2.lname)
        return false;
    else if (s1.fname > s2.fname)
        return true;
    return false;
}

bool operator == (const Survivor &s1, const Survivor &s2)
{
    if (s1.fname == s2.fname && s1.lname == s2.lname)
        return true;
    return false;
}
