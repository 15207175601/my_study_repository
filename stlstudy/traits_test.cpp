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

struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag:public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};

/*template <class I,class T>
void func_impl(I iter,T t){
    T temp;
    //...
}

template<class I>
void func(I iter){
    func_impl(iter,*iter);
}

template <class I>
typename iterator_traits<I>::value_type
func(I iter){
    return *iter;
}*/
template<class Category,class T,class Distance=ptrdiff_t,class Pointer=T*,class Reference=T&>
struct iterator
{
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
};



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
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef ptrdiff_t                   difference_type;
    typedef T*                          pointer;
    typedef T&                          reference;
};

template <class T>
struct iterator_traits<const T*>{
    typedef random_access_iterator_tag  iterator_category;
    typedef const T                     value_type;
    typedef ptrdiff_t                   difference_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;
};

template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&){
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}

template <class Iterator>
inline typename iterator_traits<Iterator>::difference_type*
difference_type(const Iterator&){
    return static_cast<typename iterator_traits<Iterator>::difference_type>(0);
}

template <class Iterator>
inline typename iterator_traits<Iterator>::value_type*
value_type(const Iterator&){
    return static_cast<typename iterator_traits<Iterator>::value_type>(0);
}


template <class I,class T>
typename iterator_traits<I>::difference_type count(I first,I last,const T& value){
    typename iterator_traits<I>::difference_type n=0;
    for(;first!=lats;++first)
        if(*first==value)
            ++n;
    return n;
}

/*template <class InputIterator,class Distance>
void advance_II(InputIterator& i,Distance n){
    while(n--) ++i;
}

template <class BidirectionalIterator,class Distance>
void advance_BI(BidirectionalIterator& i,Distance n){
    if(n>=0)
        while(n--) ++i;
    else
        while(n++) --i;
}

template <class RandomAccessIterator,class Distance>
void advance_RAI(RandomAccessIterator& i,Distance n){
    i+=n;
}*/

template <class InputIterator,class Distance>
inline void __advance(InputIterator& i,Distance n,input_iterator_tag){
    while(n--) ++i;
}

template <class InputIterator,class Distance>
inline void __advance(InputIterator& i,Distance n,forward_iterator_tag){
    __advance(i,n,input_iterator_tag());
}

template <class BidirectionalIterator,class Distance>
inline void __advance(BidirectionalIterator& i,Distance n,bidirectional_iterator_tag){
    if(n>=0)
        while(n--) ++i;
    else
        while(n++) --i;
}

template <class RandomAccessIterator,class Distance>
inline void __advance(RandomAccessIterator& i,Distance n,random_access_iterator_tag){
    i+=n;
}


template <class InputIterator,class Distance>
inline void advance(InputIterator& i,Distance n){
    __advance(i,n,iterator_category(i))
}

template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type 
__distance(InputIterator first,InputIterator last,input_iterator_tag){
    iterator_traits<InputIterator>::difference_type n=0;
    for(;first!=last;++first){
        ++n;
    }
    return n;
}

template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type 
__distance(InputIterator first,InputIterator last,forward_iterator_tag){
    __distance(first,last,input_iterator_tag());
}

template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type 
__distance(InputIterator first,InputIterator last,bidirectional_iterator_tag){
    typename iterator_traits<InputIterator>::difference_type n=0;
    if(first<=last){
        for(;first!=last;++first){
            ++n;
        }
    }
    else{
        for(;first!=last;--first){
            ++n;
        }
    }
    return n;
}

template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type 
__distance(InputIterator first,InputIterator last,random_access_iterator_tag){
    typename iterator_traits<InputIterator>::difference_type n=0;
    if(first<=last){
        n=last-first;
    }
    else{
        n=first-last;
    }
    return n;
}

template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type 
distance(InputIterator first,InputIterator last){
    __distance(first,last,iterator_traits<InputIterator>::iterator_category());
}