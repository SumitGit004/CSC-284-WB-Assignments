#include "ChatClientUI.h"

ChatClientUI::ChatClientUI() : parentWindow(LINES, COLS, 0,0){
   
    //dimensions for titlBar, messageArea, roomList, inputArea
    int titleWidth, titleHeight, 
        messageHeight, messageWidth, 
        roomHeight, roomWidth, 
        inputHeight, inputWidth,
    
    //Single vertical line  height,  position x and position y;
    vLineHeight, vLineY, vLineX;
    
     titleHeight = 2;
     titleWidth = COLS - 2;
     inputHeight = 3;
     
    roomWidth = (COLS - rightPadding - leftPadding - vLinePadding * 2 - 1) * 0.25;// -1 accounting for single verticle line

    messageHeight = roomHeight  = LINES - titleHeight - inputHeight - topPadding - bottomPadding;

    messageWidth = COLS - roomWidth - rightPadding - leftPadding - vLinePadding * 2 - 1; // -1 accounting for single verticle line
    
    inputWidth = messageWidth;

    vLineHeight = messageHeight + 2;

    int titleY, titleX;
    titleY = 1, titleX = 1;

    int messageY, roomY;
    messageY = roomY =  LINES - inputHeight - messageHeight + 1; //titleY + titleHeight + topPadding;

    int messageX, roomX;
    messageX = leftPadding;
    roomX = messageX + messageWidth + vLinePadding * 2 + 1;  

    int inputY, inputX;
    inputY = LINES - inputHeight;
    inputX = messageX;
    
    vLineY = messageY - 2;
    vLineX = roomX - vLinePadding * 2;
    

    parentWindow.setColor(COLOR_BLACK, COLOR_BLACK);
    
    parentWindow.setBorder(0,0,0,0,0,0,0,0);
    
    wattron(parentWindow.getWindow(), COLOR_PAIR(1));
    mvwvline(parentWindow.getWindow(), vLineY, vLineX, ACS_VLINE,  vLineHeight);
    wattroff(parentWindow.getWindow(), COLOR_PAIR(1));

    wrefresh(parentWindow.getWindow());

   
    titleBar = std::make_unique<TitleBar>(titleHeight, titleWidth, titleY, titleX, "Advanced C++ Chat Client");

    messageArea = std::make_unique<MessageArea> (messageHeight, messageWidth, messageY, messageX);

    roomList = std::make_unique<RoomList> (roomHeight, roomWidth, roomY, roomX, rooms);

    inputArea = std::make_unique<InputArea>(inputHeight,inputWidth, inputY, leftPadding);

}

void ChatClientUI::run(){

    noecho();
    cbreak();
    nodelay(stdscr, TRUE);// input functions return immediately without waiting for 
                          // input;
    keypad(stdscr, TRUE);

    int ch;
    std::string message;

    auto roomWindow = roomList.get();
    auto inputWindow = inputArea.get();

    while(true){
      ch = getch();

      if(ch == ERR){
       napms(10);//err represents no input
       continue;
      }
      else if(ch == KEY_UP || ch == KEY_DOWN)
        roomWindow->handleInputKey(ch);

      else if(ch == '\n')
        message = inputWindow->retrieveBuffer();

      else
      inputWindow->handleKey(ch);
    }
}

 /*auto inputWindow =  inputArea.get()->getWindow();
    keypad(inputWindow, TRUE);
    
     while(true){
      inputArea.get() -> getUserInput();
     } */
   /*
     auto roomWindow =  roomList.get()->getWindow();
    keypad(roomWindow, TRUE);
    
    noecho();
    while(true){
         
        int ch = wgetch(roomWindow);

        if(ch == KEY_UP || ch == KEY_DOWN){
            roomList->handleInputKey(ch);
            roomList->displayRoom();
        }

    }
    */

    