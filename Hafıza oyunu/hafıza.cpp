#include<stdio.h>
#include<iostream>
#include <time.h>
using namespace std;

int yerlestir(int ar[4][4],int t,int *i,int *j)
{
	int k=0,l;
	int counter=0;
	for(k=0;k<4;k++)
	{
		for(l=0;l<4;l++)
		{
			if(t==ar[k][l])
				counter++;
		}
	}
	if(counter>=2)
	{return(0);}
	else
	{ar[*i][*j]=t;return (1);}
}
void rastgele(int arka[4][4])
{
	int tmm;
		int a;
 			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
				{
					do{
						a=(rand()%9)+48;
						tmm=yerlestir(arka,a,&i,&j);
						if(!(a>48&&a<57)){tmm=0;}
					  }while(!(tmm==1));
					tmm=0;
				}
		
}

void ekranayaz(char yldz[][4])
{
	cout<<endl<<endl<<endl<<endl;
			printf("%8d%5d%5d%5d\n-----------------------------\n",1,2,3,4,5);
			for(int i=0;i<4;i++)
				{
					printf("%d |",i+1);
					for(int j=0;j<4;j++)
						{
							printf("%5c",yldz[i][j]);
							if(j==3){printf("\n");}
						}	

			}
	cout<<"good luck=)\n\n";
}
					
void kordinat(int *cr1,int *cr2)
{
	do{
	cout<<"please enter coordinats (ex:2,3):\n\n";
	scanf("%d,%d",cr1,cr2);
	}while(!(((*cr1)+(*cr2))>0&&((*cr1)+(*cr2))<9));
}
void esle (char stars[][4],int asl[][4],int *bit)
{
	int deneme=0,kor1,kor2,kor3,kor4;
	do{
		deneme=0;
		kordinat(&kor1,&kor2);
		if(stars[kor1-1][kor2-1]!='*'){deneme=1;cout<<"same cordinats!!\n";}
	  }while(deneme!=0);
	stars[kor1-1][kor2-1]=(char)(asl[kor1-1][kor2-1]);
	system("\n\CLS");
	ekranayaz(stars);
	do{
		deneme=0;
		kordinat(&kor3,&kor4);
		if(stars[kor3-1][kor4-1]!='*'){deneme=1;cout<<"same cordinats!!\n";}
	}while(deneme!=0);
	stars[kor3-1][kor4-1]=asl[kor3-1][kor4-1];
	system("\n\nCLS");
	ekranayaz(stars);
	if(!(stars[kor1-1][kor2-1]==stars[kor3-1][kor4-1]))
	{
		stars[kor1-1][kor2-1]='*';
		stars[kor3-1][kor4-1]='*';
	}
	else
		(*bit)=(*bit)+2;
}

void menu(int *secim)
{
			cout<<"--------------MENU---------------\n\n1.Instructions\n2.Start game\n3.exit\n";
			cin>>*secim;
}
void ilkdeger(int arkpl[][4],char yil[][4])
{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				arkpl[i][j]=-1;
			}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				yil[i][j]='*';
			}
}


int main(void)
{
	system ("color 4F");
	srand ( time(NULL) );
	int secim,bitis=0;
	int arkaplan[4][4];
	char yildizlar[4][4];
	do{
		system("CLS");
		do{
		menu(&secim);
		}while(!(secim==1||secim==2||secim==3));
		if(secim==1)
			{cout<<"A common memory matching game played by young children is to start with a deck of cards that contain identical pairs. For example, given six cards in the deck, two might be labeled “1”, two might be labeled “2” and two might be labeled “3”. The cards are shuffled and placed face down on the table. The player then selects two cards that are face down, turns them face up, and if they match they are left face up. If the two cards do not match they are returned to their original position face down. The game continues in this fashion until all cards are face up.\n";
			system("pause");}
		else if(secim==2)
		{
			ilkdeger(arkaplan,yildizlar);
			rastgele(arkaplan);
			ekranayaz(yildizlar);
			do{
				esle(yildizlar,arkaplan,&bitis);
			  }while(!(bitis==16));
			cout<<"\n----------------congratulations----------------\n\n";
			system("pause");
			bitis=0;
		}
	}while(secim!=3);
	cout<<"\n----------------byby-------------\n\n\n"<<endl;
	return(0);
	system("pause");
}
