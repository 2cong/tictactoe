
#include "tictactoe.h"

int main() {
    std::string currentPlayer = "player1";
    bool result = false;
    int turn = 0;
    TicTacToe tictactoe;
    char choiceItem;

    std::cout<< "Tic Tac Toe 게임을 시작합니다.\nplayer1의 말을 O, X 중 선택해주세요:";
    
    tictactoe.setPlayerItem();
    tictactoe.showBoard();

    while (result == false && turn < 9){ 
        std::cout<< currentPlayer <<"의 턴입니다. 말을 놓을 위치를 선택해주세요:";
        tictactoe.putItem(currentPlayer);
        tictactoe.showBoard();
        result = tictactoe.getResult(currentPlayer);
        
        if (result == false && currentPlayer == "player1") 
          {currentPlayer = "player2" ;
          turn += 1;}
        else if (result == false && currentPlayer == "player2")
        {currentPlayer = "player1";
        turn += 1;
        }
      };

    if (result == true){
      choiceItem = tictactoe.getChoiceItem(currentPlayer);
      std::cout<< "우승자는 " <<choiceItem<< " 을 선택한 " <<currentPlayer<<" 입니다!";
      return choiceItem;
    }
    else{
      std::cout<< "무승부 입니다!";
      return 0;
    }
}
