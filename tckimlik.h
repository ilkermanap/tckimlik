#include <string>
#include <iostream>
#include "httplib.h"



using namespace std;


//! TCKimlik Sinifi
/*
  TCKimlik sinifi kimlik numarasi, adi, soyadi ve dogum yili parametreleri ile olusturulur.

  TCKimlik t("12345678901", "Ahmet", "Mehmet", "1982")

  ya da 

  TCKimlik t(12345678901, "Ahmet", "Mehmet", 1982)

 */
class TCKimlik{
 public:
  string adi;
  string soyadi;
  string tcno;
  string dogumyili;
  string istek;


  //* Butun parametreler string ise 
  TCKimlik(string,string, string, string);
  //* Kimlik numarasi ve dogum yili tamsayi verilmis ise
  TCKimlik(unsigned long,string, string, unsigned int);
  
  //* SOAP istegi icin gerekli metni olusturur.
  void istek_hazirla();

  //* gerekli HTTP Post baslik bilgilerini olusturarak sunucuya gonderir
  bool dogrula();
};
