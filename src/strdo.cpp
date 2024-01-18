#include "strdo.hpp"
#include "iconv.h"
#include <cstdio>
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

/*
 * Converting String from a encoding to another.
 *
 * How it works:
 * > `libconv` uses `conv(cd, **inbuf, *inbufByteLeft, **outbuf, *outbufLeft)`
 * > it reads multibytes character by `(*inbuf)++` and `(*inbufByteLeft)--`
 * > it writes multibytes character by `(*outbuf)++` and `(*outbufByteLeft)--`
 *
 * Therefore after a successful conversion, `outbufLeft` will mark the
 * terminator byte in the converted string.
 */
std::string conv_encoding(const std::string &orig, std::string_view from_enc,
                          std::string_view to_enc) {
  size_t inBufBytesLeft = orig.size() + 1;
  size_t outBufBytesLeft =
      orig.size() * 4; // utf-8 character can take up 4 bytes.
  size_t outBufSize = outBufBytesLeft;

  auto inBuf = std::make_unique<char[]>(inBufBytesLeft);
  auto outBuf = std::make_unique<char[]>(outBufSize);

  std::strncpy(inBuf.get(), orig.c_str(), inBufBytesLeft);

  auto conv = iconv_open(to_enc.data(), from_enc.data());
  if (conv == (iconv_t)-1) {
    perror("iconv_open");
    exit(1);
  }

  auto pibuf = inBuf.get();
  auto pobuf = outBuf.get();
  if (iconv(conv, &pibuf, &inBufBytesLeft, &pobuf, &outBufBytesLeft) ==
      (size_t)(-1)) {
    perror("iconv");
    exit(1);
  }
  iconv_close(conv);

  outBuf[outBufSize - outBufBytesLeft] = 0;
  return std::string(outBuf.get());
}

void inspect_string_bytes(std::string_view sv, size_t nbytes) {
  if (nbytes == 0 || nbytes > sv.size())
    nbytes = sv.size();

  for (size_t i = 0; i < nbytes; i++) {
    printf("%#x ", sv[i]);
  }
  printf("\n");
}

size_t u8strlen(std::string_view sv) {
  size_t istr = 0;
  size_t count = 0;
  while (istr < sv.size()) {
    if ((sv[istr] & 0b11110000) == 0b11110000) {
      istr += 4;
    } else if ((sv[istr] & 0b11100000) == 0b11100000) {
      istr += 3;
    } else if ((sv[istr] & 0b11000000) == 0b11000000) {
      istr += 2;
    } else {
      istr += 1;
    }
    count += 1;
  }
  return count;
}

} // namespace strdo
