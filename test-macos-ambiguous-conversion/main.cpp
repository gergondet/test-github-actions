#include <cstdint>
#include <limits>
#include <type_traits>
#include <vector>


namespace details
{
  template<typename RefT, typename T>
  struct is_like : public std::conditional_t<std::is_integral_v<T> && std::is_unsigned_v<T> == std::is_unsigned_v<RefT> && std::numeric_limits<T>::max() == std::numeric_limits<RefT>::max(), std::true_type, std::false_type> {};

  template<typename T>
  struct is_like_int32_t : public is_like<int32_t, T>::type {};
  template<typename T>
  struct is_like_uint32_t : public is_like<uint32_t, T>::type {};
  template<typename T>
  struct is_like_int64_t : public is_like<int64_t, T>::type {};
  template<typename T>
  struct is_like_uint64_t : public is_like<uint64_t, T>::type {};
}

struct Foo
{
  template<typename T, std::enable_if_t<details::is_like_int32_t<T>::value, int> = 0>
  operator T() const
  {
    return 0;
  }
  template<typename T, std::enable_if_t<details::is_like_uint32_t<T>::value, int> = 0>
  operator T() const
  {
    return 0;
  }
  template<typename T, std::enable_if_t<details::is_like_int64_t<T>::value, int> = 0>
  operator T() const
  {
    return 0;
  }
  template<typename T, std::enable_if_t<details::is_like_uint64_t<T>::value, int> = 0>
  operator T() const
  {
    return 0;
  }
};

int main()
{
  size_t s = Foo{};
  return s;
}
