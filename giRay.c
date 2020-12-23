#include <time.h>
#include <stdio.h>
//#include <termios.h>

//todo render each number independentply 

void render(int values[])
{
  int j,i,k,l,val,q,o;

for(o=0;o++<3;main(4,'\n'));
  for(j = 0;j < 5;j++){
    for(l = 0; l < 3;l++){

        for(o=0;o++<4;main(4,' '));
        for(k = 0;k < 6;k++){
            for(i = 0;i < 3; i++){

	    val = main(3,values[k]);

            for(q=0;q<3;q++){
            if(val & ((1 << 14) >> ((j*3)+i)))
            {main(4,'#');}else{main(4,' ');}
          }}

          if((k % 2) == 1)
          {
                for(o=0;o++<2;main(4,' '));

                if((j % 2) == 0)
                {
                    main(4,' ');
                }
                else
                {
                    if(k != 5)
                        main(4,'#');

                }
          }
      for(o=0;o++<2;main(4,' '));
    }
    main(4,'\n');
    }

  }
  for(o=0;o++<3;main(4,'\n'));
}

short val[] = {'{o',0x1749,0x73E7,0x72CF,0x5BC9,0x79CF,0X79EF,0x7292,0x7BEF,0x7BC9};

int main(int argc, char **argv)
{
       if(argc > 1)
       {
// pointer magic
          if(!(argc-3)){return val[(int)argv];}
          if(!(argc-4)){putchar(argv);return 0;}

       }
       else
       {
       int sec = -1;
        int array[6];

        while(1){
	time_t   t = time(0);
	struct tm*   tm = localtime(&t);
        if(sec != tm->tm_sec)
        {
            sec = tm->tm_sec;
// compact this shit a lot
            array[0] = tm->tm_hour / 10;
            array[1] = tm->tm_hour % 10;
            array[2] = tm->tm_min / 10;
            array[3] = tm->tm_min % 10;
            array[4] = tm->tm_sec / 10;
            array[5] = tm->tm_sec % 10;

            render(array);

        }
}
}
}
