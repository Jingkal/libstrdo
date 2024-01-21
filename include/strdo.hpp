#ifndef LIB_STRDO_HH
#define LIB_STRDO_HH

#include <algorithm>
#include <cstring>
#include <string>
#include <string_view>
#include <vector>

namespace strdo {

/*
 * Trim spaces on the left of a string.
 */
inline std::string trim_left(const std::string &src) {
  auto b_it = std::find_if(src.cbegin(), src.cend(),
                           [](const char &c) { return !isspace(c); });
  return src.substr(b_it - src.cbegin(), src.cend() - b_it);
}

/*
 * Trim spaces on the right of a string.
 */
inline std::string trim_right(const std::string &src) {
  auto b_it = std::find_if(src.crbegin(), src.crend(),
                           [](const char &c) { return !isspace(c); });
  return src.substr(0, b_it.base() - src.cbegin());
}

/*
 * Trim spaces on the both ends of a string.
 */
inline std::string trim(const std::string &src) {
  return trim_right(trim_left(src));
}

/*
 * split string by delim into a vector of string.
 */
std::vector<std::string> split(const std::string src, const std::string &delim = " \t");

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
