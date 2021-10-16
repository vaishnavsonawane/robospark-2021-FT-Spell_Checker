#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

void check_dict(string input)
{
    }

void suggestion1( unordered_set<string> dict,string input)
{
    char miss[]="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;miss[i]!='\0';i++)
    {
       string temp=input;
       temp=temp+miss[i];
        sort(temp.begin()+1,temp.end());
        for(auto it=dict.begin();it!=dict.end();it++)
        {   string check=*it;
            sort(check.begin()+1,check.end());
            if(temp==check)
                cout<<"\n"<<*it;
        }
    }

}
void suggestion2(unordered_set<string> dict,string input)
{
    for(int i=1;i<input.length();i++)
    {   string temp="";
        for(int j=0;j<i;j++)
        {
            temp=temp+input[j];
        }
        for(int j=i+1;j<input.length();j++)
        {
            temp=temp+input[j];
        }
        if(dict.find(temp)!=dict.end())
            cout<<"\n"<<temp;
    }
}
void suggestion3(unordered_set<string> dict,string input)
{
     for(int i=1;i<input.length();i++)
    {   string temp="";
        for(int j=0;j<i;j++)
        {
            temp=temp+input[j];
        }
        for(int j=i+1;j<input.length();j++)
        {
            temp=temp+input[j];
        }
        suggestion1(dict,temp);
}

}
void suggestion4(unordered_set<string> dict,string input)
{    char miss[]="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<input.length();i++)
    { string temp=input;
      for(int j=0;miss[j]!='\0';j++)
      {
          temp[i]=miss[j];
              if(dict.find(temp)!=dict.end())
                    cout<<"\n"<<temp;
      }

    }
}
void suggestion5(unordered_set<string> dict,string input)
{
    string temp=input;
    sort(temp.begin()+1,temp.end());
      for(auto it=dict.begin();it!=dict.end();it++)
        {   string check=*it;
            sort(check.begin()+1,check.end());
            if(temp==check)
                cout<<"\n"<<*it;
        }
}

int main()
{    char arr[20];int check=0;
     cout<<"give input:";
     cin.getline(arr,20);
      string input="";
      for(int i=0;arr[i]!='\0';i++)
      {
          input=input+arr[i];
      }
       unordered_set<string> dict;
      fstream file;
     file.open("file.txt",ios::in);
     if (file.is_open()){
      string tp;
      while(getline(file, tp)){
        dict.insert(tp);
      }
      file.close();
      }
      if(dict.find(input)==dict.end())
      {
          cout<<"spelling mistake";check=1;
      }else
      {
          cout<<"correct spelling";
      }
      if(check==1)
      {  cout<<"\nSUGGESTION FOR CORRECT WORD:";

           suggestion1(dict,input);
       suggestion2(dict,input);
       suggestion3(dict,input);
        suggestion4(dict,input);
        suggestion5(dict,input);

      }
}

