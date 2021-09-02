//
// Created by Iryna Zinko on 9/2/21.
//

#ifndef LABA1GAMEOFKOSTI_GAME_H
#define LABA1GAMEOFKOSTI_GAME_H

#include <iostream>


class Player{
private:
    int score;
public:
    Player(){
        score = 0;
    }
    void turn(){
        int scoreTurn = rand() % 6 + 1;
        score += scoreTurn;
        Bone::draw(scoreTurn);
    }
    int getScore() const{
        return score;
    }
    void resetScore(){
        score = 0;
    }
};

class Game{
private:
    Game(){ }
    static void showMenu(){
        std::cout << "Menu :" << std::endl;
        std::cout << "   1 - TURN" << std::endl;
        std::cout << "   2 - SCORE" << std::endl;
        std::cout << "   3 - EXIT" << std::endl;
    }
public:
    static void run(size_t countTurns = 3){
        Player p1;
        Player p2;
        short itemMenu = 0;
        size_t currentTurn = 0;
        showMenu();
        while(currentTurn < countTurns){
            std::cin >> itemMenu;
            switch(itemMenu){
                case 1:


                default:{
                    std::cout << "Unknow item menu." << std::endl;
            }
            std::cin.get();
            showMenu();
        }
        std::cout << "Player 1 :" << p1.getScore() << std::endl;
        std::cout << "Player 2 :" << p2.getScore() << std::endl;
        if(p1.getScore() > p2.getScore())
            std::cout << "Player 1 winner" << std::endl;
        else if(p1.getScore() < p2.getScore())
            std::cout << "Player 2 winner" << std::endl;
        else
            std::cout << "dead heat" << std::endl;
    }
};
}


#endif //LABA1GAMEOFKOSTI_GAME_H
