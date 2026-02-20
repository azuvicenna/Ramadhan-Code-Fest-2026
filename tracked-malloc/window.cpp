#include <iostream>

struct Window {
	char * title; int width, height; const char * defaultTitle = "Wildan Rhomat Wijanarko";

	Window() : title{(char *)defaultTitle}, width{0}, height{0} {
		std::cout << "Window title  : " << title << std::endl;
		std::cout << "Window height : " << height << std::endl;
	}

	Window(const char * title, int width, int height) : title{(char *)title}, width{0}, height{0} {

		std::cout << "Window title : " << title << std::endl;
		std::cout << "Window width : " << width << std::endl;

	}

};


Window * CreateWindow(const char * title, int width, int height) {
	return new Window(title, width, height);
}

int main() {
	Window * window;
	window = CreateWindow("Wildan Rhomad Wijanarko", 200, 300);

}
