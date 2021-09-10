/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:41
 * @LastEditTime: 2021-09-10 16:56:33
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /go/template/swig/example.h
 */
/* File : example.h */

// Some template definitions

template <class T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <class T>
class vector {
    T* v;
    int sz;

   public:
    vector(int _sz) {
        v = new T[_sz];
        sz = _sz;
    }
    T& get(int index) { return v[index]; }
    void set(int index, T& val) { v[index] = val; }
#ifdef SWIG
  %extend {
    T getitem(int index) {
      return $self->get(index);
    }
    void setitem(int index, T val) {
      $self->set(index,val);
    }
  }
#endif
};
