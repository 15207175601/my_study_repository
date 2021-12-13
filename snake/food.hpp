#ifndef __FOOD
#define __FOOD

#include<random>

extern std::default_random_engine dre;
extern std::uniform_int_distribution<int> di;

struct Food {
	int x = di(dre);
	int y = di(dre);
	bool flag = 1;
	bool eated() {
		return !flag;
	}
	void reset() {
		x = di(dre);
		y = di(dre);
	}
};

#endif //__FOOD