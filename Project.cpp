#include<iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};  //table main no.show
char turn = 'X';    //variable
int row,column;  //declaration
bool draw = false;  //table full 

void display_board()     //functin
{
	system("cls");   //screen clear 
	cout<<"\n\n T i ck  C r o s s  G a m e"<<endl;
	cout<<"\tPlayer1 [X]  \n\tPlayer2 [O]\n\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";
	        
}
void player_turn()     //function player ke turn ke liye
{
	int choice;
	
	if(turn == 'X')
	cout<<"\n\tPlayer1 [x] turn:";       // agar  symbol X ke equal h to player 1 ki chance h
	
	if(turn == 'O')
	cout<<"\n\tPlayer2 [O] turn:";  //agar symbol O ke equal h to player2 ki chance h
	
	cin>>choice;   //user se input lene ke liye
	
	switch(choice)
	{
	
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;	
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;s
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		
		    default:
		    	cout<<"Invalid choice\n";
		    	break;
		
     }
     //check for which user turn
     if(turn == 'X' && board[row][column]!='X' && board[row][column]!='O')       // jo no.likha h vo x or y ke equal nhi h vanha pare value store karn ke liye
     {
     	board[row][column] = 'X';
     	turn = 'O';
	 }
	 else if(turn == 'O' && board[row][column]!='X' && board[row][column]!='O' )
     {
     	board[row][column] = 'O';
     	turn = 'X';
	 }
	 else
	 {
	 	cout<<"Box already filled!\n please try again!! \n\n";   //wrong no. choose karne par
		 player_turn();    //function call 
	 }
	 display_board();    //function call
}

bool gameover()   //game over function
{
	//check win
	for(int i = 0; i<3; i++)
	if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])   //rows and columns 
	return false;  
	
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])   //diagonal form  ke liye
	return false;
	
	
	//if there is any box not filled 
	//game over ya continue ko check karne keliye
	for(int i = 0; i<3; i++)   
	for(int j = 0; j<3; j++)
	if(board[i][j] != 'X' && board[i][j]!='O')  //x or o ke equal bhi nhi h to
	return true;
	
	//game draw
	draw = true;  
	return false;  //game over kar deta h agar koi bhi jita nhi hoga
	
}
main()
{
	
	while(gameover())      //user chance ke liye game off na ho
	{
	display_board();    //function call for board display
	player_turn();      //function call for user chances
	gameover();      //gameover function call
	
}
if(turn == 'X' && draw == false)   //draw flase h to player 1 or 2 jiitega
cout<<"Player2 [O] Wins!!  Congratulation\n";

else if(turn == 'O' && draw == false)
cout<<"Player1 [X] Wins!!  Congratulation\n";
else
cout<<"GAME DRAW!! \n";			
	
}
