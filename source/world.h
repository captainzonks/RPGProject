#ifndef WORLD_H
#define WORLD_H

#include <vector>

class location;

class world {
 public:
  ~world();

  void add_location(location *new_location);
  void print_locations();

  [[nodiscard]] std::vector<location *> get_world_map() { return world_map_; }

 private:
  std::vector<location *> world_map_{};
};

#endif