# include <map>
# include <string>
#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include <iterator>
#include <algorithm>
#include <set>
#include "pair.hpp"
#include "map.hpp"

int main()
{
	ft::map<int , std::string> map1;

	map1.insert(ft::make_pair<int, std::string>(2, "Test"));
	return EXIT_SUCCESS;
}