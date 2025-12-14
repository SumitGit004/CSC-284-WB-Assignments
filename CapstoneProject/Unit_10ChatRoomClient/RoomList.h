#pragma once
#include "Window.h"
#include <vector>
#include <string>

/*
 * A class that displays a vertical menu
 */
class RoomList{
    private:
    Window window;
    std::vector<std::string> rooms;
    int selected; 
    public:

    RoomList(int height, int width, int position_y, int position_x, std::vector<std::string>& rooms);

    void displayRoom();

    void handleInputKey(int key);

    const std::vector<std::string>&  getRooms() const;

    WINDOW* getWindow();
};