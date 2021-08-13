#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode)
{
  // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    for(int i = 0; i < 6; ++i)
    {
        c = c/10;
    }
    d = c % 10;
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode)
{
  // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    for(int i = 0; i < 5; ++i)
    {
        c = c/10;
    }
    d = c % 10;
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode)
{
  // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    for(int i = 0; i < 4; ++i)
    {
        c = c/10;
    }
    d = c % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode)
{
  // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    for(int i = 0; i < 3; ++i)
    {
        c = c/10;
    }
    d = c % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode)
{
    // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    for(int i = 0; i < 2; ++i)
    {
        c = c/10;
    }
    d = c % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode)
{
    // TO BE COMPLETED
    unsigned int d;
    unsigned int c = barcode;
    
    c = c/10;
    d = c % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode)
{
    // TO BE COMPLETED
    unsigned int d;
    
    d = barcode % 10;
    
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)
    //Creates new Item
    Item newItem(itemColor, itemShape, itemBrand, barcode);
    
    //Adds new Item to all 7 hash tables
    hT1[barcode] = newItem;
    hT2[barcode] = newItem;
    hT3[barcode] = newItem;
    hT4[barcode] = newItem;
    hT5[barcode] = newItem;
    hT6[barcode] = newItem;
    hT7[barcode] = newItem;
    
}

bool ItemCollection::removeItem(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false
    
    //Check to see if barcode is found in all 7 hastables
    if(hT1.find(barcode) == hT1.end() &&
       hT2.find(barcode) == hT2.end() &&
       hT3.find(barcode) == hT3.end() &&
       hT4.find(barcode) == hT4.end() &&
       hT5.find(barcode) == hT5.end() &&
       hT6.find(barcode) == hT6.end() &&
       hT7.find(barcode) == hT7.end())
    {
        //if it is not found, return false
        return false;
    }
    else
    {
        //if it is found, remove item from the 7 hash tables
        hT1.erase(barcode);
        hT2.erase(barcode);
        hT3.erase(barcode);
        hT4.erase(barcode);
        hT5.erase(barcode);
        hT6.erase(barcode);
        hT7.erase(barcode);
    }

    return true;
}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

    unsigned int balance[8];
    balance[0] = 0;
    int min = 100;  //used to calculate the minimum balance

    unsigned int min_loc, max_loc;
    
    //used to find the difference between the minimum and
    //maximum of each bucket in each hash table
    int min1 = 100, max1 = 0;
    int min2 = 100, max2 = 0;
    int min3 = 100, max3 = 0;
    int min4 = 100, max4 = 0;
    int min5 = 100, max5 = 0;
    int min6 = 100, max6 = 0;
    int min7 = 100, max7 = 0;
    
    //calculate the minimum and maximum buckets in each hash table
    //then calculate the difference and insert the value into the balance array
    for(int i = 0; i < 10; ++i)
    {
        if(min1 > hT1.bucket_size(i))
        {
            min1 = hT1.bucket_size(i);
        }
        if(max1 < hT1.bucket_size(i))
        {
            max1 = hT1.bucket_size(i);
        }
    }
    balance[1] = max1 - min1;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min2 > hT2.bucket_size(i))
        {
            min2 = hT2.bucket_size(i);
        }
        if(max2 < hT2.bucket_size(i))
        {
            max2 = hT2.bucket_size(i);
        }
    }
    balance[2] = max2 - min2;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min3 > hT3.bucket_size(i))
        {
            min3 = hT3.bucket_size(i);
        }
        if(max3 < hT3.bucket_size(i))
        {
            max3 = hT3.bucket_size(i);
        }
    }
    balance[3] = max3 - min3;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min4 > hT4.bucket_size(i))
        {
            min4 = hT4.bucket_size(i);
        }
        if(max4 < hT4.bucket_size(i))
        {
            max4 = hT4.bucket_size(i);
        }
    }
    balance[4] = max4 - min4;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min5 > hT5.bucket_size(i))
        {
            min5 = hT5.bucket_size(i);
        }
        if(max5 < hT5.bucket_size(i))
        {
            max5 = hT5.bucket_size(i);
        }
    }
    balance[5] = max5 - min5;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min6 > hT6.bucket_size(i))
        {
            min6 = hT6.bucket_size(i);
        }
        if(max6 < hT6.bucket_size(i))
        {
            max6 = hT6.bucket_size(i);
        }
    }
    balance[6] = max6 - min6;
    
    for(int i = 0; i < 10; ++i)
    {
        if(min7 > hT7.bucket_size(i))
        {
            min7 = hT7.bucket_size(i);
        }
        if(max7 < hT7.bucket_size(i))
        {
            max7 = hT7.bucket_size(i);
        }
    }
    balance[7] = max7 - min7;
    
    //find the minimum balance in the balance array
    for(int i = 0; i < 8; ++i)
    {
        if(balance[i] < min)
        {
            min = balance[i];
            min_loc = i;
        }
    }
    //return the table with the least balance
    return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
