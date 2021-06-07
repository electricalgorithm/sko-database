#ifndef SKO_DATABASE__BOOK_H_
#define SKO_DATABASE__BOOK_H_

#include "writtenmedia.h"
#include <string>
#include <cinttypes>

class book : public writtenmedia {
 public:
  std::string type = "Book";
  std::string get_location();
  void set_location(const std::string& pLoc);
  uint32_t get_user() const;
  void send_to(uint32_t id, const std::string& new_address);
  uint32_t get_id() const;
  void set(uint32_t bID, uint32_t uID);
 private:
  uint32_t book_id;
  uint32_t user_id;
  std::string location;
};

#endif //SKO_DATABASE__BOOK_H_
