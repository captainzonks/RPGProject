#ifndef LOCATION_H
#define LOCATION_H
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "constants.h"
#include "entity.h"

class location {
 public:
  explicit location(std::string name, coordinates coordinates)
	  : name_(std::move(name)), coordinates_(coordinates) {
  }

  ~location() { std::cout << "location destructor called" << std::endl; }

  void update();

  // void add_owners(entity &owner);
  // void add_visitors(entity &visitor);

  // void remove_owners(entity &not_owner);
  // void remove_visitors(entity &not_visitor);

  [[nodiscard]] std::string get_name() const { return name_; }
  [[nodiscard]] coordinates get_coordinates() const { return coordinates_; }

  // [[nodiscard]] std::vector<entity> get_owners() const { return owners_; }
  // [[nodiscard]] std::vector<entity> get_visitors() const { return visitors_; }

 private:
  std::string name_{};
  coordinates coordinates_;

  // std::vector<entity> owners_{};
  // std::vector<entity> visitors_{};
};

#endif