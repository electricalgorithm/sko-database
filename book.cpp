#include "book.h"
#include <string>
#include <iostream>

void book::send_to(uint32_t id, const std::string& new_address) {
 std::cout << "Book is sending to User #" << id << " and location " << new_address << std::endl;
 user_id = id;
 location = new_address;
}
std::string book::get_location() {
  return location;
}
uint32_t book::get_user() const {
  return user_id;
}
uint32_t book::get_id() const {
  return book_id;
}
void book::set_location(const std::string& pLoc) {
  location = pLoc;
}
void book::set(uint32_t bID, uint32_t uID) {
  book_id = bID;
  user_id = uID;
}
