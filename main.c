#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char Tahta[3][3];
const char OYUNCU = 'X';
const char RAKIP = 'O';


void resetTahta();
void printTahta();
int bosKontrol();
void oyuncuMove();
void rakipMove();
char kazananKontrol();
void printKazanan(char);


int main()
{

  char kazanan = ' ';
  char tekrar = ' ';
 

   do{
    kazanan = ' ';
    tekrar = ' ';
    resetTahta();

    while(kazanan == ' ' && bosKontrol() != 0 ){
      printTahta();

      oyuncuMove();
      kazanan = kazananKontrol();
      if(kazanan != ' ' || bosKontrol() == 0){
        break;
      }

      rakipMove();
      kazanan = kazananKontrol();
      if(kazanan != ' ' || bosKontrol() == 0){
        break;
      }
    }

    printTahta();
    printKazanan(kazanan);

    printf("\nTekrar oynamak ister misin? (E/H): ");
    scanf("%c");
    scanf("%c", &tekrar);
    tekrar= toupper(tekrar);
  }while(tekrar == 'E');

  printf("Oynadigin icin tesekkurler!");

   return 0;
}


void resetTahta(){
  for(int i=0; i < 3; i++){
    
    for(int j = 0; j<3;j++){
      Tahta[i][j] = ' ';
    }
  }

}

void printTahta(){
   printf(" %c | %c | %c ", Tahta[0][0], Tahta[0][1], Tahta[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", Tahta[1][0], Tahta[1][1], Tahta[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", Tahta[2][0], Tahta[2][1], Tahta[2][2]);
   printf("\n");
}

int bosKontrol(){
  int bosAlan = 9;

  for(int i=0;i<3;i++){
    for(int j = 0;j<3;j++){
      if(Tahta[i][j] != ' ')
      {
        bosAlan--;
      }
    }
  }

  return bosAlan;

}

void oyuncuMove(){
  int x;
  int y;

  do{
    printf("Satir giriniz (1-3): ");
    scanf("%d", &x);
    x--;
    printf("Sutun giriniz (1-3): ");
    scanf("%d", &y);
    y--;

    if(Tahta[x][y] != ' ')
    {
      printf("Gecersiz hamle!\n");
    }
    else{
      Tahta[x][y] = OYUNCU;
      break;
    }
  }while(Tahta[x][y] != ' ');

}

void rakipMove(){
  srand(time(0));
  int x;
  int y;

  if(bosKontrol() > 0)
  {
    do
    {
      x= rand() % 3;
      y= rand() % 3;
    }while(Tahta[x][y] != ' ');
    Tahta[x][y] = RAKIP;
  }
  else{
    printKazanan(' ');
  }
}

char kazananKontrol(){

   for(int i = 0; i < 3; i++)
   {
      if(Tahta[0][i] == Tahta[1][i] && Tahta[0][i] == Tahta[2][i])
      {
         return Tahta[0][i];
      }
   }

   for(int i = 0; i < 3; i++)
   {
      if(Tahta[i][0] == Tahta[i][1] && Tahta[i][0] == Tahta[i][2])
      {
         return Tahta[i][0];
      }
   }
   
   if(Tahta[0][0] == Tahta[1][1] && Tahta[0][0] == Tahta[2][2])
   {
      return Tahta[0][0];
   }

   if(Tahta[0][2] == Tahta[1][1] && Tahta[0][2] == Tahta[2][0])
   {
      return Tahta[0][2];
   }



  return ' ';
}

void printKazanan(char kazanan){
if(kazanan == OYUNCU){
  printf("Kazandin!");
}
else if(kazanan = RAKIP)
{
  printf("Kaybettin!");
}
else{
  printf("Berabere!");
}
}
