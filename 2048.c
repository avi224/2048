#include <time.h>
#include <stdio.h>
#include "operations.h"
#include <conio.h>
int main()
{
	srand(time(NULL));
    char ch;
	int t,flag=0;
    generate(0);
    print();
	while(1)
    {
        flag=0;
        if(gameover())
        break;
        ch=getch();
        t=isfull();
        switch(ch)
        {
            case 'w' : flag=shiftu();break;
            case 'a' : flag=shiftl();break;
            case 's' : flag=shiftd();break;
            case 'd' : flag=shiftr();
        }
        system("cls");
        if(!t && flag)
        generate(1);
        print();
    }
    printf("Game over  !! :)\n");
	return 0;
}
