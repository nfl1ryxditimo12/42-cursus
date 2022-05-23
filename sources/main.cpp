#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include "common.hpp"
#include "test.hpp"

/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/

#define TESTED_TYPE int

void vector_test()
{
	std::vector<TESTED_TYPE> vec(10);
	std::vector<TESTED_TYPE> vec2;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i) {
		vct[i] = (vct.size() - i) * 3;
		vec[i] = (vec.size() - i) * 3;
	}
	print(vct, vec);

	vct2.insert(vct2.end(), 42);
	vec2.insert(vec2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	vec2.insert(vec2.begin(), 2, 21);
	print(vct2, vec2);

	vct2.insert(vct2.end() - 2, 42);
	vec2.insert(vec2.end() - 2, 42);
	print(vct2, vec2);

	vct2.insert(vct2.end(), 2, 84);
	vec2.insert(vec2.end(), 2, 84);
	print(vct2, vec2);

	vct2.resize(4);
	vec2.resize(4);  
	print(vct2, vec2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vec2.insert(vec2.begin() + 2, vec.begin(), vec.end());
	vct.clear();
	vec.clear();
	print(vct2, vec2);

	print(vct, vec);
}

int main()
{
	try {
		vector_test();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// system("leaks ft_container");
}
