#include <bits/stdc++.h>

using namespace std;
#define MAX 20

int dictionary(char input[])
{
     fstream file;int flag=0;
     file.open("file.txt",ios::in);
     if (file.is_open()){
      string tp;
      while(getline(file, tp)){
         if(tp==input)
         {
             flag=1;
             break;
         }
      }
      file.close();
   } return flag;
}
void checker(char temp[])
{
    if(dictionary(temp))
             cout<<"\n"<<temp;
}
void suggestion1(char a[],int len)
{
    while(len<strlen(a)){
      for(int i=0;i<strlen(a)-len;i++)
    {    int index=0;
         char subarr[len+1];
        for(int j=i;j<=i+len;j++)
        {
          subarr[index]=a[j];
          index++;
        }
        subarr[index]='\0';
         checker(subarr);




    } len++;

} }

void suggestion2(char input[],int len)
{    char temp[20];
    char miss[]="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;miss[i]!='\0';i++)
    {
       for(int j=0;j<len;j++)
       {  strcpy(temp,input);
           for(int k=j+1;k<=len;k++)
           {
               temp[k]=input[k-1];
           }
           temp[j]=miss[i];
           temp[len+1]='\0';
           checker(temp);
       }
       strcpy(temp,input);
       temp[len]=miss[i];
       temp[len+1]='\0';
         checker(temp);
  }
}
void suggestion3(char input[],int len)
{    char temp[20];int flag=0;

    for(int i=0;i<len;i++)
    {    strcpy(temp,input);
         if(temp[i]=='j')
            temp[i]='z';
         else if(temp[i]=='z')
            temp[i]='j';
         else if(temp[i]=='k'||temp[i]=='s')
             temp[i]='c';
         else if(temp[i]=='c')
         {
             temp[i]='k';
                checker(temp);
             temp[i]='s';
                checker(temp);
                flag=1;
         }
         else if(temp[i]=='v')
               temp[i]='w';
         else if(temp[i]=='w')
            temp[i]='v';
         if(strcmp(temp,input)!=0&&flag==0)
         {
              checker(temp);
         }
         else
            continue;

    }
}


void suggestion4(string &str)
{
      sort(str.begin(), str.end());
      fstream file;
     file.open("file.txt",ios::in);
     if (file.is_open()){
      string tp;
      while(getline(file, tp)){
        if( str.length()==tp.length())
        {   string temp=tp;
            sort(temp.begin(), temp.end());
            if(str==temp)
               cout<<"\n"<<tp;
        }
      }
      file.close();
   }

}
int main()
{     char input[20],flag=0;
     cout<<"give input:";
     cin.getline(input,MAX);

     int check=dictionary(input);
   check ? cout<<"\ncorrect word":cout<<"\nspelling mistake";
   if(check==0)
   { cout<<"\n\n"<<"SUGGESTION FOR CORRECT WORD:";
    int  half_length=strlen(input)/2;
  suggestion1(input,1);
  suggestion2(input,strlen(input));
  suggestion3(input,strlen(input));
  string str="";
  for(int i=0;input[i]!='\0';i++)
  {
      str=str+input[i];
  }
   suggestion4(str);
   }

}
