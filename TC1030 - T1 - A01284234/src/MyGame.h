

#include <iostream>
#include <string>
#include "Dice.h"
using namespace std;

class MyGames
{

    public:

        // Método de la clase MyGames que contiene la lógica del juego
        void start()
        {
            // IDs de los jugadores
            int player1 = 1; 
            int player2 = 2;

            // Contador de turnos
            int turnNum = 1;

            // Turno del jugador # (1 para player 1, 2 para player 2)
            int onTurn = 1;

            // variables de posición del jugador 1
            int pos1 = 0;
            int new_pos1;

            // variables de posición del jugador 2
            int pos2 = 0;
            int new_pos2;

            // variable con el valor de pasos que da un jugador en el tablero
            int roll;

            // Variable que controla si el juego sigue corriendo o no.
            bool gameOn = true;

            // Se crea objeto del dado
            Dice Dice;

            // Creamos tablero con array de 30 espacios
            string board[30] = {
                "N","N","N","L","N","N",
                "N","N","N","S","N","N",
                "N","N","L","N","S","N",
                "N","L","N","N","N","N",
                "N","N","N","N","S","N",
                };

            // anuncio para presionar E o C para salir o continuar con el juego.
            // Dependiendo de la decisión, se regresa un valor boleano que modifica la varaible gameOn.
            gameOn = announcement();

            // comienza ciclo del juego
            // mientras no haya ganador, y el usuario no salga, que el juego continue
            while (gameOn)
            {
                // Lógica del jugador 1
                if (onTurn == player1)
                {
                    // Con la clase Dice, obtenemos un número random y se guarda en la variable roll.
                    roll = Dice.diceRoll();
                    // La nueva posición del jugador se ve afectada por la cantidad que sacó en el dado.
                    new_pos1 = movePlayer(board, player1, pos1, roll);

                    // condicional para determinar si la posición es 30 o mayor. Si lo es, romper ciclo y determinar
                    // ganador
                    if (new_pos1 >= 30)
                    {
                    // Se imprimen las casillas y números ganadores del jugador 1
                    cout << turnNum << " " << player1 << " " << pos1+1 << " "  << roll << " " << board[29] << " "<< new_pos1+1 << "\n";

                    // Adelantamos el tiro del jugador 2 para ver si logra ganarle al 1.
                    roll = Dice.diceRoll();
                    new_pos2 = movePlayer(board, player2, pos2, roll);
                    cout << turnNum << " " << player2 << " " << pos2+1 << " " << roll << " " << board[pos2] << " "<< new_pos2+1 << "\n";

                    // Revisamos quien gana con la función checkWinner().
                    gameOn = checkWinner(new_pos1, player1, new_pos2, player2, gameOn);
                        
                        // actualizamos la variable onTurn para permitir que juege el jugador 2;
                        onTurn = player2;
                    }
                    // Si no hay ningún ganador, se imprimen los datos de juego del jugador 1 y se cambia de turno.
                    else
                    {

                    
                    cout << turnNum << " " << player1 << " " << pos1+1 << " "  << roll << " " << board[pos1] << " "<< new_pos1+1 << "\n";
                    
                    // actualizamos posición anterior por la nueva posición
                    pos1 = new_pos1;

                    // actualizamos la variable onTurn para permitir que juege el jugador 2;
                    onTurn = player2;

                    }
                }

                // Comienza lógica de jugdor 2 
                else if(onTurn == player2)
                {
                    // Se tira el dado
                    roll = Dice.diceRoll();

                    // Se mueve el jugador 2 en el tablero
                    new_pos2 = movePlayer(board, player2, pos2, roll);

                    // condicional para determinar si la posición es 30 o mayor. Si lo es, romper ciclo y determinar
                    // ganador
                    if (new_pos2 >= 30)
                    {
                        // Imprimimos datos ganadores del jugador 2
                        cout << turnNum << " " << player2 << " " << pos2+1 << " " << roll << " " << board[29] << " "<< new_pos2+1 << "\n";          
                        gameOn = checkWinner(new_pos1, player1, new_pos2, player2, gameOn);

                        
                        // actualizamos la variable onTurn para permitir que juege el jugador 1 nuevamente;
                        onTurn = player1; 
                    }
                    // Si no hay ningún ganador, se imprimen datos de juego del jugador 2.
                    else{
                    cout << turnNum << " " << player2 << " " << pos2+1 << " " << roll << " " << board[pos2] << " "<< new_pos2+1 << "\n";
                    

                    // actualizamos posición anterior por la nueva posición
                    pos2 = new_pos2;

                    // actualizamos la variable onTurn para permitir que juege el jugador 2;
                    onTurn = player1;       

                    // Se incrementa el contador de turnos
                    turnNum = turnNum + 1;

                    }

                    // Después de cada tiro se verifica si un jugador ya ganó.
                    gameOn = checkWinner(new_pos1, player1, new_pos2, player2, gameOn);
                    

                }

                

            }


        } // cierra método de start

