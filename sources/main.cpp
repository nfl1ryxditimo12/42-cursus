#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include "common.hpp"
#include "test.hpp"

#include <list>

#define TESTED_TYPE int

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct, std::vector<int> const &s_vct)
{
	std::cout << "is_empty: " << vct.empty() << ", " << s_vct.empty() << std::endl;
}

void erase()
{
	const int start_size = 7;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	std::vector<TESTED_TYPE> s_vct(start_size, 20);
	std::vector<TESTED_TYPE> s_vct2;
	std::vector<TESTED_TYPE>::iterator s_it = s_vct.begin();

	for (int i = 2; i < start_size; ++i) {
		it[i] = (start_size - i) * 3;
		s_it[i] = (start_size - i) * 3;
	}
	print(vct, s_vct);

	vct.resize(10, 42);
	s_vct.resize(10, 42);
	print(vct, s_vct);

	vct.resize(18, 43);
	s_vct.resize(18, 43);
	print(vct, s_vct);
	vct.resize(10);
	s_vct.resize(10);
	print(vct, s_vct);
	vct.resize(23, 44);
	s_vct.resize(23, 44);
	print(vct, s_vct);
	vct.resize(5);
	s_vct.resize(5);
	print(vct, s_vct);
	vct.reserve(5);
	s_vct.reserve(5);
	vct.reserve(3);
	s_vct.reserve(3);
	print(vct, s_vct);
	vct.resize(87);
	s_vct.resize(87);
	vct.resize(5);
	s_vct.resize(5);
	print(vct, s_vct);

	is_empty(vct2, s_vct2);
	vct2 = vct;
	s_vct2 = s_vct;
	is_empty(vct2, s_vct2);
	vct.reserve(vct.capacity() + 1);
	s_vct.reserve(s_vct.capacity() + 1);
	print(vct, s_vct);
	print(vct2, s_vct2);

	vct2.resize(0);
	s_vct2.resize(0);
	is_empty(vct2, s_vct2);
	print(vct2, s_vct2);
}

int main(void)
{
	erase();
	return (0);
}