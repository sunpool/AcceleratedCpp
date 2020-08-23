#ifndef Guard_Handle_h
#define Guard_Handle_h

template<class T>
class Handle
{
public:
    Handle(): pt(0), refpt(new std::size_t(1)) {}
 /* why this object can access the passed in obj private varible ???
 *
 * C++ access control works on per-class basis, not on per-object basis.
 * C++ is big on compile-time mechanisms, not so big on run-time mechanisms.
 * Access control is static, compile time feature, and only per-class control
 * can be reasonbly done at complie time. 
 *  */
    Handle(const Handle& h): pt(h.pt), refpt(h.refpt) {++*refpt;}
    // from raw to handler, cannot be const T, b/c later Handler needs to
    // delete this passed-in object.
    Handle(T* p): pt(p), refpt(new std::size_t(1)) {}
    ~Handle();

    Handle& operator=(const Handle& );
    // if fns not declared as const, handle pointer cannot be used in 
    //      handlePtr ? (exp1) : (exp2); 
    operator bool() const { return pt; }
    static bool compare(const Handle& a, const Handle& b) {
        return T::compare( *a.pt, *b.pt );
    }

    // only const version as this sample project does not require RW to objects
    inline T& operator*() const { return pt ? *pt : throw std::runtime_error("unbounded Handle"); }
    inline T* operator->() const { return pt ? pt : throw std::runtime_error("unbounded Handle"); }

    void make_unique(){
        if(*refpt != 1){
            --*refpt;
            refpt = new std::size_t(1); 
            pt = pt ? pt->clone() : 0;
        } 
    }


private:
    T* pt;
    std::size_t *refpt;
};

template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    // note: .efpt is not changed as required by const parameter, but what it refers to is changed.
    ++*rhs.refpt; 
    if (--*refpt == 0)
    {
        delete pt;
        delete refpt;
    }
    pt = rhs.pt;
    refpt = rhs.refpt;
    return *this;
}

template<class T> 
Handle<T>::~Handle(){
    if(--*refpt == 0){
        delete pt; 
        delete refpt;
    }
}

#endif
