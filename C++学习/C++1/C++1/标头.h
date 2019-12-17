#pragma once

class Counter
{
	template <class T> friend class SmartPointer;
	Counter(int u) :use(u) {}
	~Counter() {}
	int use;
};
template <typename T>
class SmartPointer
{
public:
	SmartPointer(T* t) :pc(new Counter(1).pt(t))
	{
		cout << " SmartPointer Constructor Called. " << endl;
	}
	SmartPointer(const SmartPointer<T>& rhs) :
		pc(rhs.pc), pt(rhs.pt)
	{
		cout << " SmartPointer Copy Constructor Called" << endl;
	}
	~SmartPointer()
	{
		int x = pt->getX();
		int y = pt->getY();
		cout << "SmartPointer(" << x << "," << y << ") Destructor Begin." << endl;
		decrement();
		cout << "SmartPointer(" << x << "," << y << ") Destructor End." << endl;
	}
	T& operator* ()
	{
		return *pt;
	}
	const T* operator->() const
	{
		return pt;
	}
	SmartPointer <T>& operator=(const SmartPointer<T>& rhs)
	{
		if (*this == rhs)
		{
			return *this;
		}
		decrement();
		pt = rhs.pt;
		pc = rhs.pc;
		pc->use++;

		return *this
	}
	bool operator==(const SmartPointer <T>& rhs)
	{
		return rhs.pt == pt;
	}
private:
	void decrement()
	{
		pc->use--;

		if (pc->use == 0)
		{
			delete pt;
			delete pc;
		}
	}
	T* pt;
	Couter* pc;
};