#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#ifndef SURVIVOR_H_
#define SURVIVOR_H_

class Survivor
{
private:

    string fname, lname;
    string city, state;
    int age;
    int round;
    int points;

public:
    Survivor();
    Survivor(string, string);
    Survivor(string, string, string, string, int);
    void print(ostream &) const;
    int generate_next_survivor(ifstream &);

    void set_round(int);
    void add_to_points(int);
    void set_name(string, string);
    int get_age()const { return age; }

    friend bool operator == (const Survivor &, const Survivor &);
    friend bool operator < (const Survivor &, const Survivor &);
    friend bool operator > (const Survivor &, const Survivor &);


};

#endif
