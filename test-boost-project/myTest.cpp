// boost
#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

namespace bfs = boost::filesystem;

BOOST_AUTO_TEST_CASE(MyTest)
{
  bfs::path path("/NOT/EVEN");
  BOOST_REQUIRE(!bfs::exists(path));
}

