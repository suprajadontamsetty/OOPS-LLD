#ifndef TIME_UTILIS_H
#define TIME_UTILIS_H

#include<ctime>
#include<string>

using namespace std;

class TimeUtilis {
 public:
 static string getCurrentTime() {
    time_t now=time(0);   
    char*dt=ctime(&now);  //passing the memory address of now. dt points to it
    string s(dt);
    if(!s.empty() && s.back()=='\n')
     s.pop_back();
    return s; 
 }
};


#endif



//time_t is a type used by c/c++ to represent time
//It internally stores number of seconds elapsed since jan 1, 1970. This date is called Unix Epoch
//time(0)=time(nullptr)--returns current system time. i.e stores present date time as a unix timestamp. Number of seconds since 1 Jan 1970, UTC
//To print human readable date we convert it using ctime(&now). Ex: Thu Jun 25 14:32:10 2026
//ctime() returns a C-string  and in c/c++ string is represented as a pointer to char.
//i.e it returns a pointer to the first character of that string
//dt is a c-style string char* , but c++ strings are easier to work with, so string s(dt);

//ctime() automatically appends \n, at the end so we are checking whether the given string is not empty then remove \n
//ctime() returns string "Thu Jun 25 15:30:45 2026\n"
//in memory it looks like
// address     value
//  1000         'T'
//  1001          'h' etc. dt stores the address of first charcter from string

