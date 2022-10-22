#include <stdbool.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "clui.h"
using namespace std;
struct information{
	char user_name[100];
	char** Main;
	char** Show;
	int point;
	int bomb_number;
	int square_number;
	int flag_count;
};
struct leader{
	char name[100];
	int point;
};
information save[5];
information play[10];
leader lead[5];
int u=0,s=-1,show_save=0;
char name[100]="salam";
////////////////
void menu();
void new_game();
void dificulty();
void bomb_maker();
void print_field();
char bomb_check(int i ,int j);
bool f(int I,int J);
void around_check(int i,int j);
void flag(int i,int j);
void footage();
void show(int x,int y);
void comand();
void load_game();
void change_name();
void leader_board();
void win();
void initializer();
void point_calculator();
void print();
void leader_print();
void saver();
void delete_array();
void show_saved();
void change_name();
int find_number(char* a);
int main()
{   
	init_clui();
	clear_screen();
	change_color_rgb(0,247,255);
	cout<<"please enter a name :";
	cin.getline(name,100);
	//cout<<name;
	strcpy(play[u].user_name,name);
	reset_color();
	menu();
}
int find_number(char *a)
{
	int sum=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]<'0'&&a[i]>'9')return 0;
		else sum=sum*10+a[i]-'0';
	}
	return sum;
}
void menu()
{
	int o=0,k=0,f=0;
	clear_screen();
	if(show_save==1)
	{
		show_save=0;
		strcpy(play[u].user_name,name);
	}
	while(k!=1)
	{
		if(f>0){
		char x=getch();
		if(x=='w'||x=='W')o--;
		if(x=='s'||x=='S')o++;
		if(x==13)k=1;}
		reset_color();
		clear_screen();
		change_color_rgb(0,255,255);
		cout<<"choose your comand"<<endl;
		int row=get_window_rows();
		int col=get_window_cols();
		cursor_to_pos(row-3,0);
		for(int i=0;i<col;i++){
			printf("-");
   		}
   		cout<<endl<<"username : "<<play[u].user_name;
		cout<<endl<<"UP='w' DOWN='s' CHOOSE=Enter";	
   		restore_cursor();
   		cursor_to_pos(2,0);
		if(o%5==0){
		change_color_rgb(0,255,255);
		cout<<"NEW GAME"<<endl;
		change_color_rgb(0,100,100);
		cout<<"LOAD GAME"<<endl;
		cout<<"CHANGE NAME"<<endl;
		cout<<"LEADREBOARD"<<endl;
		cout<<"QUIT"<<endl;}
		if(o%5==1||o%5==-4){
			change_color_rgb(0,100,100);
			cout<<"NEW GAME"<<endl;
			change_color_rgb(0,255,255);
			cout<<"LOAD GAME"<<endl;
			change_color_rgb(0,100,100);
			cout<<"CHANGE NAME"<<endl;
			cout<<"LEADREBOARD"<<endl;
			cout<<"QUIT"<<endl;
		}
		if(o%5==2||o%5==-3){
			change_color_rgb(0,100,100);
			cout<<"NEW GAME"<<endl;
			cout<<"LOAD GAME"<<endl;
			change_color_rgb(0,255,255);
			cout<<"CHANGE NAME"<<endl;
			change_color_rgb(0,100,100);
			cout<<"LEADREBOARD"<<endl;
			cout<<"QUIT"<<endl;	
		}
		if(o%5==3||o%5==-2){
			change_color_rgb(0,100,100);
			cout<<"NEW GAME"<<endl;
			cout<<"LOAD GAME"<<endl;
			cout<<"CHANGE NAME"<<endl;
			change_color_rgb(0,255,255);
			cout<<"LEADREBOARD"<<endl;
			change_color_rgb(0,100,100);
			cout<<"QUIT"<<endl;
		}
		if(o%5==4||o%5==-1){
			change_color_rgb(0,100,100);
			cout<<"NEW GAME"<<endl;
			cout<<"LOAD GAME"<<endl;
			cout<<"CHANGE NAME"<<endl;
			cout<<"LEADREBOARD"<<endl;
			change_color_rgb(0,255,255);
			cout<<"QUIT"<<endl;	
		}
		f++;
	}
		if(o%5==0)new_game();
		if(o%5==1||o%5==-4)load_game();
		if(o%5==2||o%5==-3)change_name();
 		if(o%5==3||o%5==-2)leader_board();	
		if(o%5==4||o%5==-1)quit();
}
void dificulty()
{
	
	int q=0 ,k=0;
	while(k!=1)
	{
		clear_screen();
		change_color_rgb(255,0,230);
		cout<<"choose your dificulty"<<endl;
		int row=get_window_rows();
		int col=get_window_cols();
		cursor_to_pos(row-3,0);
		for(int i=0;i<col;i++){
			printf("-");
   		}
		cout<<endl<<"UP='w' DOWN='s' CHOOSE=Enter";	
   		restore_cursor();
   		cursor_to_pos(2,0);
		if(q%4==0)
		{
			change_color_rgb(0,255,44);
			cout<<"EASY"<<endl;
			change_color_rgb(0,110,4);
			cout<<"MEDIUM"<<endl;
			cout<<"HARD"<<endl;
			cout<<"OPTIONAL"<<endl;
		}
		if(q%4==1||q%4==-3)
		{
			change_color_rgb(0,110,4);
			cout<<"EASY"<<endl;
			change_color_rgb(0,255,44);
			cout<<"MEDIUM"<<endl;
			change_color_rgb(0,110,4);
			cout<<"HARD"<<endl;
			cout<<"OPTIONAL"<<endl;	
		}
		if(q%4==2||q%4==-2)
		{
			change_color_rgb(0,110,4);
			cout<<"EASY"<<endl;
			cout<<"MEDIUM"<<endl;
			change_color_rgb(0,255,44);
			cout<<"HARD"<<endl;
			change_color_rgb(0,110,4);
			cout<<"OPTIONAL"<<endl;
		}
		if(q%4==3||q%4==-1)
		{
			change_color_rgb(0,110,4);
			cout<<"EASY"<<endl;
			cout<<"MEDIUM"<<endl;
			cout<<"HARD"<<endl;
			change_color_rgb(0,255,44);
			cout<<"OPTIONAL"<<endl;
		}
		char x=getch();
		if(x=='w'||x=='W')q--;
		if(x=='s'||x=='S')q++;
		if(x==13)k=1;
	}
	if(q%4==0){play[u].bomb_number=4;play[u].square_number=5;}
	if(q%4==1||q%4==-3){play[u].bomb_number=28;play[u].square_number=12;}
	if(q%4==2||q%4==-2){play[u].bomb_number=96;play[u].square_number=20;}
	if(q%4==3||q%4==-1)
	{			
		while(1)
		{
			char S[4];
			char B[4];
			int s=0,b=0;
			clear_screen();
			change_color_rgb(0,255,44);
			cout<<"choose the number of square :";
			cin.getline(S,4);
			s=find_number(S);
			cout<<endl;
			cout<<"choose the number of bombs :";
			cin.getline(B,4);
			b=find_number(B);
			cout<<endl;
			if(s==0||b==0)
			{
				cout<<"enter valid number"<<endl;
				delay(500);
				continue;
			}
			else if(s<=20&s>=0&&b<=s*s&&b>0)
			{
				play[u].square_number=s;
				play[u].bomb_number=b;
				break;
			}
			else 
			{
				cout<<"enter valid number"<<endl;
				delay(500);
				continue;
			}			
		}	
	}	
}
void initializer()
{
	play[u].Main=new char*[play[u].square_number];
	play[u].Show=new char*[play[u].square_number];
	for(int i=0;i<play[u].square_number;i++)
	{
		play[u].Main[i]=new char[play[u].square_number];
		play[u].Show[i]=new char[play[u].square_number];
	}
	for(int i=0;i<play[u].square_number;i++)
	{
		for(int j=0;j<play[u].square_number;j++){
		play[u].Main[i][j]='0';
		play[u].Show[i][j]='X';}
	}
	bomb_maker();
	for(int i=0;i<play[u].square_number;i++)
	{
	
		for(int j=0;j<play[u].square_number;j++)
		{
			play[u].Main[i][j]=bomb_check(i,j);//calling bomb check to compelete the rest of play[u].Main array 
		}
	}		
	
	
}
void bomb_maker()//this function makes random bombs in play[u].Main array using srand()  
{
	srand(time(0));
	for(int i=play[u].bomb_number;i>0;)
	{
	 	int r=rand()%play[u].square_number;
	 	int c=rand()%play[u].square_number;
		if(play[u].Main[r][c]=='B')
	 	{
	 		continue;
	 	}
	 	else 
	 	{
	 		play[u].Main[r][c]='B';
	 		i--;
	 	}
	}
}
char bomb_check(int i,int j)//this function checks if there is any bomb near each square 
{
	int n=play[u].square_number;
	if(play[u].Main[i][j]=='B')
	{
		return 'B';
	}
	char z='0';
	if(i+1<n&&play[u].Main[i+1][j]=='B')
	z++;
	if(i+1<n&&j+1<n&&play[u].Main[i+1][j+1]=='B')
	z++;
	if(j+1<n&&play[u].Main[i][j+1]=='B')
	z++;
	if(i-1>=0&&j+1<n&&play[u].Main[i-1][j+1]=='B')
	z++;
	if(i-1>=0&&play[u].Main[i-1][j]=='B')
	z++;
	if(i-1>=0&&j-1>=0&&play[u].Main[i-1][j-1]=='B')
	z++;
	if(j-1>=0&&play[u].Main[i][j-1]=='B')
	z++;
	if(i+1<n&&j-1>=0&&play[u].Main[i+1][j-1]=='B')
	z++;
	return z;
}
void print_field()//prints the play[u].Show array each set
{
	clear_screen();
	reset_color();
	change_color_rgb(60,255,0);
	int row=get_window_rows();
	int col=get_window_cols();
	cursor_to_pos(row-3,0);
	for(int i=0;i<col;i++){
		printf("-");
   	}
   	cout<<endl;
   	cout<<"USER NAME:"<<play[u].user_name;
	cout<<endl<<"UP='w' DOWN='s' SHOW='space' FLAG='f' SAVE='o' LEAVE='q' ";	
   	restore_cursor();
   	cursor_to_pos(1,1);
	int n=play[u].square_number;
	for(int I=0;I<n;I++)
	{
		if(n>=10)
		{
			for(int J=0;J<n;J++)
			{ 
				change_color_rgb(255,0,200); 
				printf("%c ",play[u].Show[I][J]);
			}delay(20);
			printf("\n");
		}
		else {
		for(int J=0;J<n;J++)
		{ 
			change_color_rgb(255,0,200); 
			printf("%c ",play[u].Show[I][J]);
		}delay(60);
		printf("\n");
		}
    }
    reset_color();
    return;
}
void comand()
{
	int x=1,y=1,p=0;
	while(1){
		if(x>play[u].square_number*2)x=1;
		if(x<=0)x=2*play[u].square_number-1;
		if(y>play[u].square_number)y=1;
		if(y<=0)y=play[u].square_number;
		if(p==1)
		{
			clear_screen();
			print_field();
			p=0;
		}
		save_cursor();
		cursor_to_pos(y,x);
		char com=getch();
		if(com==32){show(y,x/2+1);p=1;}
		else if(com=='f'||com=='F'){flag(y-1,x/2);p=1;}
		else if(com=='o'||com=='O'){saver();menu();}
		else if(com=='q'||com=='Q'){delete_array();menu();}
		else if(com=='w'||com=='W')y=y-1;
		else if(com =='s'||com =='S')y=y+1;
		else if(com =='d'||com =='D')x=x+2;
		else if(com == 'a'||com =='A')x=x-2;
		else {
		int r=get_window_rows();
		int c=get_window_cols();
		cursor_to_pos(25,c+2);
		change_color_rgb(255,20,20);
		cout<<" enter valid command"<<endl;
		reset_color();
		delay(500);
		clear_screen();
		print_field();
		}
		cursor_to_pos(y,x);
		save_cursor();
		win();
    }
}
void flag(int a,int b)// this function puts flags or removes them from the screen 
{
	if(play[u].Show[a][b]=='F')
	{
		play[u].Show[a][b]='X';	
		play[u].flag_count--;
	}
	else if(play[u].Show[a][b]=='0'||play[u].Show[a][b]=='1'||play[u].Show[a][b]=='2'||play[u].Show[a][b]=='3'||play[u].Show[a][b]=='4'||play[u].Show[a][b]=='5'||play[u].Show[a][b]=='6')
	{
		clear_screen();
		change_color_rgb(225,10,10);
		play_beep();
		printf("you can't do this order \n");
		reset_color();
		delay(500);
		clear_screen();
		return;
	}
	else if(play[u].flag_count==play[u].bomb_number)
	{
		clear_screen();
		change_color_rgb(225,10,10);
		play_beep();
		printf("you can't do this order \n");
		reset_color();
		delay(500);
		clear_screen();
		return;
	}
	else 
	{
		play[u].Show[a][b]='F';
		play[u].flag_count++;
	}
	return;
}
bool f(int I,int J)//out of bond check
{
	int n=play[u].square_number;
	if(I>=0&&I<n&&J>=0&&J<n)
	{
		return true;
	}
	else 
	return false;
}
void win()
{
	int n=play[u].square_number;
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(play[u].Main[i][j]==play[u].Show[i][j])
			count++;
		}
	}
	if(count==n*n-play[u].bomb_number)
	{
		point_calculator();
		print_field();
		change_color_rgb(83,241,110);
		printf("congratulations you won if you want to play again press y else press any key to quit\n");
		char exit=getch();
	 	if(exit=='y'||exit=='Y')
		{
		    delete_array();
			menu();
		}
		else
		{
		change_color_rgb(0,222,255);
		printf("wish you the best\n ");
		delay(1000);
		quit();	
	}
  }
}
void around_check(int i,int j)//this function reveals the empty elements and elemnts near bombs which are near the chosen empty one
{
	
	if(play[u].Main[i][j]==play[u].Show[i][j])
	{
		return;
	}
	play[u].Show[i][j]='0';
    if(f(i+1,j)&&play[u].Main[i+1][j]=='0'&&play[u].Show[i+1][j]!='0')
    around_check(i+1,j);
    else if(f(i+1,j))
    play[u].Show[i+1][j]=play[u].Main[i+1][j];
    
    if(f(i-1,j)&&play[u].Main[i-1][j]=='0'&&play[u].Show[i-1][j]!='0')
    around_check(i-1,j);
    else if(f(i-1,j))
    play[u].Show[i-1][j]=play[u].Main[i-1][j];
    
    if(f(i+1,j+1)&&play[u].Main[i+1][j+1]=='0'&&play[u].Show[i+1][j+1]!='0')
    around_check(i+1,j+1);
    else if(f(i+1,j+1))
    play[u].Show[i+1][j+1]=play[u].Main[i+1][j+1];
    
    if(f(i,j+1)&&play[u].Main[i][j+1]=='0'&&play[u].Show[i][j+1]!='0')
    around_check(i,j+1);
    else if(f(i,j+1))
    play[u].Show[i][j+1]=play[u].Main[i][j+1];
    
    if(f(i-1,j+1)&&play[u].Main[i-1][j+1]=='0'&&play[u].Show[i-1][j+1]!='0')
    around_check(i-1,j+1);
    else if(f(i-1,j+1))
    play[u].Show[i-1][j+1]=play[u].Main[i-1][j+1];
    
    if(f(i-1,j-1)&&play[u].Main[i-1][j-1]=='0'&&play[u].Show[i-1][j-1]!='0')
    around_check(i-1,j-1);
    else if(f(i-1,j-1))
    play[u].Show[i-1][j-1]=play[u].Main[i-1][j-1];
    
    if(f(i,j-1)&&play[u].Main[i][j-1]=='0'&&play[u].Show[i][j-1]!='0')
    around_check(i,j-1);
    else if(f(i,j-1))
    play[u].Show[i][j-1]=play[u].Main[i][j-1];
    
    if(f(i+1,j-1)&&play[u].Main[i+1][j-1]=='0'&&play[u].Show[i+1][j-1]!='0')
    around_check(i+1,j-1);
    else if(f(i+1,j-1))
    play[u].Show[i+1][j-1]=play[u].Main[i+1][j-1];
	return; 
}
void show(int x,int y)//this function is responsible for S orders and its conditions
{                                                                               
       	int n=play[u].square_number;
		if(play[u].Show[x-1][y-1]!='X')//this if checks the chosen elemnt isn't shown or flaged yet
		{
			change_color_rgb(225,10,10);
			play_beep();
			clear_screen();
			printf("you can't do this order \n");
			reset_color();
			delay(500);
			clear_screen();
			return;
		}
		if(play[u].Main[x-1][y-1]=='B')// if the chosen element has bomb some lines will be play[u].Shown and then ask you if you want to play again  
		{
			clear_screen();
			change_color_rgb(255,25, 25);
			play_beep();
			play_beep();
		    for(int i=0;i<n;i++)
		    {
				for(int j=0;j<n;j++)
				{
					printf("%c ",play[u].Main[i][j]);
				}
				delay(40);
				printf("\n");
		    } 
			delay(500);
			printf("GAME OVER\nIf you want to play again press y else press any key to quit\n");
			reset_color();
			delete_array();
			char exit=getch();
			if(exit=='y'||exit=='Y')
			{
			     menu();
			}
			else
			{
				change_color_rgb(0,222,255);
				printf("wish you the best\n ");
				delay(1000);
				quit();	
			}
		}
			if(play[u].Main[x-1][y-1]=='0')
			{
				around_check(x-1,y-1);
			}
			else
				play[u].Show[x-1][y-1]=play[u].Main[x-1][y-1];
				return;	
}
void new_game()
{
	int i=0,k=0;
    for(;i<10;i++)
    {
    	if(strcmp(name,play[i].user_name)==0){
    	k=1;	
		break;}
	}
	if(k==1)u=i;
	else
	{
		for(int i=0;i<strlen(name);i++)
		{
			play[u].user_name[i]=name[i];
		}
	
   	}
	dificulty();
	initializer();
	print_field();
	comand();
}
void saver()
{
	s++;
	if(s>5)
    {
    	clear_screen();
    	change_color_rgb(255,10,10);
    	cout<<"you cant have more saved playground "<<endl;
    	delay(1000);
    	menu();
	}
	int n=play[u].square_number;
	save[s].Main=new char*[n];
	save[s].Show=new char*[n];
	for(int i=0;i<n;i++)
	{
		save[s].Main[i]=new char[n];
		save[s].Show[i]=new char[n];
	}
	clear_screen();
	for(int i=0;i<=strlen(play[u].user_name);i++)
	{
		save[s].user_name[i]=play[u].user_name[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			save[s].Main[i][j]=play[u].Main[i][j];
			save[s].Show[i][j]=play[u].Show[i][j];
        }
    }
	save[s].bomb_number=play[u].bomb_number;
	save[s].flag_count=play[u].flag_count;
	save[s].point=play[u].point;
	save[s].square_number=play[u].square_number;
	delete_array();
}
void delete_array()
{
		int n=play[u].square_number;
		for(int i=0;i<n;i++)
		{
			delete []play[u].Main[i];
			delete []play[u].Show[i];
		}
		delete [] play[u].Main;
		delete [] play[u].Show;
}
void point_calculator()
{  
    clear_screen();
	int n=play[u].square_number;
	int point=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(play[u].Show[i][j]!='X')point++;
		}
	}
	point=point*n*play[u].bomb_number;
	play[u].point=play[u].point+point;
	point=play[u].point;
	int i=0;
	for(i=0;i<5;i++)
	{
		if(point>=lead[i].point)
		{
			
			break;
		}
	}
	if(strcmp(lead[i].name,play[u].user_name)==0)
	{
		
		lead[i].point=point;
		return;
	}
	for(int j=3;j>=i;j--)
	{	
	    strcpy(lead[j+1].name,lead[j].name);
	    lead[j+1].point=lead[j].point;
    } 
	lead[i].point=point;  
	for(int k=0;k<=strlen(play[u].user_name);k++)
	{
		lead[i].name[k]=play[u].user_name[k];
	}
}
void load_game()
{
	clear_screen();
	//cout<<"11111"<<endl;
	show_saved();
	print_field();
	comand();
	
}
void show_saved()
{
	clear_screen();
	change_color_rgb(0,247,255);
	cout<<"   name   squarenumber"<<endl;
   	for(int i=0;i<5;i++)
   	{
   		cout<<i+1<<' ';
   		for(int j=0;j<strlen(save[i].user_name);j++)
   		{
   			cout<<save[i].user_name[j];
		}
		cout<<"  "<<save[i].square_number<<endl;
	}
	cout<<"enter the number of the user you want to continue"<<endl;
	cout<<"if you want to back to menu press 'm' "<<endl;
	char temp[5];
	temp[0]='\0';
	cin.getline(temp,5);
	if(temp[0]=='m'||temp[0]=='M')menu(); 
	int k=temp[0]-'0';
	for(int i=1;i<=5;i++)
	{
		if(k==i)
		{
			//delete_array();
	         show_save=1;	
			play[u].square_number=save[i-1].square_number;
			play[u].Main=new char*[play[u].square_number];
			play[u].Show=new char*[play[u].square_number];
			for(int f=0;f<play[u].square_number;f++)
			{
		 		play[u].Main[f]=new char[play[u].square_number];
				play[u].Show[f]=new char[play[u].square_number];
			}
			play[u].bomb_number=save[i-1].bomb_number;
			play[u].flag_count=save[i-1].flag_count;
			play[u].point=save[i-1].point;
			for(int o=0;o<strlen(save[i-1].user_name);o++)
			{
				play[u].user_name[o]=save[i-1].user_name[o];
			}
			for(int o=0;o<play[u].square_number;o++)
			{
				for(int j=0;j<play[u].square_number;j++)
				{
					play[u].Main[o][j]=save[i-1].Main[o][j];
					play[u].Show[o][j]=save[i-1].Show[o][j];
				}
			}
		 return;	
		}
	}
	
}
void leader_board()
{
	clear_screen();
	change_color_rgb(0,255,94);
	for(int i=0;i<5;i++)
	{
		cout<<i<<' '<<lead[i].name<<' '<<lead[i].point<<endl;
	}
	change_color_rgb(255,100,100);
	cout<<"press 'm' to continue"<<endl;
	while(1)
	{
		char m[5];
		cin.getline(m,5);
		if(m[0]=='m'||m[0]=='M')break;
	}
	menu();
}
void change_name()
{
	clear_screen();
	change_color_rgb(0,255,200);
	int i=0;
	change_color_rgb(0,255,200);
	while(play[i].user_name[0]!='\0')
	{
		cout<<play[i].user_name<<endl;
		i++;
	}
	cout<<"enter the name :";
	char temp[100];
	temp[0]='\0';
	cin.getline(temp,100);
	i=0;
	while(play[i].user_name[0]!='\0')
	{
		if(strcmp(temp,play[i].user_name)==0)
		{
			u=i;
			menu();
		}
		i++;
	}
	if(i>=9)
	{
		clear_screen();
		cout<<"you've got to be kiding me you can't have more players "<<endl;
		delay(1000);
		menu();
	}
	u++;
	strcpy(play[u].user_name,temp);
	strcpy(name,temp);
	menu();
}


























































