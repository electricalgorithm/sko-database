#ifndef SKO_DATABASE__BOOKBASE_H_
#define SKO_DATABASE__BOOKBASE_H_

#include <string>
#include <cinttypes>
#include <vector>
#include "book.h"
#include "user.h"

class bookbase {
 public:
  std::string title;
  bookbase();
  explicit bookbase(const std::string& pName);
  void insert_csv(const std::string& pFileName);
  void export_csv(const std::string& pFileName);
  uint32_t get_book_count() const;
  std::vector <std::string> get_names();
  std::vector <std::string> get_locations();
  void insert(book Book, user User);
  std::vector <book> select(const std::string& pName);
  std::vector <book> select(std::string pName, std::string pField);
  std::vector <book> select(std::string pName, std::string pField, uint32_t pPage);
 private:
  // Allocating vectors in heap, so that we can return its address.
  std::vector <book>* object_list = new std::vector <book>;
  std::vector <std::string>* field_list = new std::vector <std::string>;
  uint32_t book_count;
};

#endif //SKO_DATABASE__BOOKBASE_H_
