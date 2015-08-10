/*
CS 218 Homework 5 
Question 3 : Tiling
Name       : Dibyendu Mondal
Roll No.   : 130050046
*/

#include <simplecpp>

const int W=20, N=32;
int flag=1;

// W = tile width, N = number of tiles in each row and each column.

Color rColor() // random Color.
{  
  return COLOR(randuv(0,256), randuv(0,256), randuv(0,256));
}


void tile(int neXindex, int neYindex, int N, int holeX, int holeY)
{
  if(N==2)
   {
      Color c=rColor();
      if(flag==0)
        c=COLOR("White");
      if(holeX!=neXindex || holeY!=neYindex)
      {
        Rectangle r3(neXindex*W + W/2,neYindex*W + W/2,W,W);
        r3.setFill();
        r3.setColor(c);
        r3.imprint();
      }
      if(holeX!=neXindex || holeY!=neYindex+1)
      {
        Rectangle r1(neXindex*W + W/2,neYindex*W + 3*W/2,W,W);
        r1.setFill();
        r1.setColor(c);
        r1.imprint();
      }
      if(holeX!=neXindex+1 || holeY!=neYindex+1)
      {
        Rectangle r2(neXindex*W + 3*W/2,neYindex*W + 3*W/2,W,W);
        r2.setFill();
        r2.setColor(c);
        r2.imprint();
      }
      if(holeX!=neXindex+1 || holeY!=neYindex)
      {
        Rectangle r3(neXindex*W + 3*W/2,neYindex*W + W/2,W,W);
        r3.setFill();
        r3.setColor(c);
        r3.imprint();
      }
   } 
  else
  {
    if(neXindex<=holeX && holeX<neXindex+N/2 && neYindex<=holeY && holeY<neYindex+N/2)    //Bottom Left
    {
      tile(neXindex,neYindex,N/2,holeX,holeY);
      tile(neXindex,neYindex+N/2,N/2,neXindex-1+N/2,neYindex+N/2);
      tile(neXindex+N/2,neYindex+N/2,N/2,neXindex+N/2,neYindex+N/2);
      tile(neXindex+N/2,neYindex,N/2,neXindex+N/2,neYindex-1+N/2);
      flag=0;
      tile(neXindex-1+N/2,neYindex-1+N/2,2,neXindex-1+N/2,neYindex-1+N/2);
      flag=1;
    }
    else if(neXindex<=holeX && holeX<neXindex+N/2 && holeY>=neYindex+N/2 && holeY<neYindex+N) //Top Left
    {
      tile(neXindex,neYindex+N/2,N/2,holeX,holeY);
      tile(neXindex,neYindex,N/2,neXindex-1+N/2,neYindex-1+N/2);
      tile(neXindex+N/2,neYindex+N/2,N/2,neXindex+N/2,neYindex+N/2);
      tile(neXindex+N/2,neYindex,N/2,neXindex+N/2,neYindex-1+N/2);
      flag=0;
      tile(neXindex-1+N/2,neYindex-1+N/2,2,neXindex-1+N/2,neYindex+N/2);
      flag=1;
    }
    else if(holeX>=neXindex+N/2 && holeX<neXindex+N && holeY>=neYindex+N/2 && holeY<neYindex+N) //Top Right
    {
      tile(neXindex+N/2,neYindex+N/2,N/2,holeX,holeY);
      tile(neXindex,neYindex,N/2,neXindex-1+N/2,neYindex-1+N/2);
      tile(neXindex,neYindex+N/2,N/2,neXindex-1+N/2,neYindex+N/2);
      tile(neXindex+N/2,neYindex,N/2,neXindex+N/2,neYindex-1+N/2);
      flag=0;
      tile(neXindex-1+N/2,neYindex-1+N/2,2,neXindex+N/2,neYindex+N/2);
      flag=1;
    }
    else //if(holeX>=neXindex+N/2 && holeX<neXindex+N && neYindex<=holeY && holeY<neYindex+N/2) //Bottom Right
    {
      tile(neXindex+N/2,neYindex,N/2,holeX,holeY);
      tile(neXindex,neYindex,N/2,neXindex-1+N/2,neYindex-1+N/2);
      tile(neXindex,neYindex+N/2,N/2,neXindex-1+N/2,neYindex+N/2);
      tile(neXindex+N/2,neYindex+N/2,N/2,neXindex+N/2,neYindex+N/2);
      flag=0;
      tile(neXindex-1+N/2,neYindex-1+N/2,2,neXindex+N/2,neYindex-1+N/2);
      flag=1;
    }
  }
}


int main()
{

  initCanvas("Tiling",W*N,W*N);

  int clickPos = getClick();  // to fix square to leave untiled.

  int holeX = clickPos/65536/W, holeY =(clickPos % 65536)/W;

  Circle c(holeX*W + W/2, holeY*W + W/2, W/2);
  c.setFill();
  c.setColor(COLOR("red"));
  c.imprint();

  tile(0,0,N,holeX,holeY);
  Circle c1(holeX*W + W/2, holeY*W + W/2, W/2);
  c1.setFill();
  c1.setColor(COLOR("red"));
  c1.imprint();

  getClick();

}