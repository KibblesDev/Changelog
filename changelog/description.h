#ifndef DESCRIPTION_H_
#define DESCRIPTION_H_

#include <iostream>

/*
	Template Index Reference
	0 - changed
	1 - reduced
	2 - increased
*/

class Description {
private:
	std::string current_data;
	std::string new_data;
	std::string custom_description;
	std::string templates[3];
	int index;
	void InitTemplate();

public:
	enum ChangeType;
	Description::Description(std::string current_data, std::string new_data, std::string description);
	Description::Description(std::string current_data, std::string new_data, ChangeType type);
	std::string Description::to_string();
};
#endif