#include "RoomList.h"

RoomList::RoomList(int height, int width, int position_y, int position_x, std::vector<std::string>& roomList)
     :window(height,width,position_y,position_x),rooms(roomList), selected(0){

    this->window.setColor(COLOR_BLACK, COLOR_BLUE);
    this->window.setBorder(0,0,0,0,0,0,0,0);
    
    keypad(window.getWindow(), TRUE);
    displayRoom();
}

const std::vector<std::string>& RoomList::getRooms() const{
    return rooms;
}



void RoomList::displayRoom(){
   
    WINDOW* win_ptr = window.getWindow();

    werase(win_ptr);        
    window.setBorder(0,0,0,0,0,0,0,0);
    
     for(int i = 0; i < rooms.size(); i++) {
            
            if(i == selected){
                wattron(win_ptr, A_STANDOUT);
                window.print(i + 2, 2, rooms[i]);
                wattroff(win_ptr, A_STANDOUT);
            }
            else 
            window.print(i + 2, 2, rooms[i]);
        }
   
}
//update selected room based on the user input (arrow up or down)
void RoomList::handleInputKey(int key)
{
    if (key == KEY_UP){
      selected = (selected == 0 ? rooms.size() - 1 : selected - 1);
    }
    else if (key == KEY_DOWN){
        selected = (selected == rooms.size() - 1 ? 0 : selected + 1);
    }
}
