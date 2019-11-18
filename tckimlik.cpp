#include "tckimlik.h"

#define CA_CERT_FILE "./ca-bundle.crt"
TCKimlik::TCKimlik(string tcno, string adi, string soyadi, string dogumyili) {
  this->tcno = tcno;
  this->adi = adi;
  this->soyadi = soyadi;
  this->dogumyili = dogumyili;
  this->istek_hazirla();
}


TCKimlik::TCKimlik(unsigned long tcno, string adi, string soyadi, unsigned int  dogumyili) {
  this->tcno = to_string(tcno);
  this->adi = adi;
  this->soyadi = soyadi;
  this->dogumyili = to_string(dogumyili);
  this->istek_hazirla();
}

void TCKimlik::istek_hazirla() {
  this->istek = "<?xml version=\"1.0\" encoding=\"utf-8\"?> \n  <soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"  xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"   xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\">\n   <soap:Body>\n    <TCKimlikNoDogrula xmlns=\"http://tckimlik.nvi.gov.tr/WS\">\n      <TCKimlikNo>" + this->tcno + "</TCKimlikNo>\n      <Ad>" + this->adi + "</Ad>\n      <Soyad>"+this->soyadi + "</Soyad>\n      <DogumYili>"+ this->dogumyili +"</DogumYili>\n    </TCKimlikNoDogrula>\n  </soap:Body>\n</soap:Envelope>"; 
}

bool TCKimlik::dogrula() {
  httplib::Headers headers = {
    { "SOAPAction", "http://tckimlik.nvi.gov.tr/WS/TCKimlikNoDogrula"},
    { "Content-Length", to_string(this->istek.size())},
    { "Content-Type", "text/xml; charset=utf-8"}
  };

  httplib::SSLClient cli("tckimlik.nvi.gov.tr", 443);
  cli.set_ca_cert_path(CA_CERT_FILE);
  cli.enable_server_certificate_verification(true);
  
  auto res = cli.Post("/Service/KPSPublic.asmx", headers, this->istek, "text/xml; charset=utf-8");
  cout << res->body << endl;
  //TODO: sonuc xml metnini parse edip true/false degiskenini bul.

  return true;
}
