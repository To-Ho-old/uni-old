#ifndef _FLEXARRAY_H
#define _FLEXARRAY_H


//   This will disallow a typically erroneous implicit type-conversion:
//   flexarray a( 10 );
//   a = 0; // Oops!! Allowed because of implicit type-conversion.
//   
//   An explicit member function is needed for each of 
//   a) copy constructor
//   b) destructor
//   c) copy assignment operator
class flexarray
{
  public:
    // Constructor that can specify size, intialization value, and lowest index 

    explicit flexarray( int size=0,  const int &fillValue = 0, int lb=0);

    flexarray( const flexarray& fla );   // copy constructor 

    ~flexarray( );                        // destructor 

  // assignment
    const flexarray & operator= ( const flexarray & fla );

  // accessors
    int  length( ) const;                   // number of  elements 
    int  lbound() const;                    // lowest index
    int  ubound() const;                    // highest index
  // indexing
    int &       operator [ ] ( int index );   // indexing with range checking non const object
    const int & operator [ ] ( int index ) const; // indexing with range checking const object

  // modifiers
    void resize( int newSize );             // change size dynamically;
                                            // can result in losing values
  private:

    int  mySize;                            // # elements in array
    int * myList;                           // array used for storage
    int lower;                              // lower bound of index
};

// *******************************************************************
//  Specifications for flexarray functions
//
//
//  Any violation of a function's precondition will result in an error message
//  followed by a call to exit.
//
//  constructors
//  The constructor has three parameters and each can take default value so that
//  there are four possible ways of creating an object using none, one, two, or all
//  three of the default values
//
//   flexarray( )
//     postcondition: flexarray is created and has space for zero int, and therefore it will
//                    need to be resized before any element can be inserted. The lowest index  
//                    is set to zero. 
//   flexarray( int size )
//     precondition: size >= 0
//     postcondition: flexarray is created and has space for size ints. If size > 0 then all the elements 
//                    are initialized to zero. The lowest index is set to zero.      
//
//   flexarray( int size, const int & fillValue )
//     precondition: size >= 0
//     postcondition: flexarray is created and has space for size ints, all of which are set
//                    by assignment to fillValue after default construction. The lowest index 
//                    is set to zero.
//   flexarray( int size, const int & fillValue, int lb )
//     precondition: size >= 0
//     postcondition: flexarray is created and has space for size ints, all of which are set
//                    by assignment to fillValue after default construction. The lowest index
//                    is set to lb.

//
//   flexarray( const flexarray & fla )
//     postcondition: flexarray object is a copy of fla

//   ~flexarray( )
//     postcondition: flexarray is destroyed i.e. memory held by it is released to Free Store
//
//  Assignment:
//
//   const flexarray & operator= ( const flexarray & rhs )
//     postcondition: normal assignment via copying has been performed;
//                    if flexarray and rhs were different sizes, flexarray
//                    has been resized to  match the size of rhs
//
//  Accessor:
//
//   int  length( ) const
//     postcondition: returns flexarray's size (number of memory cells
//                    allocated for flexarray)
//
//  Indexing:
//
//   int &       operator [ ] ( int k )       -- index into nonconst flexarray
//   const int & operator [ ] ( int k ) const -- index into const flexarray
//     description: range-checked indexing, returning kth item
//     precondition: lower <= k < lower + length() 
//     postcondition: returns the item at index k 
//
//  Modifier
//
//   void resize( int newSize )
//     description:  resizes the flexarray to newSize elements
//     precondition: the current size of flexarray is length; newSize >= 0
//
//     postcondition: the current size of flexarray is newSize; for each k
//                    such that lower <= k <= min(length()+lower, newSize+lower), flexarray[k]
//                    is a copy of the original; other elements of flexarray are
//                    initialized using the 0-argument constructor
//                    Note: if newSize < length, elements may be lost
//
//  examples of use
//      flexarray<int> v1;              // 0-element flexarray
//      flexarray<int> v2(4);           // 4-element flexarray
//      flexarray<int> v3(4, 22);       // 4-element flexarray, all elements initialized  to 22.
//      flexarray<int> v4(4,22,-1);     // 4-element flexarray, all elements nitialized to 22 and 
//                                      // index of the first element is -1

#endif




