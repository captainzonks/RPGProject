#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <string>

#include "game_state.h"

class menu_state final : public game_state {
 public:
  void init() override;
  void cleanup() override;

  void pause() override;
  void resume() override;

  void handle_events(game *game) override;
  void update(game *game) override;
  void render(game *game) override;

  static menu_state *instance() { return &menu_state_; }

 protected:
  menu_state() = default;

 private:
  static menu_state menu_state_;

  unsigned choice_{};

  std::vector<std::string> options_{"Player Info", "Fantasy Shop",
									"NPC Debug Menu", "Map Debug Menu",
									"Exit game"};
  const std::string name_{"Main Menu"};
};

#endif
