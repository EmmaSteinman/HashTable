/*
* hash table class methods
* lindsey siegfried
* 6 november 2017
*/



/*-------------------------------
* default constructor (unspecified slots)
-------------------------------*/
template <class KeyType>
    HashTable<KeyType>::HashTable(void)
{
  slots = 1000;
  table = new List<KeyType>[slots];
  //cout << slots << endl;
}

/*-------------------------------
* default constructor (specified slots)
-------------------------------*/
template <class KeyType>
    HashTable<KeyType>::HashTable(int numSlots)
{
    slots = numSlots;
    table = new List<KeyType>[slots];
}

/*-------------------------------
* copy constructor
-------------------------------*/
template <class KeyType>
    HashTable<KeyType>::HashTable(const HashTable<KeyType>& h)
{
    slots = h.slots;
    table = new List<KeyType>;
    for (int i = 0; i < h.slots; i++)
    {
        table[i] = h[i];
    }
}

/*-------------------------------
* destructor
-------------------------------*/
template <class KeyType>
    HashTable<KeyType>::~HashTable()
{
    for (int i = 0; i < slots; i++)
    {
      int count = 0;
      while (table[i][count] != NULL)
      {
        delete table[i][count];
        count += 1;
      }
    }
    slots = 0;
    delete[] table;

}

/*-------------------------------
* get
* this method returns a pointer to the object in the hash table where the value resides
* parameters: const KeyType& k for which to find
* return value: KeyType* location
-------------------------------*/
template <class KeyType>
KeyType* HashTable<KeyType>::get(const KeyType& k) const
{
  int where2look = k.hash(slots);
  return table[where2look].get(k);
}

/*-------------------------------
* insert
* this method inserts a value into the hash table
* parameters: KeyType* k to insert
* return value: void
-------------------------------*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType* k)
{
  //cout << slots << endl;
  int slot = k->hash(slots);
  cout << slot<< endl;

  table[slot].append(k);


}

/*-------------------------------
* remove
* this method removes a given value from the hash table
* parameters: const KeyType& k to remove
* return value: void
-------------------------------*/
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{
  int slot = k->hash(slots);
  table->remove(k);

}

/*-------------------------------
* assignment operator
* this operator assigns a hash table to *this
* parameters: const HashTable<KeyType>& h existing hash table to copy
* return value: HashTable<KeyType>& new hash table
-------------------------------*/
template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h)
{
  delete[] table;
  table = h.table;
  return *this;
}

/*-------------------------------
* toString
* this method returns the list located in a given slot as a string
* parameters: int slot
* return value: string
-------------------------------*/
template <class KeyType>
string HashTable<KeyType>::toString(int slot) const
{
  stringstream ss;
  List<KeyType> t = table[slot];
  int i = 0;
  while (t[i] != NULL)
  {
    ss << t[i];
    if (t[i+1] != NULL)
      ss << " ";
    i++;
  }
  return ss.str();
}




template <class KeyType>
bool  HashTable<KeyType>::Empty(void) const
{
  return (table == NULL);
}
