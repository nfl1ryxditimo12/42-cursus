#include "test.hpp"

void	map_test(void)
{
	clock_t	f_start, f_end;
	clock_t	s_start, s_end;

	ft::map<int, int>	f_map;
	ft::map<int, int>	f_map2;
	std::map<int, int>	s_map;
	std::map<int, int>	s_map2;

	/* Element access */

	f_start = clock();
	for (int i = 0; i < 10; i++)
		f_map[i] = i + 1;
	f_end = clock();

	s_start = clock();
	for (int i = 0; i < 10; i++)
		s_map[i] = i + 1;
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* insert */

	f_start = clock();
	for (int i = 0; i < 30; i++)
		f_map.insert(f_map.end(), ft::pair<int, int>(i + 31, i + 31));
	f_end = clock();

	s_start = clock();
	for (int i = 0; i < 30; i++)
		s_map.insert(s_map.end(), std::pair<int, int>(i + 31, i + 31));
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	f_start = clock();
	for (int i = 0; i < 30; i++)
		f_map2.insert(f_map.begin(), f_map.end());
	f_end = clock();

	s_start = clock();
	for (int i = 0; i < 30; i++)
		s_map2.insert(s_map.begin(), s_map.end());
	s_end = clock();

	print(f_map2, s_map2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* erase */

	f_start = clock();
	ft::map<int, int>::iterator f_it = f_map.begin();
	for (int i = 0; i < 15; i++)
		f_it++;
	f_map.erase(f_it);
	f_end = clock();

	s_start = clock();
	std::map<int, int>::iterator s_it = s_map.begin();;
	for (int i = 0; i < 15; i++)
		s_it++;
	s_map.erase(s_it);
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	f_start = clock();
	f_map.erase(42);
	f_end = clock();

	s_start = clock();
	s_map.erase(42);
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	f_it = f_map.begin();
	s_it = s_map.begin();
	ft::map<int, int>::iterator f_eit = f_map.end();
	std::map<int, int>::iterator s_eit = s_map.end();

	--f_eit;
	--s_eit;

	f_start = clock();
	f_map.erase(f_it, f_map.end());
	f_end = clock();

	s_start = clock();
	s_map.erase(s_it, s_map.end());
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* swap */

	f_start = clock();
	f_map.swap(f_map2);
	f_end = clock();

	s_start = clock();
	s_map.swap(s_map2);
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_map2, s_map2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* copy constructor */

	f_start = clock();
	ft::map<int, int> f_map3(f_map);
	f_end = clock();

	s_start = clock();
	std::map<int, int> s_map3(s_map);
	s_end = clock();

	print(f_map3, s_map3, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* copy assignment operator */

	ft::map<int, int> f_map4;
	std::map<int, int> s_map4;

	f_start = clock();
	f_map4 = f_map;
	f_end = clock();

	s_start = clock();
	s_map4 = s_map;
	s_end = clock();

	print(f_map4, s_map4, true, sub_time(f_start, f_end), sub_time(s_start, s_end));

	/* clear */

	f_start = clock();
	f_map.clear();
	f_map2.clear();
	f_map3.clear();
	f_map4.clear();
	f_end = clock();

	s_start = clock();
	s_map.clear();
	s_map2.clear();
	s_map3.clear();
	s_map4.clear();
	s_end = clock();

	print(f_map, s_map, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_map2, s_map2, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_map3, s_map3, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
	print(f_map4, s_map4, true, sub_time(f_start, f_end), sub_time(s_start, s_end));
}