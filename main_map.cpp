# include <map>
# include <string>
#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include <iterator>
#include <algorithm>
#include <set>
#include "pair.hpp"
#include "Map.hpp"
#include <iomanip>

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

template <class Key, class T>
void	print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  ft::map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
  // show content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';

	std::cout << "Hello there\n";
	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
	std::cout << "General Kenobi\n";

	ft::map<char, int>::const_iterator it = mymap.begin();
	ft::map<char, int>::const_iterator ti = mymap.end();
	std::cout << "Wupwup\n";

	it++;
	++it;
	it--;
	--it;
	std::cout << "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	std::cout << "Trump is a kiddo\n";
	ft::map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
		std::cout << it->first << " => " << it->second << '\n';
		it++;
	}

  return 0;
}
