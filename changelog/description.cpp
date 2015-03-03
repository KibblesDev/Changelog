#include "description.h"

/*
	Template Index Reference
	0 - changed
	1 - reduced
	2 - increased	
*/

enum ChangeType { CHANGED, REDUCED, INCREASED };

Description::Description(std::string current_data, std::string new_data, std::string description) {
	custom_description = description;
	this->index = -1;
	this->current_data = current_data;
	this->new_data = new_data;
	InitTemplate();
};


Description::Description(std::string current_data, std::string new_data, ChangeType type) {
	this->index = type;
	this->current_data = current_data;
	this->new_data = new_data;
	InitTemplate();

};

std::string Description::to_string() {
	if (custom_description != "")
		return custom_description;
	return templates[index];
};

void Description::InitTemplate() {
	std::string templates[3] = {
		"from " + current_data + " to " + new_data + ".",
		"down from  " + current_data + " to " + new_data + ".",
		"up from " + current_data + " to " + new_data + ".",
	};
}