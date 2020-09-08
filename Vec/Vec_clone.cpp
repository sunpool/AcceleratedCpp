#include "Vec.h"

template <typename T> T* clone(const T*);

#ifndef Guard_Vec_clone
#define Guard_Vec_clone

template<>
Vec<char>* clone(const Vec<char>* vec) {
    return new Vec<char>(*vec);
}

#endif
