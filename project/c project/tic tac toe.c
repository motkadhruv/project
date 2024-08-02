#include<stdio.h>
#include<conio.h>
void printboard();
int checkwin();
void system();

char board[]={'0','1','2','3','4','5','6','7','8','9'};

void main(){
	int player=1,input,status=-1,mark;
	printboard();
	
	while(status==	-1)
	{
	
	player=(player%2==0) ? 2 :1;
	char mark=(player==1) ? 'x' : 'o';
	printf("pleas  enter number for player %d\n",player);
	
	scanf("d",&input);
	if(input<1 || input>9)
	{
		printf("invelid input");
	}
	}
	
	
	
	board[input]=mark;
	printboard();
	
	
	int result=checkwin();
	
	if(result==1)
	{
		printf("winner");
	}
	else(result==0){
		printf("draw");
	}
	
	player++;
	
	
}

void printboard()
{
	system("cls");
	
	printf("==== tic tac toe====\n\n");
	printf("       |       |       \n");
	printf("    %c  |  %c    |   %c    \n",board[1],board[2],board[3]);
	printf("_______|_______|_______\n");
	printf("       |       |       \n");
	printf("    %c  |  %c    |   %c    \n",board[4],board[5],board[6]);
	printf("_______|_______|_______\n");
	printf("       |       |       \n");
	printf("    %c  |  %c    |   %c    \n",board[7],board[8],board[9]);
}


int checkwin()
{
	if (board[1]==board[2] && board[2]==board[3])
	{
		return 1;
	}
		if (board[1]==board[4] && board[4]==board[7])
	{
		return 1;
	}
		if (board[7]==board[8] && board[8]==board[9])
	{
		return 1;
	}
		if (board[3]==board[6] && board[6]==board[9])
	{
		return 1;
	}
		if (board[1]==board[5] && board[5]==board[9])
	{
		return 1;
	}
		if (board[3]==board[5] && board[5]==board[7])
	{
		return 1;
	}
		if (board[2]==board[5] && board[5]==board[8])
	{
		return 1;
	}
		if (board[4]==board[5] && board[5]==board[6])
	{
		return 1;
	}
	
	int count=0;
	for(int i=1;i<=9;i++)
	{
		if(board[i]=='x' || board[i]=='o')
		{
			count ++;
		}
	}
	
	if(count==9)
	{
		return 0;
	}
	
	return -1;
}
