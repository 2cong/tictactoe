#include <iostream>
#include <algorithm>

class TicTacToe{
  char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  char firstPlayerItem;
  char secondPlayerItem;

  public:    
    void showBoard(){
      std::cout<< "\nCurrent Board Status\n\n";
      std::cout<< "|-------|-------|-------|\n" ;
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|   "<<board[0][0]<< "   |   "<<board[0][1]<<"   |   "<<board[0][2]<<"   |\n";
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|-------|-------|-------|\n" ;
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|   "<<board[1][0]<< "   |   "<<board[1][1]<<"   |   "<<board[1][2]<<"   |\n";
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|-------|-------|-------|\n" ;
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|   "<<board[2][0]<< "   |   "<<board[2][1]<<"   |   "<<board[2][2]<<"   |\n";
      std::cout<< "|       |       |       |\n" ;
      std::cout<< "|-------|-------|-------|\n\n" ;
    };

    void setPlayerItem(){
      char choiceItem;

      std::cin>> choiceItem;
      if (choiceItem == 'X' || choiceItem == 'x')
        {firstPlayerItem = 'X';
         secondPlayerItem = 'O';
        }
      else if (choiceItem == 'O'|| choiceItem == 'o')
        {firstPlayerItem = 'O';
         secondPlayerItem = 'X';
        }
      else
        {std::cout<< "잘못된 말을 선택했습니다. O, X 중 선택해주세요:";
        return setPlayerItem();
      }
      std::cout<< "player1의 말은 "<<firstPlayerItem << " player2의 말은 " <<secondPlayerItem << "로 선택되었습니다.\n\n";
    };

  bool isValidPlace(char item){
    if (item != 'X' && item != 'O')
      return true;
    else
      return false;
  };

  char getChoiceItem(std::string currentPlayer){
    char choiceItem;

    if (currentPlayer == "player1") 
      choiceItem = firstPlayerItem ;
    else
      choiceItem = secondPlayerItem ;    

    return choiceItem;
  };

  void putItem(std::string currentPlayer){
    char placeStatus;
    char choiceItem;
    int col;
    int row;
    int placeNumber;
    bool isPossiblePlaceNumber = false;
    char possiblePlaceNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    choiceItem = getChoiceItem(currentPlayer);

    while (isPossiblePlaceNumber == false){
      std::cin>> placeNumber;
      isPossiblePlaceNumber = std::find(std::begin(possiblePlaceNumber), std::end(possiblePlaceNumber), placeNumber) != std::end(possiblePlaceNumber);
      if (isPossiblePlaceNumber == false)
        std::cout << "잘못된 위치입니다. 다시 선택해주세요:";
    };

    switch(placeNumber){
      case 1:
        col=0; row=0; placeStatus = board[col][row]; break;
      case 2:
        col=0; row=1; placeStatus = board[col][row]; break;
      case 3:
        col=0; row=2; placeStatus = board[col][row]; break;
      case 4:
        col=1; row=0; placeStatus = board[col][row]; break;
      case 5:
        col=1; row=1; placeStatus = board[col][row]; break;
      case 6:
        col=1; row=2; placeStatus = board[col][row]; break;
      case 7:
        col=2; row=0; placeStatus = board[col][row]; break;
      case 8:
        col=2; row=1; placeStatus = board[col][row]; break;
      case 9:
        col=2; row=2; placeStatus = board[col][row]; break;
      }
      
    
    if (isValidPlace(placeStatus))
        board[col][row] = choiceItem;
    else
      {std::cout<< "해당 위치는 이미 놓여있는 말이 있습니다. 다른 위치를 선택해주세요: ";
      return putItem(currentPlayer);
      };
    };

  bool getResult(std::string currentPlayer){
    char choiceItem;
    bool result = false;
    
    choiceItem = getChoiceItem(currentPlayer);
    
    if (board[0][0] == choiceItem && board[1][1] == choiceItem && board[2][2] == choiceItem)
      result = true;
      
    else if (board[2][0] == choiceItem && board[1][1] == choiceItem && board[0][2] == choiceItem)
       result = true;

    else
      for (int i=0; i < 3; i++)
        if (board[i][0] == choiceItem && board[i][1] == choiceItem && board[i][2] == choiceItem){
          result = true;
          break;
        }
        else if (board[0][i] == choiceItem && board[1][i] == choiceItem && board[2][i] == choiceItem){
          result = true;
          break;
    };

  return result;
  };
};
