#include <iostream>

using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>

namespace cf{

    class Bone{

    private:
        Bone(){}

    public:
        static void draw(size_t idx){

            switch(idx){
                case 1:
                    cout <<"===========" <<endl;
                    cout <<"|         |" <<endl;
                    cout <<"|    0    |" <<endl;
                    cout <<"|         |" <<endl;
                    cout <<"===========" <<endl;
                    break;

                case 2:
                    cout <<"===========" <<endl;
                    cout <<"|    0    |" <<endl;
                    cout <<"|         |" <<endl;
                    cout <<"|    0    |" <<endl;
                    cout <<"===========" <<endl;
                    break;

                case 3:
                    cout <<"===========" <<endl;
                    cout <<"|  0      |" <<endl;
                    cout <<"|    0    |" <<endl;
                    cout <<"|      0  |" <<endl;
                    cout <<"===========" <<endl;
                    break;

                case 4:
                    cout <<"===========" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"|         |" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"===========" <<endl;
                    break;

                case 5:
                    cout <<"===========" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"|    0    |" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"===========" <<endl;

                    break;

                case 6:
                    cout <<"===========" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"|  0   0  |" <<endl;
                    cout <<"===========" <<endl;
                    break;
                default : cout << "UNKNOW BONE" << endl;
            }
        }
    };




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
            cout << endl;
            cout << "MENU:" << endl;
            cout << "   0 - Rules" << endl;
            cout << "   1 - Roll" << endl;
            cout << "   2 - Score" << endl;
            cout << "   3 - Reset Score" << endl;
            cout << "   4 - Exit" << endl;
            cout <<"====================================================" <<endl;

        }

    public:

        static void run(size_t countTurns = 50){
            Player p1;
            Player p2;

            short itemMenu = 0;
            size_t currentTurn = 0;
            showMenu();
            while(currentTurn < countTurns){
                cin >> itemMenu;

                switch(itemMenu){

                    case 0:
                        cout << "RULES:\n"
                                "You need to select the Roll option further and the program will throw two random dice.\n"
                                "The first dice is yours, the second is your computer.\n"
                                "The one who has the most points is the winner.\n"
                                "Maximum number of throws 50\n"
                                "Have fun!" << endl;
                        cout <<"====================================================" <<endl;

                        break;

                    case 1 :
                        p1.turn();
                        p2.turn();
                        ++currentTurn;
                        cout <<"====================================================" <<endl;
                        break;

                    case 2 :
                        cout << "Your/Comp score" << endl;
                        cout << "Player :" << p1.getScore() << endl;
                        cout << "Computer :" << p2.getScore() << endl;
                        cout <<"====================================================" <<endl;

                        break;
                    case 3 :
                        cout << "Reset Score" << endl;
                        p1.resetScore();
                        p2.resetScore();
                        cout <<"====================================================" <<endl;

                        break;

                    case 4 :
                        cout << "Thanks for game! " << endl;
                        cout <<"====================================================" <<endl;

                        return;

                        default:
                        cout << "Unknow item menu." << endl;
                }

                cin.get();
                showMenu();
            }

            cout <<"====================================================" <<endl;
            cout << "Player 1 :" << p1.getScore() << endl;
            cout << "Computer  :" << p2.getScore() << endl;
            cout <<"====================================================" <<endl;

            if(p1.getScore() > p2.getScore())
                cout << "Player 1 is winner" << endl;
            else if(p1.getScore() < p2.getScore())
                cout << "Computer is winner" << endl;
            else
                cout << "The game ended with the same result" << endl;
        }
    };
}

int main()
{
    cout << endl;
    cout <<"====================================================" <<endl;
    cout << " The program was made by Iryna Zinko " << endl
         << " Welcome to \"Dice Game\"" << endl;
    cout <<"====================================================" <<endl;

    cf::Game::run();

    return 0;
}