#include "httplib.h"
#include <iostream>
#include "tckimlik.h"

using namespace std;

int main(void) {
  
  TCKimlik t("1234567890", "İLKER MUSTAFA","MANAP", "1982");
  cout << t.istek << endl;
  cout << t.dogrula() << endl;

  return 0;
}
