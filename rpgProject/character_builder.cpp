//#include "character_builder.h"
//
//#include <memory>
//
//#include "entity.h"
//#include "attributes_component.h"
//#include "job_component.h"
//#include "currency_component.h"
//#include "helper_functions.h"
//#include "name_list.h"
//#include "transform_component.h"
//#include "inventory_component.h"
//
//character_builder character_builder::character_builder_instance_;
//
//void character_builder::ask_for_race_and_name() const
//{
//	std::cout << "\nWhat race are you?" << std::endl;
//	const std::vector<std::string> race_options{ "Human", "Dwarf", "Elf", "Halfling" };
//	print_menu("Races", race_options);
//	auto race_choice { menu_choice(race_options) };
//
//	std::cout << "\nWhat's your name?" << std::endl;
//	std::string name;
//	std::cin >> name;
//	
//	build_attributes(name, "Player", static_cast<::race_options>(race_choice));
//}
//
//void character_builder::build_attributes(const std::string& name, const std::string& label, const race_options race) const
//{
//	//auto strength {roll_dice_ignore_lowest(4, 6)};
//	//auto dexterity {roll_dice_ignore_lowest(4, 6)};
//	//auto constitution {roll_dice_ignore_lowest(4, 6)};
//	//auto intelligence {roll_dice_ignore_lowest(4, 6)};
//	//auto wisdom {roll_dice_ignore_lowest(4, 6)};
//	//auto charisma {roll_dice_ignore_lowest(4, 6)};
//	//
//	//if(race == race_options::human)
//	//{
//	//	strength++;
//	//	dexterity++;
//	//	constitution++;
//	//	intelligence++;
//	//	wisdom++;
//	//	charisma++;
//	//}
//	//else if(race == race_options::dwarf)
//	//{
//	//	strength += 2;
//	//	constitution += 2;
//	//}
//	//else if(race == race_options::elf)
//	//{
//	//	dexterity += 2;
//	//	intelligence++;
//	//	wisdom++;
//	//	charisma++;
//	//}
//	//else // halfling
//	//{
//	//	constitution++;
//	//	charisma++;
//	//}
//	//
//	//result_->add_component<attributes_component>(label, name, layer_type::player_layer, race, strength,
//	//                                          dexterity, constitution,
//	//                                          intelligence, wisdom, charisma);
//}
//
//void character_builder::build_currency() const
//{
//	result_->add_component<currency_component>();
//}
//
//void character_builder::build_inventory() const
//{
//	result_->add_component<inventory_component>();
//}
//
//void character_builder::build_transform() const
//{
//	result_->add_component<transform_component>(0, 0, 0, 0, 16, 16, 1);
//}
//
//
//void character_builder::ask_for_job() const
//{
//	std::cout << "\nWhat is your job?" << std::endl;
//	const std::vector<std::string> job_options{ "Lumberer", "Blacksmith", "Farmer" };
//	print_menu("Jobs", job_options);
//	auto choice { menu_choice(job_options) };
//
//	build_job(static_cast<job_labels>(choice));
//}
//
//void character_builder::build_job(const job_labels choice) const
//{
//	result_->add_component<job_component>(choice);
//}
//
//std::shared_ptr<entity> character_builder::build_player()
//{
//	result_ = std::make_shared<entity>();
//	
//	ask_for_race_and_name();
//	build_currency();
//	build_inventory();
//	build_transform();
//	ask_for_job();
//	
//	return result_;
//}
//
//std::shared_ptr<entity> character_builder::build_character()
//{
//	result_ = std::make_shared<entity>();
//	
//	const auto gender = rand() % 2;
//	std::string name;
//	if (gender == 0)
//		name = name_list::male_names.at((rand() % name_list::male_names.capacity()));
//	if (gender == 1)
//		name = name_list::female_names.at((rand() % name_list::female_names.capacity()));
//
//	auto race = rand() % 4 + 1;
//	auto class_choice = rand() % 3 + 1;
//	
//	build_attributes(name, "NPC", static_cast<race_options>(race));
//	build_currency();
//	build_inventory();
//	build_transform();
//	build_job(static_cast<job_labels>(class_choice));
//
//	return result_;
//}
