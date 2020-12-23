#include <time.h>

int getFunnyValue(const int value)
{
  static short numbers[] = {'{o',0x1749,0x73E7,0x72CF,0x5BC9,0x79CF,0X79EF,0x7292,0x7BEF,0x7BC9};
//   *(&value) = *(&value) + 1;
   return numbers[value];
}

void print(char c)
{printf("%c",c);}

void render(int values[])
{
  int i,k,l,val,q,o;

for(o=0;o++<3;print('\n'));

  for(int j = 0;j < 5;j++){
    for(l = 0; l < 3;l++){
        for(o=0;o++<4;print(' '));
        for(k = 0;k < 6;k++){
            for(i = 0;i < 3; i++){

            val = getFunnyValue(values[k]);

            for(q=0;q<3;q++){
            if(val & ((1 << 14) >> ((j*3)+i)))
            {print('#');}else{print(' ');}
          }}

          if((k % 2) == 1)
          {
                for(o=0;o++<2;print(' '));

                if((j % 2) == 0)
                {
                    print(' ');
                }
                else
                {
                    if(k != 5)
                        print('#');
                }
          }
      for(o=0;o++<2;print(' '));
    }
    print('\n');
    }

  }
  for(o=0;o++<3;print('\n'));
}

int main(int argc, char *argv[])
{
//  int i;
//  for(i=1;i < argc;i++)
//  {
//    switch(argv[i])
//    {
//      case "time":
       // time_t t = time(0);
       // struct tm* tm= localtime(&t);
        int sec = -1;
        int array[6];

        while(1){
time_t   t = time(0);
struct tm*   tm = localtime(&t);
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
}

