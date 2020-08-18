#ifndef Guard_Vec_h
#define Guard_Vec_h

template<class T>
class Vec final {
    public: 

        typedef T* iterator; 
        typedef const T* const_iterator; 
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;
        typedef size_t size_type;

        Vec() { create(); }; 
        Vec(int n) { create(n); };
        Vec(int n, T t) { create(n, t); };
        Vec(iterator a, iterator b) { create(a, b); };
        ~Vec(); 

        size_type size() const { return avail - data; };

        iterator begin() { return data; };
        const_iterator begin() const { return data; };
        iterator end() { return avail; };
        const_iterator end() const { return avail; };

        T& operator[](int i) {return *(iter+i); };
        const T& operator[](int i) {return *(iter+i); };

        void push_back(const T& t) {
            if(limit == avail)
                grow();
            unchecked_append(t);
        }

    private:
        iterator data;
        iterator avail;
        iterator limit;

        allocator<T> alloc; 

        create();
        create(int);
        create(int , const T& );
        create(iterator, iterator);
        uncreate(iterator);

        void grow(); 
        void unchecked_append(const T&);
}

/*  
Template<class T> class allocator {
public: 
    T* allocate(size_t); 
    void deallocate(T*, size_t); 
    void destroy(T*);
    void construct(T*, const T&);
}

template<class In, class for>
For uninitialized_copy(In, In, For);

template<class For, class T>
For uninitialized_fill(For, For, const T&);

*/

template<class T> 
void Vec<T>::create(){
    data = avail = limit = nullptr;
}

template<class T> 
void Vec<T>::create(std::size_t n){
    data = avail = alloc.allocate(n);
    limit = data + n;
}

template<class T> 
void Vec<T>::create(std::size_t n, const T& t){
    data = alloc.allocate(n);
    uninitialized_fill(data, data + n, t);
    avail = limit = data + n;
}

template<class T> 
void Vec<T>::create(iterator a, iterator b){
    data = alloc.allocate(b - a);
    uninitialized_copy(a, b, data);
    avail = limit = data + b-a;
}

template<class T> 
void Vec<T>::uncreate() {
    while(data != avail) {
        alloc.destroy(--avail);
    } 
    alloc.deallocate(data, limit - data);

    data = avail = limit = nullptr; 
}

// TODO: better to use swap to be exception safe
template<class T>
void Vec<T>::grow() {
    std::size_t new_sz = (limit - data) * 2; 

    auto new_ptr = alloc.allocate(new_sz); 
    uninitialized_copy(data, avail, new_ptr);
    
    std::size_t old_sz = size();
    uncreate(); 

    data = new_prt; 
    avail = data + old_sz; 
    limit = data + new_sz;
}

template<class T>
void Vec<T>::unchecked_append(const T& t) {
    alloc.construct(avail++, t);
}

#endif
