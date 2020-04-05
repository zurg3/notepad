#include <QtGlobal>

#if WIN32
  constexpr auto font_family = "Lucida Console";
#else
  constexpr auto font_family = "DejaVu Sans Mono Book";
#endif
const int font_size = 12;
const int tab_size = 2;
const int zoom_range = 2;
