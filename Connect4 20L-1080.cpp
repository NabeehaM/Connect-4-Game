//CONNECT4 GAME BY: NABEEHA MUDASSIR 20L-1080 BS SE 1A1

#include<iostream>
#include<string>

using namespace std;


struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    void re_init(string Names[]){
        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 6;
            for(int j = 0; j< 6; j++)
                Data[j][i] = '_';
        }
        Result = 0;
        GameOver = false;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
        TurningPlayer;
    }

    int MakeMove(int Column){

            if ( ColumnMoves[Column] == 0 ) //check draw case
                {
                    int counter=0;
                    for ( int i=0 ; i < 6 ; i++)
                        {
                            if (ColumnMoves[i]==0)
                            {
                                counter++;
                            }
                        }
                    if (counter == 6)
                        {
                            Result = 0;
                            GameOver = true;
                            return 5;
                        }
                }
            if (Column==50) //reset case
                {
                    return -1;
                }
            else if ( Column > 6 || Column < 0 || ColumnMoves[Column] == 0 )
                    {
                        return 1;
                    }
            else
            {
                int a;
                if (TurningPlayer == 0)
                    {
                        a = 0;
                    }
                else
                    {
                        a = 1;
                    }

                if ( ColumnMoves [Column] <= 6 && ColumnMoves [Column]>0 && GameOver == false) //to ensure that rows empty in this column are between 0 exclusive and 6 inclusive
                    {

                            int  b = ColumnMoves[Column]; //b is the number of empty rows
                            Data[b-1][Column] = PlayerChar[a]; // b-1 because of indexing that starts from 0
                            ColumnMoves[Column]={b-1}; // holds how many rows are free from 0 not included to 6 included in that column

                            if (TurningPlayer==0)
                                {
                                    TurningPlayer=1;
                                }
                            else
                                {
                                    TurningPlayer=0;
                                }

                            CheckIfGameOver( (ColumnMoves[Column]) , Column ); //row index
                            return 0;
                    }
            }
    }

    void ShowGame(){
            for (int i = 0 ; i < 6 ; i++)
            {

                for (int j = 0 ; j < 7 ; j++)
                {
                    if (i==0 && j==0)
                        {
                            cout<<"\t \t \t ";
                        }
                    cout<< Data[i][j] <<" ";
                }
                cout<<endl<<"\t \t \t ";
            }
}

    bool isGameOver(){

        return GameOver;
}

    int WhosTurn(){

        return TurningPlayer;
}
    int rowcheck (int r, int c){

    int a=0;int R=1;

        while ( GameOver == false && a < 2 )
        {
            if ( c >= 0 && c < 4) //last char can only be on column index 3, yeh us se agay check karta hai, index 6 is last column
            {
                if (Data[r][c] == PlayerChar[a] && Data[r][c+1] == PlayerChar[a] && Data[r][c+2] == PlayerChar[a] && Data[r][c+3] == PlayerChar[a])
                    {
                        Result = R;
                        GameOver=true;
                        Data[r][c] = PlayerWinningChar[a];
                        Data[r][c+1] = PlayerWinningChar[a];
                        Data[r][c+2] = PlayerWinningChar[a];
                        Data[r][c+3] = PlayerWinningChar[a];
                    }
            }
            if (c > 2 && c <= 6) // yeh last col se peechay check karta hai, tou last char has to be on column index: 3
            {
                if (Data[r][c] == PlayerChar[a] && Data[r][c-1] == PlayerChar[a] && Data[r][c-2] == PlayerChar[a] && Data[r][c-3] == PlayerChar[a])
                    {
                            Result = R;
                            GameOver = true;
                            Data[r][c] = PlayerWinningChar[a]; Data[r][c-1] = PlayerWinningChar[a]; Data[r][c-2] = PlayerWinningChar[a];Data[r][c-3] = PlayerWinningChar[a];
                    }
            }
            a++;
            R=R-2;
        }
}
    int columncheck(int r, int c){

             if (r<3)
             {
                 if (Data[r][c]==PlayerChar[0] && Data[r+1][c]==PlayerChar[0] && Data[r+2][c]==PlayerChar[0] && Data[r+3][c]==PlayerChar[0])
                    {
                        Result = 1;
                        GameOver=true;
                        Data[r][c]=PlayerWinningChar[0];
                        Data[r+1][c]=PlayerWinningChar[0];
                        Data[r+2][c]=PlayerWinningChar[0];
                        Data[r+3][c]=PlayerWinningChar[0];
                    }

                else if (Data[r][c]==PlayerChar[1] && Data[r+1][c]==PlayerChar[1] && Data[r+2][c]==PlayerChar[1] && Data[r+3][c]==PlayerChar[1])
                    {
                        Result = -1;
                        GameOver=true;
                        Data[r][c]=PlayerWinningChar[1];
                        Data[r+1][c]=PlayerWinningChar[1];
                        Data[r+2][c]=PlayerWinningChar[1];
                        Data[r+3][c]=PlayerWinningChar[1];
                    }
             }

}
    int diagonalcheck2(int r, int c){

        int a=0; int R=1;
        while ( GameOver == false && a < 2 )
        {
                        if (r>=0 && r<=2 && c>=3 && c<=6 )
                        {
                            if (Data[r][c]==PlayerChar[a] && Data[r+1][c-1]==PlayerChar[a] && Data[r+2][c-2]==PlayerChar[a] && Data[r+3][c-3]==PlayerChar[a])
                                {
                                    GameOver=true;
                                    Result=R;
                                    Data[r][c]=PlayerWinningChar[a] ;
                                    Data[r+1][c-1]=PlayerWinningChar[a];
                                    Data[r+2][c-2]=PlayerWinningChar[a];
                                    Data[r+3][c-3]=PlayerWinningChar[a];
                                }
                        }
                        else if (r>=1 && r<=3 && c>=2 && c<=5)
                        {
                            if (Data[r][c]==PlayerChar[a] && Data[r+1][c-1]==PlayerChar[a] && Data[r+2][c-2]==PlayerChar[a] && Data[r-1][c+1]==PlayerChar[a])
                                {
                                    GameOver=true;
                                    Result=R;
                                    Data[r][c]=PlayerWinningChar[a];
                                    Data[r+1][c-1]=PlayerWinningChar[a];
                                    Data[r+2][c-2]=PlayerWinningChar[a];
                                    Data[r-1][c+1]=PlayerWinningChar[a];
                                }
                        }

                        else if (r<=4 && r>=2 && c>=1 && c<=4)
                        {
                            if (Data[r][c]==PlayerChar[a] && Data[r+1][c-1]==PlayerChar[a] && Data[r-1][c+1]==PlayerChar[a] && Data[r-2][c+2]==PlayerChar[a])
                                {
                                    GameOver=true;
                                    Result=R;
                                    Data[r][c]=PlayerWinningChar[a];
                                    Data[r+1][c-1]=PlayerWinningChar[a];
                                    Data[r-1][c+1]=PlayerWinningChar[a];
                                    Data[r-2][c+2]=PlayerWinningChar[a];
                                }
                        }

                        else if (r>=3 && r<=5 && c<=3 && c>=0)
                        {
                            if (Data[r][c]==PlayerChar[a] && Data[r-1][c+1]==PlayerChar[a] && Data[r-2][c+2]==PlayerChar[a] && Data[r-3][c+3]==PlayerChar[a])
                                {
                                    GameOver=true;
                                    Result=R;
                                    Data[r][c]=PlayerWinningChar[a] ;
                                    Data[r-1][c+1]=PlayerWinningChar[a];
                                    Data[r-2][c+2]=PlayerWinningChar[a];
                                    Data[r-3][c+3]=PlayerWinningChar[a];
                                }
                        }

                        a++;
                        R=R-2;
        }

}
    int diagonalcheck1 (int r, int c){

    int a=0;
    int R=1;
    while ( a<2 && GameOver==false )
        {
                            if (r<=2 && r>=0 && c>=3 && c<=0)
                            {
                                if (Data[r][c]==PlayerChar[a] && Data[r+1][c+1]==PlayerChar[a] && Data[r+2][c+2]==PlayerChar[a] && Data[r+3][c+3]==PlayerChar[a])
                                    {
                                        GameOver=true;
                                        Result=R;
                                        Data[r][c]=PlayerWinningChar[a];
                                        Data[r+1][c+1]=PlayerWinningChar[a];
                                        Data[r+2][c+2]=PlayerWinningChar[a];
                                        Data[r+3][c+3]=PlayerWinningChar[a];
                                    }
                            }
                            else if (r>=1 && r<=3 && c>=1 && c<=4)
                            {
                                if (Data[r][c]==PlayerChar[a] && Data[r-1][c-1]==PlayerChar[a]&& Data[r+1][c+1]==PlayerChar[a] && Data[r+2][c+2]==PlayerChar[a])
                                {
                                    GameOver=true;
                                    Result=R;
                                    Data[r][c]=PlayerWinningChar[a] ;
                                    Data[r-1][c-1]=PlayerWinningChar[a];
                                    Data[r+1][c+1]=PlayerWinningChar[a];
                                    Data[r+2][c+2]=PlayerWinningChar[a];
                                }
                            }

                            else if (r<=4 && r>=2 && c>=2 && c>=5)
                            {
                                if (Data[r][c]==PlayerChar[a] && Data[r-1][c-1]==PlayerChar[a] && Data[r-2][c-2]==PlayerChar[a] && Data[r+1][c+1]==PlayerChar[a])
                                    {
                                        GameOver=true;
                                        Result=R;
                                        Data[r][c]=PlayerWinningChar[a];
                                        Data[r-1][c-1]=PlayerWinningChar[a];
                                        Data[r-2][c-2]=PlayerWinningChar[a];
                                        Data[r+1][c+1]=PlayerWinningChar[a];
                                    }
                            }

                            else if (r>=3 && r<=5 && c>=3 && c<=6)
                            {
                                if (Data[r][c]==PlayerChar[a] && Data[r-1][c-1]==PlayerChar[a] && Data[r-2][c-2]==PlayerChar[a] && Data[r-3][c-3]==PlayerChar[a])
                                    {
                                        GameOver=true;
                                        Result=R;
                                        Data[r][c]=PlayerWinningChar[a] ;
                                        Data[r-1][c-1]=PlayerWinningChar[a] ;
                                        Data[r-2][c-2]=PlayerWinningChar[a];
                                        Data[r-3][c-3]=PlayerWinningChar[a];
                                    }
                            }


            a++;
            R=R-2;
        }

}

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "what";
        return PlayerNames[id];
}
private:
    bool CheckIfGameOver(int r, int c){

          if ( GameOver == false )
          {
                rowcheck(r,c);
                columncheck(r,c);
                diagonalcheck1(r,c);
                diagonalcheck2(r,c);
          }
}

    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
    bool GameOver=false; // If true it means the game is over.
    int Result;// Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
};

