#include <iostream>
#include <fstream>
#include <string>
#include "json.hh"


using json = nlohmann::json;

int print_table(){
  std::ifstream file("table.txt");

  if(!file){
    std::cerr<<"failed to load file\n";
    return 1;
  }

  while(file){
    std::string str;
    std::getline(file, str);
    std::cout<<"\n"<<str;
  }
  return 0;
}

void title(std::string& input){
  for(char& elem: input){
    if(std::isalpha(elem)){
      elem = std::toupper(elem);
      break;
    }
  }
}

int print_elements(){
  std::ifstream elements("elements.json");
  std::cout<<"Enter the element you wantt to search for and get info about...\n";
  json data;
  std::string a;
  std::getline(std::cin, a);
  elements>>data;
  title(a);
  for (auto& each:data["elements"]){
    if (static_cast<std::string>(each["name"]) == a){
      std::cout<<(std::string)(each["summary"])<<"\n";
      if(each["appearance"].is_null()){
        std::cout<<"Appearance: "<<each["appearance"]<<"No info given\n";
      }
      else{
        std::cout<<"Appearance: "<<(std::string)(each["appearance"])<<"\n";
      }
      std::cout<<"For more information: "<<(std::string)(each["source"])<<"\n";
    }
  }
  return 0;
}


int main(){
  std::cout<<"Welcome to the periodic table\n";
  print_table();
  print_elements();
  return 0;
}
