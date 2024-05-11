#include "test.hpp"

void	vector_test(void)
{
	clock_t	f_start, f_end;
	clock_t	s_start, s_end;

	ft::vector<int>		f_vec(7);
	ft::vector<int>		f_vec2;

	std::vector<int>	s_vec(7);
	std::vector<int>	s_vec2;

	/* push_back */

	f_start = clock();
	for (int i = 1; i <= 30; i++) 
		f_vec.push_back(i);
	f_end = clock();

	s_start = clock();
	for (int i = 1; i <= 30; i++) 
		s_vec.push_back(i);
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* pop_back */
	
	f_start = clock();
	for (int i = 1; i <= 10; i++) 
		f_vec.pop_back();
	f_end = clock();

	s_start = clock();
	for (int i = 1; i <= 10; i++) 
		s_vec.pop_back();
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* insert */

	f_start = clock();
	f_vec.insert(f_vec.begin(), 10, 77);
	f_end = clock();

	s_start = clock();
	s_vec.insert(s_vec.begin(), 10, 77);
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	f_start = clock();
	f_vec.insert(f_vec.begin() + 3, f_vec.begin() + 5, f_vec.begin() + 15);
	f_end = clock();

	s_start = clock();
	s_vec.insert(s_vec.begin() + 3, s_vec.begin() + 5, s_vec.begin() + 15);
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* assign */

	f_start = clock();
	f_vec2.assign(f_vec.begin() + 10, f_vec.end());
	f_end = clock();

	s_start = clock();
	s_vec2.assign(s_vec.begin() + 10, s_vec.end());
	s_end = clock();

	print(f_vec2, s_vec2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	f_start = clock();
	f_vec2.assign(10, 22);
	f_end = clock();

	s_start = clock();
	s_vec2.assign(10, 22);
	s_end = clock();

	print(f_vec2, s_vec2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* swap */

	f_start = clock();
	f_vec.swap(f_vec2);
	f_end = clock();

	s_start = clock();
	s_vec.swap(s_vec2);
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_vec2, s_vec2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* copy constructor */

	f_start = clock();
	ft::vector<int> f_vec3(f_vec);
	f_end = clock();

	s_start = clock();
	std::vector<int> s_vec3(s_vec);
	s_end = clock();

	print(f_vec3, s_vec3, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	ft::vector<int> f_vec4;
	std::vector<int> s_vec4;

	f_start = clock();
	f_vec4 = f_vec2;
	f_end = clock();

	s_start = clock();
	s_vec4 = s_vec2;
	s_end = clock();

	print(f_vec4, s_vec4, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* clear */

	f_start = clock();
	f_vec.clear();
	f_vec2.clear();
	f_vec3.clear();
	f_vec4.clear();
	f_end = clock();

	s_start = clock();
	s_vec.clear();
	s_vec2.clear();
	s_vec3.clear();
	s_vec4.clear();
	s_end = clock();

	print(f_vec, s_vec, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_vec2, s_vec2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_vec3, s_vec3, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_vec4, s_vec4, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
}
