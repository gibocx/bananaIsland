#include <stdio.h>
#include <time.h>

int getFunnyValue(int value)
{
            switch(value)
            {
            case 1:
              return 0x1749;
            case 2:
              return 0x73E7;
            case 3:
              return 0x72CF;
            case 4:
              return 0x5BC9;
            case 5:
              return 0x79CF;
            case 6:
              return 0x79EF;
            case 7:
              return 0x7292;
            case 8:
              return 0x7BEF;
            case 9:
              return 0x7BC9;
            case 0:
            default:
               return 0x7B6F;
            }
}

void render(int values[])
{

printf("\n\n\n");
  int i,k,l,val;
  for(int j = 0;j < 5;j++){
    for(l = 0; l < 3;l++){
        printf("  ");
        for(k = 0;k < 6;k++){
            for(i = 0;i < 3; i++){

            val = getFunnyValue(values[k]);

            if(val & ((1 << 14) >> ((j*3)+i)))
            {printf("###");}else{printf("   ");}
          }

          if((k % 2) == 1)
          {
                if((j % 2) == 0)
                {
                    printf("   ");
                }
                else
                {
                    if(k != 5)
                        printf("  #");
                }
          }
      printf("  ");
    }
    printf("\n");
    }

  }
  printf("\n\n\n");
}

int main(int argc, char *argv[])
{
printf("%p\n\n",&main);
//  int i;
//  for(i=1;i < argc;i++)
//  {
//    switch(argv[i])
//    {
//      case "time":
        time_t t = time(0);
        struct tm* tm= localtime(&t);
        int sec = -1;
        int array[6];

        while(1){
        t = time(0);
        tm = localtime(&t);
        if(sec != tm->tm_sec)
        {
            sec = tm->tm_sec;
            array[0] = tm->tm_hour / 10;
            array[1] = tm->tm_hour % 10;
            array[2] = tm->tm_min / 10;
            array[3] = tm->tm_min % 10;
            array[4] = tm->tm_sec / 10;
            array[5] = tm->tm_sec % 10;

            render(array);
        }

}
//    }
//  }

}





