#include <QtGlobal>

#if defined(WIN32) || defined(_WIN32)
  constexpr auto font_family = "Lucida Console";
#else
  constexpr auto font_family = "DejaVu Sans Mono Book";
#endif
const int font_size = 12;
const int tab_size = 2;
const int zoom_range = 2;
const int status_bar_message_timeout = 10000; //10 seconds
constexpr auto default_file_name = "untitled.txt";
