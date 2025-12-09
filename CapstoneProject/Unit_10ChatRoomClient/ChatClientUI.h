#pragma once

#include "Window.h"
#include "MessageArea.h"
#include "RoomList.h"
#include "InputArea.h"
#include "TitleBar.h"
#include <memory>

/*
 * A UI class that handles all the UI components of the consoled based application
 */
class ChatClientUI{
    
    private:
    Window parentWindow;
    std::unique_ptr<TitleBar> titleBar;
    std::unique_ptr<MessageArea> messageArea;
    std::unique_ptr<RoomList> roomList;
    std::unique_ptr<InputArea> inputArea;

    int topPadding = 0;
    int bottomPadding = 0;
    int leftPadding = 2;
    int rightPadding = 2;
    int vLinePadding = 1;
    int roomWidth = 25;
    

    std::vector<std::string> rooms = {"General", "Sports", "Programming", "Music", "Random"};


    public:
    
    ChatClientUI();

    void run();
};