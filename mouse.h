#include <iostream>
namespace aerobox {
void mousefunc(int button, int state, int x, int y) {
	std::cout << button << "\t" << state << "\t" << x << "\t" << y << "\n";
}
}
