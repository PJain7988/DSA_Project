#include<bits/stdc++.h>
using namespace std;
string Winner(char Ttt[][3], string P1, string P2)
{
    string Winner = " ";
    if ((Ttt[0][0] == 'X' && Ttt[0][1] == 'X' && Ttt[0][2] == 'X') ||
        (Ttt[1][0] == 'X' && Ttt[1][1] == 'X' && Ttt[1][2] == 'X') ||
        (Ttt[2][0] == 'X' && Ttt[2][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][0] == 'X' && Ttt[2][0] == 'X') ||
        (Ttt[0][1] == 'X' && Ttt[1][1] == 'X' && Ttt[2][1] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][2] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][1] == 'X' && Ttt[2][0] == 'X')){
        Winner = P1;
    }
    if ((Ttt[0][0] == 'O' && Ttt[0][1] == 'O' && Ttt[0][2] == 'O') ||
        (Ttt[1][0] == 'O' && Ttt[1][1] == 'O' && Ttt[1][2] == 'O') ||
        (Ttt[2][0] == 'O' && Ttt[2][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][0] == 'O' && Ttt[2][0] == 'O') ||
        (Ttt[0][1] == 'O' && Ttt[1][1] == 'O' && Ttt[2][1] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][2] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][1] == 'O' && Ttt[2][0] == 'O')){
        Winner = P2;
    }
    return Winner;
}
string PlayerInput(char start[3][3] , string P1 , string P2){
    string p1;
    string p2;
    char repeat[10];
    string Win;
    for (int i = 0; i < 5; i++){
        cout << P1 << " turn : ";
        do{
            cin >> p1;
            if (p1.length() == 1 && p1[0]>48 && p1[0]<58 && p1[0] != repeat[0] && p1[0] != repeat[1]
                && p1[0] != repeat[2] && p1[0] != repeat[3] && p1[0] != repeat[4] && p1[0] != repeat[5]
                && p1[0] != repeat[6] && p1[0] != repeat[7] && p1[0] != repeat[8] && p1[0] != repeat[9]){
                cout << endl;
                break;
            }
            else if (p1[0] == repeat[0] || p1[0] == repeat[1] || p1[0] == repeat[2] || p1[0] == repeat[3]
                || p1[0] == repeat[4] || p1[0] == repeat[5] || p1[0] == repeat[6] || p1[0] == repeat[7]
                || p1[0] == repeat[8] || p1[0] == repeat[9])
            {
                cout << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                cout << P1 << " turn again : ";
            }
            else
            {
                cout << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                cout << P1 << " turn again : ";
            }
        } while (true);

        if (p1[0] == '1') { start[0][0] = 'X'; }
        if (p1[0] == '2') { start[0][1] = 'X'; }
        if (p1[0] == '3') { start[0][2] = 'X'; }
        if (p1[0] == '4') { start[1][0] = 'X'; }
        if (p1[0] == '5') { start[1][1] = 'X'; }
        if (p1[0] == '6') { start[1][2] = 'X'; }
        if (p1[0] == '7') { start[2][0] = 'X'; }
        if (p1[0] == '8') { start[2][1] = 'X'; }
        if (p1[0] == '9') { start[2][2] = 'X'; }
 
        Win = Winner(start, P1, P2);
 
        cout << " " << start[0][0] << " | " << start[0][1] << " | " << start[0][2];
        cout << "\t\t 1 | 2 | 3 " << endl;
        cout << " " << start[1][0] << " | " << start[1][1] << " | " << start[1][2] ;
        cout << "\t\t 4 | 5 | 6 " << endl;
        cout << " " << start[2][0] << " | " << start[2][1] << " | " << start[2][2] ;
        cout << "\t\t 7 | 8 | 9 " << endl << endl;
 
        if (Win == P1 || Win == P2) break;
        else if (i == 4) { Win = "Draw"; break; }
        repeat[i] = p1[0];
        cout << P2 << " turn : ";
        do
        {
            cin >> p2;
            if (p2.length() == 1 && p2[0]>48 && p2[0]<58 && p2[0] != p1[0] && p2[0] != repeat[0] &&
                p2[0] != repeat[1] && p2[0] != repeat[2] && p2[0] != repeat[3] && p2[0] != repeat[4]
                && p2[0] != repeat[5] && p2[0] != repeat[6] && p2[0] != repeat[7] && p2[0] != repeat[8]
                && p2[0] != repeat[9])
            {
                cout << endl;
                break;
            }
 
            else if (p2[0] == repeat[0] || p2[0] == repeat[1] || p2[0] == repeat[2] || p2[0] == repeat[3]
                || p2[0] == repeat[4] || p2[0] == repeat[5] || p2[0] == repeat[6] || p2[0] == repeat[7]
                || p2[0] == repeat[8] || p2[0] == repeat[9])
                 {
                cout << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                cout << P2 << " turn again : ";
                 }
            else
            {
                cout << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                cout << P2 << " turn again : ";
            }
        } while (true);
 
 
        if (p2[0] == '1') { start[0][0] = 'O'; }
        if (p2[0] == '2') { start[0][1] = 'O'; }
        if (p2[0] == '3') { start[0][2] = 'O'; }
        if (p2[0] == '4') { start[1][0] = 'O'; }
        if (p2[0] == '5') { start[1][1] = 'O'; }
        if (p2[0] == '6') { start[1][2] = 'O'; }
        if (p2[0] == '7') { start[2][0] = 'O'; }
        if (p2[0] == '8') { start[2][1] = 'O'; }
        if (p2[0] == '9') { start[2][2] = 'O'; }
 
        Win = Winner(start, P1, P2);
  
        cout << " " << start[0][0] << " | " << start[0][1] << " | " << start[0][2];
        cout << "\t\t 1 | 2 | 3 " << endl;
        cout << " " << start[1][0] << " | " << start[1][1] << " | " << start[1][2];
        cout << "\t\t 4 | 5 | 6 " << endl;
        cout << " " << start[2][0] << " | " << start[2][1] << " | " << start[2][2];
        cout << "\t\t 7 | 8 | 9 " << endl << endl;
 
 
        if (Win == P1 || Win == P2) break; 
        repeat[i + 5] = p2[0];
    }
    return Win;
}
void Display(string W , string p1 , string p2){
    if (W == p1 || W == p2)
    {
        cout << "\n\n\t\t\t\t\t        Winner of Game is : " <<W << endl << endl;
    }
    else cout << "\t\t\t\t\t\t\tGame is Draw \n";
    cout << "\t\t\t\t\t *** Thank You for using our Game Program ***\n";
    cout << "\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";
}
int main()
{
    char start[3][3]{
       {'-', '-', '-'},
       {'-', '-', '-'},
       {'-', '-', '-'}
    };
    string P1;
    string P2;
    cout << "\t\t\t\t     ***  TIC - TAC - TOE  ***\n\n";
    cout << "\t\t\t\t        Welcome to our Game\n\n";

    cout << "Enter player 1 name : ";
    getline(cin, P1);
    cout << "Enter player 2 name : ";
    getline(cin, P2);

    cout << "\nChoose following format to enter input\n\n";
    cout << " 1 | 2 | 3 " << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << " 7 | 8 | 9 " << endl << endl;
 
    string Winner = PlayerInput(start, P1, P2);
    Display(Winner, P1, P2);
    return 0;
}