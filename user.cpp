#include "user.h"
#include <string>
#include <cinttypes>

user::user(const std::string& first_name,
           const std::string& last_name,
           const uint8_t Age,
           const std::string& Location,
           const std::string& Tel) {
  full_name = first_name + " " + last_name;
  age = Age;
  location = Location;
  tel = Tel;
  user_id = 0; // It will be changed in userbase::add
}
void user::update_info(const std::string& FullName, const std::string& Tel, const std::string& Location, uint8_t Age) {
  full_name = FullName;
  age = Age;
  location = Location;
  tel = Tel;
}
std::string user::get_location() {
  return location;
}
uint32_t user::get_id() const {
  return user_id;
}
std::string user::get_fullname() {
  return full_name;
}
uint8_t user::get_age() {
  return age;
}
void user::set_id(uint32_t userID) {
  user_id = userID;
}
