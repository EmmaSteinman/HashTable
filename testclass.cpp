#include <iostream>
using namespace std;
#include <math.h>
#include "HashTable.h"


class test
{
public:
  int key;

  test(void){key = 0;};
  test(int k){key = k;};
  ~test(void){};

  int hash ( int slots )
  {/*
    float m = slots;
    float hval = 0;
    float A = (sqrt(5)-1)/2;
    float q = fmod((hval * A), 1);
    hval = floor(m * q);
    return hval;*/
    return 7;
  }
  bool operator< ( test& a) const
  {
    return *this < a;
  };
  bool operator> (const test& a)           //overloading comparison operators
  {                                         //to compare key specifically
    return *this > a;
  };
  bool operator== (const test& a)
  {
    return *this == a;
  };
  bool operator!= (const test& a)
  {
    return *this != a;
  };
};

int main ( void )
{
  test *t = new test;
  t->key = 5;
  HashTable<test> t1(10);
  cout << "<" << endl;
  cout << t1.toString(0) << endl;
  //cout << t1.toString(1) << endl;
  //t1.insert(t);





  return 0;
}
