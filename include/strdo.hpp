#ifndef LIB_STRDO_HH
#define LIB_STRDO_HH

#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <cstring>

namespace strdo {

/*
 * Remove space characters from beginning of a string. VIEW ONLY.
 */
inline std::string_view strip_left(std::string_view sv) {
  auto pos = std::find_if(sv.begin(), sv.end(),
                          [](char c) { return !std::isspace(c); });
  sv.remove_prefix(pos - sv.begin());
  return sv;
}

/*
 * Remove space characters from end of a string. VIEW ONLY.
 */
inline std::string_view strip_right(std::string_view sv) {
  auto pos = std::find_if(sv.rbegin(), sv.rend(),
                          [](char c) { return !std::isspace(c); });
  sv.remove_suffix(sv.end() - pos.base());
  return sv;
}

/*
 * A new string without the beginning space characters
 */
inline std::string strip_left_new(std::string_view sv) {
  sv = strip_left(sv);
  return std::string(sv);
}

/*
 * A new string without the trailing space characters
 */
inline std::string strip_right_new(std::string_view sv) {
  sv = strip_right(sv);
  return std::string(sv);
}

/*
 * A new string without space characters at the head or tail.
 */
inline std::string strip(std::string_view sv) {
  sv = strip_right(strip_left(sv));
  return std::string(sv);
}

/*
 * split string by delim into a vector of string.
 */
std::vector<std::string> split(std::string_view srcview, std::string delim);

/*
 * convert string encoding from *from_enc* to *to_enc*
 * returns a new string with *to_enc* encoding.
 */
std::string conv_encoding(const std::string &orig, std::string_view from_enc,
                          std::string_view to_enc);

/*
 * convert string encoding from *from_enc* to *UTF-8*
 * returns a new string with *UTF-8* encoding.
 */
inline std::string conv_to_utf8(const std::string &orig,
                                std::string_view from_enc) {
  return conv_encoding(orig, from_enc, "UTF-8");
}


/*
 * Inspect every bytes(in hex) in the string.
 */
void inspect_string_bytes(std::string_view sv, size_t nbytes = 0);


/*
 * strlen for UTF-8 string. Counting characters instead of bytes.
 */
size_t u8strlen(std::string_view sv);

} // namespace strdo

#endif
