#include "bookbase.h"
#include "book.h"
#include "user.h"
#include "userbase.h"
using namespace std;

int main() {
  // Creating a book database and adding some books init.
  bookbase libcon("LibCon - A Shared Library");
  libcon.insert_csv("../book-list");

  // Creating three user
  userbase Users;
  user Sedat("Sedat", "Nefsidar", 25, "Turkiye, Istanbul", "+9012345678");
  user Volkan("Volkan", "Cengaver", 19, "Turkiye, Aydın", "+9087654321");
  user Gokhan("Gokhan", "Elektrik", 21, "Poland, Warshaw", "+9086574123");
  Users.add(Sedat);
  Users.add(Volkan);
  Users.add(Gokhan);

  book Kitap1;
  Kitap1.name = "Hayatımı Nasıl Yaşadım?";
  Kitap1.field = "Felsefe";
  Kitap1.page = 128;
  Kitap1.set_location("Malkara, Tekirdag");

  book Kitap2;
  Kitap2.name = "Hayalet Beşli ve Bitmeyen Kanama";
  Kitap2.field = "Roman";
  Kitap2.page = 755;
  Kitap2.set_location("Artvin, Turkiye");

  book Kitap3;
  Kitap3.name = "Yoda ve Casper: İlk Karşılışma";
  Kitap3.field = "Fantastik";
  Kitap3.page = 43;
  Kitap3.set_location("Malkara, Tekirdag");

  libcon.insert(Kitap1, Sedat);
  libcon.insert(Kitap2, Volkan);
  libcon.insert(Kitap3, Gokhan);

  libcon.export_csv("../deneme");

  vector <book> selection_first = libcon.select("Y");
  vector <book> selection_sec = libcon.select("a", "Fantastik");
  vector <book> selection_third = libcon.select("a", "Fantastik", 43);

  Users.remove(Gokhan);
  Users.remove(Sedat.get_id());
  Users.remove("Volkan Cengaver", "Turkiye, Aydın", 19);

  return 0;
}