int main(){
    int choice;
    int A,C ;
    bool draw=false;

    cout<<"\t \t \t WELCOME TO CONNECT4! \t \t \t"<<endl<<endl;
    cout<<"\t \t \t Brought to you by Nabeeha Mudassir "<<endl;

    string One, Two;

    cout<<endl<<"\t \t \t Player One: Enter your ID: ";
    cin>>One;
    cout<<"\t \t \t Player Two: Enter your ID: ";
    cin>>Two;

    cout<<endl<<"\t \t \t Welcome Aboard: "<<One<<" and "<<Two<<"!";

    string N[2]={One,Two};
    connect4 Game(N);

    cout<<endl<<"\t \t \t To play this game, you will be asked to enter column numbers. "<<endl;
    cout<<endl<<"\t \t \t Remember that Column Numbers start from 0 and go up to 6.";
    cout<<endl<<"\t \t \t Expect an error message if you enter a column out of range, or if ";
    cout<<endl<<" \t \t \t you enter a column that is full. This is the board that will be used. "<<endl;
    Game.ShowGame();

    cout<<endl<<"\t \t \t Connect 4 characters in a row, in a column, or diagonally consecutively to WIN."<<endl;
    cout<<endl<<" \t \t \t Follow the rules of the game. "<<endl;

    cout<<"\t \t \t Player 1: "<<One<<" "<<"will use character o "<<endl;
    cout<<"\t \t \t Player 2: "<<Two<<" "<<"will use character x "<<endl;

    cout<<"\t \t \t Remember that you can CLEAR THE BOARD any time by PRESSING 50 as your choice. "<<endl;
    cout<<" \t \t \t Let's Start!"<<endl;

    A = Game.isGameOver();

    while ( A == false )
    {
                    C=Game.WhosTurn();
                    if (C==0)
                        {
                           cout<<endl<<"\t \t \t "<<One<<", Enter Column: ";
                        }
                    else
                        cout<<endl<<"\t \t \t "<<Two<<", Enter Column: ";

                    cin>>choice;

                    int B = Game.MakeMove(choice);

                    if (B==5)
                        {
                            //cout<<"GAME DRAWN";
                            draw=true;
                        }

                    while ( B == 1 || B == -1 )
                    {
                        if (B==1)
                        {cout<<endl<<"\t \t \t INVALID CHOICE, Enter again: ";}
                        else if (B==-1)
                            {   Game.re_init(N);
                                cout<<"\t \t \t You have cleared the board. Continue to enter your choice: "<<endl;
                                Game.ShowGame();
                            }
                        cout<<endl<<"\t \t \t Your choice is: ";
                        cin>>choice;
                        B=Game.MakeMove(choice);
                    }

                     if (B==0)
                      Game.ShowGame();

                      A=Game.isGameOver();
     }

     if (A==true && draw==false)
     {
         cout<<endl<<" \t \t \t Looks like we have a WINNER!"<<endl;
         if (C==0)
         {
             cout<<"\t \t \t PLAYER ONE: CONGRATULATIONS "<<One<<"!";
         }
         else
            cout<<"\t \t \t PLAYER TWO: CONGRATULATIONS "<<Two<<"!";
     }

     else if (A==true && draw==true)
     {
         cout<<endl<<"\t \t \t DRAW! NEITHER PLAYER WAS ABLE TO WIN."<<endl;

     }

     cout<<endl<<endl<<"\t \t \t GAME OVER ";
     cout<<endl<<"\t \t \t Come Back Soon! ";




    return 0;
}
