#ifndef CUSTOM_ALLOCATOR_H
#define CUSTOM_ALLOCATOR_H

#include <iostream>
#include <memory>

template<typename T, size_t max_size>
class custom_allocator
{
  size_t max_allocator_size = 0;
  size_t count = 0;
  T *data;

public:
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;

  custom_allocator() = default;

  template <typename U>
  custom_allocator(const custom_allocator<U, max_size>& ) {
  }

  ~custom_allocator()
  {
    delete data;
  }

  template<typename U>
  struct rebind {
    using other = custom_allocator<U, max_size>;
  };

  T *allocate(std::size_t n)
  {
    if(data==nullptr) data = new T[max_size];

    if(max_allocator_size == 0)
      {
        max_allocator_size = max_size;
      }


    if(count > max_allocator_size)
      {
        throw std::bad_alloc();
      }

    return reinterpret_cast<T *>(&data[count++]);
  }

  void deallocate(T *pointer, std::size_t n)
  {}

  template<typename U, typename ...Args>
  void construct(U *p, Args &&...args)
  {
    new(p) U(std::forward<Args>(args)...);
  }

  void destroy(T *p)
  {
    p->~T();
  }

  constexpr bool operator== (const custom_allocator<T, max_size>&) noexcept {
          return false;
  }


  constexpr bool operator!= (const custom_allocator<T, max_size>) noexcept {
          return false;
  }

};

#endif // CUSTOM_ALLOCATOR_H
