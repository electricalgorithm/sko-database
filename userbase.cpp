#include "userbase.h"
#include <string>
#include <vector>

void userbase::remove(const user& User) {
  remove(User.get_id());
}

void userbase::remove(uint32_t user_id) {
  for (size_t index = 0; index < user_list->size(); index++){
    // TODO: Fix Clang-Tidy Narrowing Warning!
    if (user_list->at(index).get_id() == user_id) user_list->erase(user_list->begin() + index);
  }
}

void userbase::remove(const std::string& FullName, const std::string& Location, const uint8_t Age) {
  for (size_t index = 0; index < user_list->size(); index++) {
    // If the user object in that position have a part of FullName and Location, and also
    // it's age is equals to Age; then erase it from the vector.
    if ((user_list->at(index).get_fullname().find(FullName) != std::string::npos)
    && (user_list->at(index).get_location().find(Location) != std::string::npos)
    && (user_list->at(index).get_age() == Age)) {
      // TODO: Fix Clang-Tidy Narrowing Warning!
      user_list->erase(user_list->begin() + index);
    }
  }
}

user* userbase::get_user(uint32_t user_id) {
  for (auto& iter : *user_list) {
    if (iter.get_id() == user_id) return &iter;
  }

  return nullptr;
}

void userbase::change_user(const user& changed_user) {
  for (size_t index = 0; index < user_list->size(); index++){
    // Find the position of the same user object with the same ID.
    if (user_list->at(index).get_id() == changed_user.get_id()) {
      // Erase old user object.
      user_list->erase(user_list->begin() + index - 1);
      // Insert new user object to the end.
      user_list->push_back(changed_user);
    }
  }
}

void userbase::add(user& User) {
  User.set_id(user_list->size());
  user_list->push_back(User);
  location_list->push_back(User.get_location());
}
