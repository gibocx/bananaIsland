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
        int array;
printf("\e[?25l");

        while(1){
	time_t   t = time(0);
	struct tm*   tm = localtime(&t);
        if(sec != tm->tm_sec)
        {
            sec = tm->tm_sec;
// compact this shit a lot

            array = tm->tm_hour / 10;
render(array,0);
            array = tm->tm_hour % 10;
render(array,1);
            array = tm->tm_min / 10;
render(array,2);
            array = tm->tm_min % 10;
render(array,3);
            array = tm->tm_sec / 10;
render(array,4);
            array = tm->tm_sec % 10;
render(array,5);
drawPoint();
fflush(stdout);
}
}
}
}
