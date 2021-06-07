#ifndef SKO_DATABASE__USER_H_
#define SKO_DATABASE__USER_H_

#include <string>
#include <cinttypes>

class user {
 public:
  user(const std::string& first_name,
       const std::string& last_name,
       uint8_t age,
       const std::string& location,
       const std::string& tel);

  // Methods
  void update_info(const std::string& full_name, const std::string& tel, const std::string& location, uint8_t age);
  std::string get_location();
  uint32_t get_id() const;
  std::string get_fullname();
  uint8_t get_age();
  void set_id(uint32_t userID);
 private:
  uint32_t user_id;
  std::string full_name;
  std::string tel;
  std::string location;
  uint8_t age;
};

#endif //SKO_DATABASE__USER_H_
