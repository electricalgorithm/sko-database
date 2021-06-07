#include "bookbase.h"
#include <cinttypes>
#include <iostream>
#include "book.h"
#include "user.h"

bookbase::bookbase() {
  book_count = 0;
  title = "Non-titled";
}

bookbase::bookbase(const std::string& pName) {
  book_count = 0;
  title = pName;
}

void bookbase::insert_csv(const std::string& pFileName) {
  // Choosing file name
  std::string file_name = pFileName + ".csv";
  char* file_name_c = const_cast<char *>(file_name.c_str());
  // Opening file
  FILE* CSV = fopen(file_name_c, "r");
  if (CSV == nullptr) {
    perror("File opening error.");
    return;
  }

  // Object creation from lines
  char line[1000];
  size_t pos;
  while (fgets(line, 1000, CSV)) {
    std::string s = line;

    pos = s.find(", "); // To find ", "
    if (pos > s.length()) break;

    book Data;
    Data.name = s.substr(0, pos);
    s = s.substr(pos+1, s.length()-1);

    pos = s.find(", ");
    if (pos > s.length()) break;
    Data.page = std::stoi(s.substr(0, pos));
    s = s.substr(pos+1, s.length()-1);

    pos = s.find(", ");
    if (pos > s.length()) break;
    Data.field = s.substr(0, pos);
    s = s.substr(pos+1, s.length()-1);

    pos = s.find(", ");
    if (pos > s.length()) break;
    Data.set_location(s.substr(0, pos));
    s = s.substr(pos+1, s.length()-1);

    Data.set(object_list->size(), std::stoi(s.substr(0, s.size()-1)));

    // Inserting the object
    object_list->push_back(Data);
  }

  // Closing file
  fclose(CSV);
}

void bookbase::export_csv(const std::string& pFileName) {
  // Choosing file name
  std::string file_name = pFileName + ".csv";
  char* file_name_c = const_cast<char *>(file_name.c_str());
  // Opening file
  FILE* CSV = fopen(file_name_c, "w+");
  if (CSV == nullptr) {
    perror("File opening error.");
    return;
  }

  // Writing books to the file
  for (auto& iter : *object_list) {
    std::string data = iter.name + ", " + std::to_string(iter.page) + ", " + iter.field + ", " + iter.get_location() + ", "
        + std::to_string(iter.get_user());
    auto* data_c = data.c_str();
    fputs(data_c, CSV);
    fputs("\n", CSV);
  }

  // Closing the file
  fclose(CSV);
}

uint32_t bookbase::get_book_count() const {
  return book_count;
}

std::vector <book> bookbase::select(const std::string& pName) {
  std::vector <book> returned;
  for (auto& iter : *object_list) if (iter.name.find(pName) < iter.name.length()) returned.push_back(iter);
  return returned;
}

std::vector <book> bookbase::select(const std::string pName, const std::string pField) {
  std::vector <book> returned;
  for (auto& iter : *object_list)
    if ((iter.name.find(pName) < iter.name.length())
    && (iter.field.find(pField) < iter.field.length()))
      returned.push_back(iter);
  return returned;
}

std::vector<book> bookbase::select(const std::string pName, const std::string pField, uint32_t pPage) {
  std::vector <book> returned;
  for (auto& iter : *object_list)
    if ((iter.name.find(pName) < iter.name.length())
    && (iter.field.find(pField) < iter.field.length())
    && (iter.page == pPage))
      returned.push_back(iter);
  return returned;
}

std::vector<std::string> bookbase::get_names() {
  std::vector <std::string> only_names;
  for (auto& iter : *object_list) only_names.push_back(iter.name);
  return only_names;
}

std::vector<std::string> bookbase::get_locations() {
  std::vector <std::string> locations;
  for (auto& iter : *object_list) locations.push_back(iter.get_location());
  return locations;
}
void bookbase::insert(book Book, user User) {
  Book.set(++book_count, User.get_id());
  object_list->push_back(Book);
}
