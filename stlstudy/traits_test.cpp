#include<iostream>
/*template <typename T>
void func(T t){
    std::cout<<t<<std::endl;
}


template <typename T>
void func(T t){
    std::cout<<t<<std::endl;
}

template <typename T>
void func(T* t){
    std::cout<<*t<<std::endl;
}

int main(){
    int x=0;
    int *p=&x;
    func(x);
    func(p);
    return 0;
}*/

template <class I,class T>
void func_impl(I iter,T t){
    T temp;
    //...
}

template<class I>
void func(I iter){
    func_impl(iter,*iter);
}

template <class I>
struct iterator_traits{
    typedef typename I::iterator_category   iterator_category;
    typedef typename I::value_type          value_type;
    typedef typename I::difference_type     difference_type;
    typedef typename I::pointer             pointer;
    typedef typename I::reference           reference;
};

template <class T>
struct iterator_traits<T*>{
    typedef typename random_access_iterator_tag iterator_category;
    typedef typename T                          value_type;
    typedef typename ptrdiff_t                  difference_type;
    typedef typename T*                         pointer;
    typedef typename T&                         reference;
};

template <class I>
typename iterator_traits<I>::value_type
func(I iter){
    return *iter;
}
