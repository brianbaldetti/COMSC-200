//
//  main.cpp
//  MapExercise01
//
//  Created by brian on 10/25/22.
//
// Goal: To learn three types of map insert() functions, find() function and
// how the content in a map object can be displayed.
#include <iostream>
#include <map>
using namespace std;
 
int main ()
{
  map<char,int> myMap; //creates a map named myMap with the char data type for key and the int data type for its value
 
  // first insert function version (single parameter):
  myMap.insert ( pair<char, int>('z', 200) );   //adds the key 'z' to the map with 200 as its value
  myMap.insert ( pair<char, int>('a', 100) );   //adds the key 'a' to the map with 100 as its value
    myMap.insert( {'f', 420} );
 
 
  //creates a pair datatype 'ret' that contains a map iterator for first value and a bool for second
  pair<map<char,int>::iterator, bool> ret;
 
  ret = myMap.insert ( pair<char,int>('d', 500) );
  // Q1: What is returned from a map insert? Why it is not a bool value?
 
  //runs if the value is false
  if (!ret.second)
  {
    cout << "Element " << ret.first->first << " already exist " << " with a value of " << ret.first->second << ".\n";
  }
  else
      cout << "Element " << ret.first->first << " has been inserted.\n";
 
  // second insert function version with hint position at the beginning of the loop
  map<char,int>::iterator it = myMap.begin();
  myMap.insert (it, pair<char,int>('c', 400));  // max efficiency inserting
  myMap.insert (it, pair<char,int>('b', 300));  // no max efficiency inserting
 
  // third insert function version (range insertion):
  map<char,int> myMap2;
  myMap2.insert(myMap.begin(), myMap.find('z'));
  // Q2: What does myMap.find() return? Could you test the find() function, get its
  // return iterator and display its values?
    map<char,int>::iterator Q2 = myMap.find('c');
    if (Q2 != myMap.end())
    {
        cout << "The element " << Q2->first << " is found with a vlaue of: " << Q2->second << endl;
    }
    else
    {
        cout << "The element " << Q2->first << " is found with a value of: " << Q2->second << endl;
    }
 
  // Q3: Change the statement above to myMap2.insert(++myMap.begin(),myMap.find('c'));
  //    and see the difference.
  //This causes the first element to not be inserted due to the prefix notation of ++'myMap'.begin()

  // Q4: Change the statement above to myMap2.insert(myMap.begin()++,myMap.find('c'));
  //    and see the difference.
  // This causes the nothing to be changed though I think that it should cause the second iterator to be skipped.
 
  // Q5: Change the statement above to myMap2.insert(myMap.begin(),myMap.find('z'));
  //    and see the difference.
  //This will causes the 'myMap' to be copied to 'myMap2' untill 'z' is encountered
 
  // Q6: What is the time complexity when using find()?
  //The time complexity should be O(n).
 
 
  // showing contents:
  cout << endl << endl;
  cout << "myMap contains:\n";
  for (it = myMap.begin(); it != myMap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
 
  cout << endl << endl;
  cout << "myMap2 contains:\n";
  for (it = myMap2.begin(); it != myMap2.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
 
  return 0;
}
