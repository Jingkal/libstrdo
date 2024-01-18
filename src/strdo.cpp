#include "strdo.hpp"
#include "iconv.h"
#include <memory>

namespace strdo {

std::vector<std::string> split(std::string_view srcview, std::string delim) {
  std::vector<std::string> ret;
  auto pos = size_t(0);
  while (srcview.size() > 0) {
    pos = srcview.find(delim);
    auto rv = strip(srcview.substr(0, pos));
    if (!rv.empty())
      ret.push_back(std::string(rv));
    if (pos == std::string::npos)
      break;
    srcview.remove_prefix(pos + delim.size());
  }
  return ret;
}

std::string conv_encoding(const std::string &orig, std::string_view from_enc,
                          std::string_view to_enc) {
  size_t ibufleft = orig.size() + 1;
  size_t obufleft = orig.size() * 2;
  size_t bufsize = obufleft;

  auto ibuf = std::make_unique<char[]>(ibufleft);
  auto obuf = std::make_unique<char[]>(bufsize);

  std::strncpy(ibuf.get(), orig.c_str(), ibufleft);

  auto conv = iconv_open(to_enc.data(), from_enc.data());
  if (conv == (iconv_t)-1) {
    perror("iconv_open");
    exit(1);
  }

  auto pibuf = ibuf.get();
  auto pobuf = obuf.get();
  if (iconv(conv, &pibuf, &ibufleft, &pobuf, &obufleft) == (size_t)(-1)) {
    perror("iconv");
    exit(1);
  }
  iconv_close(conv);

  obuf[bufsize - obufleft] = 0;
  return std::string(obuf.get());
}

} // namespace strdo