        // función que regresa en dónde estará ubicado el jugador después de haber tirado el dado
        int movePlayer(string board[30], int player, int pos, int roll)
        {
            // REVISAR ESTO
            // si la posición del jugador es 30 o mayor, se determina el ganador y no entran los 
            // siguientes condicionales.
            if (pos+roll >= 30)
            {
                
                return pos+roll;
            }
            // Si el jugador cuando se mueve cae en una casilla "N", se retorna
            // el valor de esta casilla para imprimirse
            else if (board[pos+roll] == "N")
            {
                return pos+roll;
            } 
            // cuando el jugador cae en una casilla de escalera,
            // a la posición final se le suman 3 casillas más
            else if (board[pos+roll] == "L")
            {
                return pos+roll+3;
            } 
            // cuando el jugador cae en una casilla de serpiente,
            // a la posición final se le restan 3 casillas más.
            else if(board[pos+roll] == "S")
            {
                return pos+roll-3;
            }

            

        }

        // función para imprimir el tablero
        void printBoard(string board[])
        {
            for (int i = 0; i < 30; i++)
            {
                cout << board[i];

                // cada 6to caracter, que se haga un \n
                if (30 % i == 0)
                {
                    cout << "\n";
                }
            }
        }

        bool announcement()
        {
                string option;
                // anuncio al usuario
                cout << "Press C to continue next turn, or E to end the game: ";
                cin >> option;
                

                 while (option != "C" && option != "E" && option != "c" && option != "e")
            {
                cout << "Invalid option, please press C to continue next turn or E to end the game: ";
                cin >> option;

            }

            // si el usuario quiere salir del juego el ciclo while de los turnos no entrará
            if (option == "E" || option == "e")
            {
                cout << "-- Game Over --\n";
                cout << "Thanks for playing!!!";
                return false;
            }
            else
            {
                return true;
            }

        }

        // hacer función si hubo ya un ganador o no.
        bool checkWinner(int pos1, int player1, int pos2, int player2, bool gameOn)
        {

            // Este primer condicional verifica que, si se interrumpe el juego no hubo ingún ganador.
            if (!gameOn)
            {
                
                return false;

            }
            else if (pos1 == 30 && pos2 != 30)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player1 << " is the winner!!!\n";
                return false;
            }
            else if (pos2 == 30 && pos1 != 30)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player2 << " is the winner!!!\n";
                return false;
            }
            else if (pos1 >= 30 && pos2 >=30 && pos1 < pos2)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player1 << " is the winner!!!\n";
                return false;
            }
            else if (pos2 >= 30 && pos1 >=30 && pos2 < pos1)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player2 << " is the winner!!!\n";
                return false;

            } 
            else if (pos1 >= 30 && pos2 < 30)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player1 << " is the winner!!!\n";
                return false;
            }
            else if(pos2 >= 30 && pos1 < 30)
            {
                cout << "-- Game Over --\n";
                cout << "Player " << player2 << " is the winner!!!\n";
                return false;
            }else return true;
        }

};
