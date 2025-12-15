#include "ChatClientUI.h"

ChatClientUI::ChatClientUI() : parentWindow(LINES, COLS, 0,0){
   
    //dimensions for titlBar, messageArea, roomList, inputArea
    int titleWidth, titleHeight, 
        messageHeight, messageWidth, 
        roomHeight, roomWidth, 
        inputHeight, inputWidth;
    
    //Single vertical line  height,  position x and position y;
    int vLineHeight, vLineY, vLineX;
    
     titleHeight = 2;
     titleWidth = COLS - 2;
     inputHeight = 3;
     
    roomWidth = (COLS - rightPadding - leftPadding - vLinePadding * 2 - 1) / 4;// -1 accounting for single verticle line

    roomHeight  = LINES - titleHeight - inputHeight - topPadding - bottomPadding;

    messageHeight = roomHeight;

    messageWidth = COLS - roomWidth - rightPadding - leftPadding - vLinePadding * 2 - 1; // -1 accounting for single verticle line
    
    inputWidth = messageWidth;

    vLineHeight = messageHeight + 2;

    int titleY, titleX;
    titleY = 1, titleX = 1;

    int messageY, roomY;
    roomY =  LINES - inputHeight - messageHeight + 1; //titleY + titleHeight + topPadding;
    messageY = roomY;

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

void ChatClientUI::run(const std::string& ip, int port){

    if(!client.connectToServer(ip, port)){
      throw std::runtime_error("Failed to connect to server at " + ip + ":" + std::to_string(port));
    }

    client.startReceiving([this](const std::string& msg){
       std::lock_guard<std::mutex> lock(messageMutex);
       receivedMessages.push(msg);
    });
    
    auto parentWin = parentWindow.getWindow();
    noecho();
    cbreak();
    nodelay(parentWin, TRUE);// input functions return immediately without waiting for 
                          // input;
    keypad(parentWin, TRUE);

    auto roomListWindow = roomList.get();
    auto inputAreaWindow = inputArea.get();
    auto messageAreaWindow = messageArea.get();
    
    while(true){
     int ch = wgetch(parentWin);

      if(ch != ERR){

      if(ch == KEY_UP || ch == KEY_DOWN)
        roomListWindow->handleInputKey(ch);

      else if(ch == '\n'){
       std::string message = inputAreaWindow->retrieveBuffer();
         if(!message.empty()){
         client.sendMessage(message);
         messageAreaWindow->displayMessage("You: " + message);
         }
      }
      else
      inputAreaWindow->handleKey(ch);
    }
    std::lock_guard<std::mutex> lock(messageMutex);

    while(!receivedMessages.empty()){
        std::string message = receivedMessages.front();
        receivedMessages.pop();
        
        messageAreaWindow->displayMessage("Server: " + message);
    }
    napms(10);
}

client.disconnect();
endwin();
}

    