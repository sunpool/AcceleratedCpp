#ifndef Guard_Vec_h
#define Guard_Vec_h

#include <cstddef> // ptrdiff_t, size_t
#include <memory>

template<class T>
class Vec final {
    public: 

        typedef T* iterator; 
        typedef const T* const_iterator; 
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;
        typedef std::size_t size_type;

        Vec() { create(); }; 
        // Vec(int n) { create(n); };  // taken in the next declaration 
        explicit Vec(size_type n, const T& t = T()) { create(n, t); };
        Vec(const Vec& vec) { create(vec.begin(), vec.end()); };
        Vec(const_iterator a, const_iterator b) { create(a, b); };
        ~Vec() { uncreate(); }; 

        Vec& operator=(const Vec&);

        size_type size() const { return avail - data; };
        void reserve(size_type);
        // void resize(size_type);

        iterator begin() { return data; };
        const_iterator begin() const { return data; };
        iterator end() { return avail; };
        const_iterator end() const { return avail; };

        T& operator[](size_type i) {return *(data+i); };
        const T& operator[](size_type i) const {return *(data+i); };

        void push_back(const T& t) {
            if(limit == avail)
                grow();
            unchecked_append(t);
        }

    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc; 

        void create();
        // void create(size_type);
        void create(size_type, const T& );
        void create(const_iterator, const_iterator);
        void uncreate();

        void grow(); 
        void grow(size_type); 
        void unchecked_append(const T&);
};

/*  
Template<class T> class allocator {
public: 
    T* allocate(size_t); 
    void deallocate(T*, size_t); 
    void destroy(T*);
    void construct(T*, const T&);
}

template<class In, class for>
For uninitialized_copy(In, In, For); // return iter that is one pass last element 

template<class For, class T>
For uninitialized_fill(For, For, const T&);

*/



template<class T> 
void Vec<T>::create(){
    data = avail = limit = nullptr;
}

// template<class T>
// void Vec<T>::create(std::size_t n){
//     data = avail = alloc.allocate(n);
//     limit = data + n;
// }

template<class T> 
void Vec<T>::create(size_type n, const T& t){
    data = alloc.allocate(n);
    avail = limit = data + n;
    std::uninitialized_fill(data, limit, t);
}

template<class T> 
void Vec<T>::create(const_iterator i, const_iterator j){
    // TODO: feels like I need to uncreate if object already holds data for copy
    // constructor 
    data = alloc.allocate(j - i);
    avail = limit = std::uninitialized_copy(i, j, data);
}

template<class T> 
void Vec<T>::uncreate() {
    // NOTE: C++ style of validity check, and in-/de-creamental variable.
    // Foregot of those in init check
    if(data) {
        iterator it = avail;
        while(data != it) 
            alloc.destroy(--it);

        alloc.deallocate(data, limit - data);
    }

    data = avail = limit = nullptr; 
}

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if(this != &rhs) {
        // TODO: this is not exception safe, need swap implementation
        uncreate();
        create(rhs.begin(), rhs.end()); 
    } 
    return *this; 
}

// note, it is even better to use swap to be exception safe
// following is c++98 style creation first and then "append". also exception safe
template<class T>
void Vec<T>::grow(size_type new_sz) {
    iterator new_ptr = alloc.allocate(new_sz); 
    iterator new_avail = std::uninitialized_copy(data, avail, new_ptr);
    
    uncreate(); 

    data = new_ptr; 
    avail = new_avail;
    limit = data + new_sz;
}

template<class T>
void Vec<T>::reserve(size_type n) {
    if(limit - data < n)
        grow(n);
}

template<class T>
void Vec<T>::grow() {
    size_type new_sz = std::max( (limit - data) * 2, ptrdiff_t(1) ); 
    grow(new_sz);
}

template<class T>
void Vec<T>::unchecked_append(const T& t) {
    alloc.construct(avail++, t);
}

#endif
