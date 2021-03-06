//Hannah Kerr and Emma Steinman
//dictionary.h
//This file implements a dictionary via inheritance from our bst class
//November 1, 2017

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "HashTable.h"

template <class KeyType>
class Dictionary
{

public:
              Dictionary  (){};    //default constructor
              ~Dictionary (void){};    //destructor
              Dictionary  (const Dictionary<KeyType> &d){};     //copy constructor
  void        insert      (KeyType *k)
  {
    d->insert(k);
  };
  void        remove      (const KeyType &k)
  {
    d->remove(k);
  };
  KeyType *   get         (const KeyType &k) const
  {
    return d->get(k);
  };
  bool        Empty       (void)  const
  {
    return d->Empty();
  };

private:
  HashTable<KeyType> *d;

};
#endif
