#include "UI.h"
#include "Tests.h"
int main() {
	Tests test;
	test.runTests();
	char airplane[100],bus[100], write[100];
	strcpy_s(airplane,sizeof("airplane.txt"), "airplane.txt");
	strcpy_s(bus, sizeof("bus.txt"), "bus.txt");
	strcpy_s(write, sizeof("test.txt"), "test.txt");
	FileRepository repo{ airplane, bus, write };
	LogInService logInService{ "users.txt" };
	Service service{ repo };
	UI ui{ service, logInService };
	ui.show_menu_1();
	return 0;
}