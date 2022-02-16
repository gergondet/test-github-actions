#define BOOST_STACKTRACE_LINK
#include <boost/stacktrace.hpp>

#include <iostream>
#include <string>

void foo(const std::string &, double, bool)
{
  std::cout << boost::stacktrace::stacktrace() << "\n";
}

int main()
{
#ifdef BOOST_STACKTRACE_USE_BASIC
  std::cout << "Use BOOST_STACKTRACE_USE_BASIC\n";
#endif
#ifdef BOOST_STACKTRACE_USE_ADDR2LINE
  std::cout << "Use BOOST_STACKTRACE_USE_ADDR2LINE\n";
#endif
#ifdef BOOST_STACKTRACE_USE_BACKTRACE
  std::cout << "Use BOOST_STACKTRACE_USE_BACKTRACE\n";
#endif
  foo("hello", 42.42, true);
  return 0;
}
