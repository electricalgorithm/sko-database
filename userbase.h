#ifndef SKO_DATABASE__USERBASE_H_
#define SKO_DATABASE__USERBASE_H_

#include <cinttypes>
#include <string>
#include "user.h"
#include <vector>

class userbase {
 public:
  // Properties
  std::string basename;
  // Methods
  void add(user& User);
  void remove(const user& User);
  void remove(uint32_t user_id);
  void remove(const std::string& FullName, const std::string& Location, uint8_t Age);
  user* get_user(uint32_t user_id);
  void change_user(const user& changed_user);
 private:
  std::vector <user>* user_list = new std::vector <user>;
  std::vector <std::string>* location_list = new std::vector <std::string>;
};

#endif //SKO_DATABASE__USERBASE_H_
