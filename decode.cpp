#include<conio.h>
#include<stdio.h>
#include<string>
#include<math.h>
#include<vector.h>
#include<fstream.h>
#include<algorithm>
#include<time.h>
using namespace std;
ifstream keyfile("key.txt");
char mat[6][4][4]={0},temp[4]={0},e[6][4][4]={0};
void encode();
void swapx();
void key()
{
  ifstream ifile("letterlist.txt");
  for (int x = 0 ; x <6; ++x)
      {
           for (int y = 0 ; y <4; ++y)
           {
               for (int z = 0 ; z <4; ++z)
               {
                   ifile >> noskipws >>mat[x][y][z];
                   e[x][y][z]=mat[x][y][z];
               }
           }
      }
ifile.close();
}
void swapx()
{
          for(int x=0; x<6; x++)
          {
                  for(int y=0; y<4; y++)
                  {                                 
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector=0;
                                           keyfile >> shiftvector;
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[shiftvector][y][z];
                                           e[shiftvector][y][z]=temp[z];
                                 }
                  }
          }
		
}
void swapy()
{
          for(int x=0; x<6; x++)
          {
                  for(int y=0; y<4; y++)
                  {
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector=0;
                                           keyfile >> shiftvector;                                           
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[x][shiftvector][z];
                                           e[x][shiftvector][z]=temp[z];
                                 }
                  }
          }
}          
void swapz()
{
          for(int x=0; x<6; x++)
          {       
                  for(int y=0; y<4; y++)
                  {
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector=0;
                                           keyfile >> shiftvector;
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[x][y][shiftvector];
                                           e[x][y][shiftvector]=temp[z];
                                 }
                  }
          }
}
void newlist()
{
  ofstream out("letterlist.txt");
  for (int x = 0 ; x <6; ++x)
      {
           for (int y = 0 ; y <4; ++y)
           {
               for (int z = 0 ; z <4; ++z)
               {
                   out << e[x][y][z];
               }
           }
      }
out.close();
}
int main()
{
int i=0,n=0,n1=0,n2=0;
key();
keyfile>>n;
for(i=0;i<n+1;i++)
{
swapx();
swapy();
swapz();
}
keyfile>>n1;
for(i=0;i<n1+1;i++)
{
swapx();
swapy();
swapz();
}
keyfile>>n2;
for(i=0;i<n2+1;i++)
{
swapx();
swapy();
swapz();
}
      cout<<"\n WELCOME TO THE RUBIX CRYPT!";
      ifstream is("ciphertext.txt");    
      char c;
      ofstream ofile("decodedtext.txt");
      while (is.get(c))         
      for (int x = 0 ; x <6; ++x)
              {
                  for (int y = 0 ; y <4; ++y)
                  {
                      for (int z = 0 ; z <4; ++z)
                      {
                          
                          if(e[x][y][z] == c)
                          {
                            ofile << noskipws << mat[x][y][z];
                          }
                      }
                  }
              }
      
      is.close();               
      ofile.close();
      keyfile.close();
      newlist();
      cout<<"\nThe Decoded text is saved in a file decodedtext.txt";              
      getch();
}     
