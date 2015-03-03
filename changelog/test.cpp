#define _CRT_SECURE_NO_WARNINGS
#include "description.h"
#include "category.h"
#include <iostream>
#include <ctime>
#include <string>
#include <time.h>

int main() {
	Content cpu = Content("CPU");
	Content design = Content("Design");
	Content fan = Content("Fan");
	Category hardware = Category("Hardware");
	Category applecomputer = Category("Macbook Pro");

	hardware.add_subcategory(cpu);
	hardware.add_subcategory(design);
	hardware.add_subcategory(fan);
	applecomputer.add_subcategory(hardware);
	applecomputer.print();

	hardware.add_subcategory(fan);
	applecomputer.print();

	system("PAUSE");
	return 0;
}