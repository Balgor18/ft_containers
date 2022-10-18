#include <iostream>
#include "set.hpp"
#include <string>
#include <cmath>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif
// Consturctor test
struct Point { double x, y; };
struct PointCmp {
	bool operator()(const Point& lhs, const Point& rhs) const { 
		return std::hypot(lhs.x, lhs.y) < std::hypot(rhs.x, rhs.y); 
	}
};

void	constructor_test()
{
	NAMESPACE::set<std::string> a;
	a.insert("cat");
	a.insert("dog");
	a.insert("horse");
	for(auto& str: a) std::cout << str << ' ';
	std::cout << '\n';
	
	// (2) Iterator constructor
	NAMESPACE::set<std::string> b(a.find("dog"), a.end());
	for(auto& str: b) std::cout << str << ' ';
	std::cout << '\n';
	
	// (3) Copy constructor
	NAMESPACE::set<std::string> c(a);
	c.insert("another horse");
	for(auto& str: c) std::cout << str << ' ';
	std::cout << '\n';
	
	// (4) Move constructor
	NAMESPACE::set<std::string> d(std::move(a));
	for(auto& str: d) std::cout << str << ' ';
	std::cout << '\n';
	std::cout << "moved-from set is ";
	for(auto& str: a) std::cout << str << ' ';
	std::cout << '\n';

}

// Operator = test
void	operator_equal_test()
{
	int myints[]={ 12,82,37,64,15 };
	NAMESPACE::set<int> first (myints,myints+5);   // set with 5 ints
	NAMESPACE::set<int> second;                    // empty set

	second = first;                          // now second contains the 5 ints
	first = NAMESPACE::set<int>();                 // and first is empty

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
}

void	iterator_test()
{
	int myints[] = {75,23,65,42,13};
	NAMESPACE::set<int> myset (myints,myints+5);

	std::cout << "iterator" << std::endl;
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << *it << '\n';

	std::cout << "const_iterator" << std::endl;
	for (NAMESPACE::set<int>::const_iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << *it << '\n';

	std::cout << "reverse_iterator" << std::endl;
	NAMESPACE::set<int>::reverse_iterator rit;
	for (rit=myset.rbegin(); rit!=myset.rend(); ++rit)
		std::cout << *rit << '\n';

	std::cout << "const_reverse_iterator" << std::endl;
	NAMESPACE::set<int>::const_reverse_iterator crit;
	for (crit=myset.rbegin(); crit!=myset.rend(); ++crit)
		std::cout << *crit << '\n';
}

void	capacity_test()
{
	NAMESPACE::set<int> myset;

	std::cout << "Empty test :" << std::endl;
	myset.insert(20);
	myset.insert(30);
	myset.insert(10);


	while (!myset.empty())
	{
		std::cout << *myset.begin() << '\n';
		myset.erase(myset.begin());
	}

	std::cout << "size test :" << std::endl;
	myset.insert (100);

	std::cout << "myset.size() is " << myset.size() << '\n';
	std::cout << "maxsize test" << std::endl;
	std::cout << "myset.maxsize() " << myset.max_size() << std::endl;

}

void	insert_test()
{
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;
	NAMESPACE::pair<NAMESPACE::set<int>::iterator,bool> ret;

	// set some initial values:
	for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

	ret = myset.insert(20);               // no new element inserted

	if (ret.second==false) it=ret.first;  // "it" now points to element 20

	myset.insert (it,25);                 // max efficiency inserting
	myset.insert (it,24);                 // max efficiency inserting
	myset.insert (it,26);                 // no max efficiency inserting

	int myints[]= {5,10,15};              // 10 already in set, not inserted
	myset.insert (myints,myints+3);

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	erase_test()
{
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;

	// insert some values:
	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	++it;                                         // "it" points now to 20

	myset.erase (it);

	myset.erase (40);

	it = myset.find (60);
	myset.erase (it, myset.end());

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	swap_test()
{
	int myints[]={12,75,10,32,20,25};
	NAMESPACE::set<int> first (myints,myints+3);     // 10,12,75
	NAMESPACE::set<int> second (myints+3,myints+6);  // 20,25,32

	first.swap(second);

	std::cout << "first contains:";
	for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (NAMESPACE::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	clear_test()
{
	NAMESPACE::set<int> myset;

	myset.insert (100);
	myset.insert (200);
	myset.insert (300);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert (1101);
	myset.insert (2202);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	comp_test()
{
	NAMESPACE::set<int> myset;
	int highest;

	NAMESPACE::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	NAMESPACE::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';


	NAMESPACE::set<int>::value_compare mycomp2 = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp2(*(++it),highest) );

	std::cout << '\n';
}

void	find_test()
{
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	it=myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	count_test()
{
  NAMESPACE::set<int> myset;

  // set some initial values:
  for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

  for (int i=0; i<10; ++i)
  {
    std::cout << i;
    if (myset.count(i)!=0)
      std::cout << " is an element of myset.\n";
    else
      std::cout << " is not an element of myset.\n";
  }
}

void	bound_test()
{
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

void	equal_test()
{
	NAMESPACE::set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	NAMESPACE::pair<NAMESPACE::set<int>::const_iterator,NAMESPACE::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';

}

void	allocator_test()
{
	NAMESPACE::set<int> myset;
	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	myset.get_allocator().deallocate(p,5);

}

int main ()
{
	std::cout << "Constructor test" << std::endl;
	constructor_test();
	std::cout << "================" << std::endl;
	std::cout << "operator_equal test" << std::endl;
	operator_equal_test();
	std::cout << "================" << std::endl;
	std::cout << "iterator test" << std::endl;
	iterator_test();
	std::cout << "================" << std::endl;
	std::cout << "capacity test" << std::endl;
	capacity_test();
	std::cout << "================" << std::endl;
	std::cout << "insert test" << std::endl;
	insert_test();
	std::cout << "================" << std::endl;
	std::cout << "erase test" << std::endl;
	erase_test();
	std::cout << "================" << std::endl;
	std::cout << "swap test" << std::endl;
	swap_test();
	std::cout << "================" << std::endl;
	std::cout << "clear test" << std::endl;
	clear_test();
	std::cout << "================" << std::endl;
	std::cout << "comp test" << std::endl;
	comp_test();
	std::cout << "================" << std::endl;
	std::cout << "find test" << std::endl;
	find_test();
	std::cout << "================" << std::endl;
	std::cout << "count test" << std::endl;
	count_test();
	std::cout << "================" << std::endl;
	std::cout << "bound test" << std::endl;
	bound_test();
	std::cout << "================" << std::endl;
	std::cout << "equal test" << std::endl;
	equal_test();
	std::cout << "================" << std::endl;
	std::cout << "allocator test" << std::endl;
	allocator_test();
	std::cout << "================" << std::endl;
	return 0;
}