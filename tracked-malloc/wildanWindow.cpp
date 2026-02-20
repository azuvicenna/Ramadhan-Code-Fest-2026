#include <iostream>
using namespace std;

struct Window; // Forward declaration of Window class
Window* CreateWindow(const char* title, int width, int height); // Create a new window
void DestroyWindow(Window* window); // Destroy the window

int main() {
    Window* window; // ✅ Allowed (Pointer)
    // Window window; // ❌ ERROR: 'Window' is an incomplete type
    
    window = CreateWindow("Basic Window", 200, 300);        
    
    // Don't forget to destroy the window
    DestroyWindow(window);

    return 0;
}

struct Window {
    
    int width, height;
    char* title;
    
    const char* defaulTitle = "Window";
    
    Window() : title{(char*)defaulTitle}, width{0}, height{0} {
        cout << "Window title: "  << title  << endl;
        cout << "Window width: "  << width  << endl;
        cout << "Window height: " << height << endl;
    }
    
    Window(const char* title, int width, int height) : title{(char*)title}, width{0}, height{0} {
        cout << "Window title: "  << title  << endl;
        cout << "Window width: "  << width  << endl;
        cout << "Window height: " << height << endl;
    }
};

Window* CreateWindow(const char* title, int width, int height) {
    return new Window(title, width, height);
}

void DestroyWindow(Window* window) {
    delete window;
}
