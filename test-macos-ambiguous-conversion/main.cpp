#include <cstdint>
#include <vector>

struct Foo
{
  operator int() const
  {
    return 0;
  }
  operator uint32_t() const
  {
    return 0;
  }
  operator uint64_t() const
  {
    return 0;
  }
  operator unsigned long() const
  {
    return 0;
  }
};

int main()
{
  size_t s = Foo{};
  static_assert(std::is_same_v<uint64_t, unsigned long>, "OK");
  static_assert(std::is_same_v<unsigned long, size_t>, "OK");
  return s;
}
