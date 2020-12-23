#include <stdio.h>
#include <time.h>
//#include <termios.h>

//todo render each number independentply

void drawPoint()
{
  for(int i=0;i++<2;){
    for(int j=0;j++<9;){
      if(!(j<=6 && j>3)){
      printf("\033[%i;%iH",8+j,26*i+1);
      main(4,'#');
      }
    }
  }
}

void render(const int value,const int offset)
{
  int row, line,q,pattern,thic,wide;
  printf("\033[6;%iH",(offset*12)+4+(offset/2)*2);

   pattern = main(3,value);
   for(row=0;row<6;row++)
   {
     for(thic=0;thic++<3;)
     {
        for(line=0;line++<3;)
        {
            for(wide=0;wide++<3;)
            {
               if(pattern & ((1 << 14) >> (row*3)+line-1))
               {main(4,'#');}else{main(4,' ');}
            }
       }

        printf("\033[%i;%iH",((row)*3)+6+thic,(offset*12)+4+(offset/2)*2);
     }
   }
}

short val[] = {'{o',0x1749,0x73E7,0x72CF,0x5BC9,0x79CF,0X79EF,0x7292,0x7BEF,0x7BC9};

int main(int argc, char **argv)
{
       if(argc > 1)
       {
// pointer magic
          if(!(argc-3)){return val[(int)argv];}
          if(!(argc-4)){printf("%c",argv);return 0;}

       }
       else
       {

  	int sec = -1;
        int i;
        printf("\e[?25l\033[0;0H");
        for(i=0;i++<(80*24);main(4,' '));

        while(1){
          time_t t = time(0);
          struct tm* tm = localtime(&t);
          int *p = &tm->tm_hour;

          if(sec != tm->tm_sec)
          {
             p=&tm->tm_hour;
             sec = tm->tm_sec;
             for(i=0;i++<3;p=p-1)
             {render(*p/10,(2*(i-1)));render(*p%10,(2*(i-1))+1);}
	     drawPoint();
	     fflush(stdout);
          }
       }
   }
}
