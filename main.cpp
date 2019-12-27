#include <iostream>
#include <qwt/qwt_global.h>
#include <qwt/qwt_color_map.h>

int main()
{
  std::cout << QWT_VERSION_STR << "\n";
  QwtLinearColorMap map;
  return 0;
}
