#include "game.h"

#include <ctime>
#include <iostream>

#include "character_builder.h"
#include "constants.h"
#include "entity.h"
#include "entity_manager.h"
#include "game_state.h"
#include "menu_state.h"

void game::init()
{
  srand(static_cast<unsigned>(time(nullptr))); // seed the dice rolls
  running_ = true;
}

void game::cleanup()
{
  // cleanup all the states_
  while (!states_.empty())
  {
    states_.back()->cleanup();
    states_.pop_back();
  }
}

void game::change_state(game_state *state)
{
  // cleanup the current state
  if (!states_.empty())
  {
    states_.back()->cleanup();
    states_.pop_back();
  }

  // store and init the new state
  states_.push_back(state);
  states_.back()->init();
}

void game::push_state(game_state *state)
{
  // pause current state
  if (!states_.empty())
  {
    states_.back()->pause();
  }

  // store and init the new state
  states_.push_back(state);
  states_.back()->init();
}

void game::pop_state()
{
  // cleanup the current state
  if (!states_.empty())
  {
    states_.back()->cleanup();
    states_.pop_back();
  }

  // resume previous state
  if (!states_.empty())
  {
    states_.back()->resume();
  }
}

void game::handle_events()
{
  // let the state handle events
  if (!is_running())
    return;
  states_.back()->handle_events(this);
}

void game::update()
{
  // entity_manager::instance()->update(this);
  if (!is_running())
    return;
  states_.back()->update(this);
}

void game::render()
{
  // if (entity_manager::instance()->has_no_entities())
  //   return;

  // entity_manager::instance()->render(this);
  if (!is_running())
    return;
  states_.back()->render(this);
}