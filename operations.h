#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int ar[4][4],s=0,max=2,flag=0,score=0;
int isfull()  //checks if matrix is full or not
{
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            if(!ar[i][j])
            return 0;
        }
    }
    return 1;
}
int gameover() //check if game is over or not
{
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<3;++j)
        {
            if(!ar[i][j] || !ar[i][j+1] || !ar[j+1][i] || ar[i][j]==ar[i][j+1] || ar[j][i]==ar[j+1][i])
            return 0; //if any adjacent elements are equal or any element is blank
        }
    }
    return 1;
}
void print()
{
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            if(ar[i][j])
            printf("%10d ",ar[i][j]);
            else printf("%10c ",'.');
        }
        printf("\n\n\n\n\n");
    }
    printf("SCORE = %d\n",score);
    if(max==2048)
    {
        printf("YOU WIN !! Press 1 to continue playing :) \n");
        char ch=getch();
        if(ch-'1')
    	exit(0);
	}
}
void generate(int flag) //generate number 2/4(at start only) at random position
{
    int i=rand()%4,j=rand()%4,k=rand()%2;
    if(!ar[i][j]) //unfilled
    {
        ar[i][j]=(k && !flag)?4:2;
		if(!flag)
		{
			flag=1;			//indicates 1 element has been filled
			generate(1);
		}
	}
	else
	generate(1); //if already filled, generate again :)
}
int shiftl()
{
    int i,j,k,flag=0;
    for(k=0;k<3;++k)  //limit= no of zeros
    {
        for(i=0;i<4;++i)
        {
            for(j=0;j<3;++j)
            {
                if(!ar[i][j]) //shifting all zeros to right
                {
                    if(ar[i][j+1])
                    flag=1;
                    ar[i][j]=ar[i][j+1];
                    ar[i][j+1]=0;
                }
            }
        }
    }
    for(i=0;i<4;++i)
    {
        for(j=0;j<3;++j)
        {
            if(ar[i][j] && ar[i][j]==ar[i][j+1])
            {
                ar[i][j]=2*ar[i][j+1];
                score+=ar[i][j];
                if(ar[i][j]>max)
                max=ar[i][j];
                for(k=j+1;k<3;++k)
                ar[i][k]=ar[i][k+1]; //left shift
                ar[i][3]=0;
                flag=1;
            }
        }
    }
   return flag;
}
int shiftr()
{
    int i,j,k,flag=0;
    for(k=0;k<3;++k)  //limit= no of zeros
    {
        for(i=0;i<4;++i)
        {
            for(j=3;j>=1;--j)
            {
                if(!ar[i][j])
                {
                    ar[i][j]=ar[i][j-1];
                    ar[i][j-1]=0;
                    if(ar[i][j-1])
                    flag=1;
                }
            }
        }
    }
    for(i=0;i<4;++i)
    {
        for(j=3;j>0;--j)
        {
            if(ar[i][j] && ar[i][j]==ar[i][j-1])
            {
                ar[i][j]=2*ar[i][j-1];
                score+=ar[i][j];
                for(k=j-1;k>0;--k)
                ar[i][k]=ar[i][k-1];
                ar[i][0]=0;
                flag=1;
            }
        }
    }
    return flag;
}
int shiftd()
{
    int i,j,k,flag=0;
    for(k=0;k<3;++k)  //limit= no of zeros
    {
        for(i=0;i<4;++i)
        {
            for(j=3;j>=1;--j)
            {
                if(!ar[j][i])
                {
                    ar[j][i]=ar[j-1][i];
                    ar[j-1][i]=0;
                    if(ar[j-1][i])
                    flag=1;
                }
            }
        }
    }
    for(i=0;i<4;++i)
    {
        for(j=3;j>0;--j)
        {
            if(ar[j][i] && ar[j][i]==ar[j-1][i])
            {
                ar[j][i]=2*ar[j-1][i];
                score+=ar[j][i];
                for(k=j-1;k>0;--k)
                ar[k][i]=ar[k-1][i];
                ar[0][i]=0;
                flag=1;
            }
        }
    }
    return flag;
}
int shiftu()
{
    int i,j,k,flag=0;
	for(k=0;k<3;++k)  //limit= no of zeros
    {
        for(i=0;i<4;++i)
        {
            for(j=0;j<3;++j)
            {
                if(!ar[j][i])
                {
                    if(ar[j+1][i])
                    flag=1;
                    ar[j][i]=ar[j+1][i];
                    ar[j+1][i]=0;
                }
            }
        }
    }
    for(i=0;i<4;++i)
    {
        for(j=0;j<3;++j)
        {
            if(ar[j][i] && ar[j][i]==ar[j+1][i])
            {
                ar[j][i]=2*ar[j+1][i];
                score+=ar[j][i];
                if(ar[j][i]>max)
                max=ar[j][i];
                for(k=j+1;k<3;++k)
                ar[k][i]=ar[k+1][i]; //up shift
                ar[3][i]=0;
                flag=1;
            }
        }
    }
    return flag;
}
