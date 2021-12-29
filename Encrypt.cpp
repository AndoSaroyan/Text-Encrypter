#include "Encrypt.h"

#include <iostream>
#include <vector>

void Cube::Start()
{
    std::cout<<"======= Welcome ======="<<std::endl;
    std::cout<<"Which Option Do You Want ?"<<std::endl;
    std::cout<<"1.Encrypt Text"<<std::endl;
    std::cout<<"2.Decrypt Text"<<std::endl;
    int choice = 0;
    std::cin >> choice;
    if(choice == 1) { Code();}
    else if(choice == 2) { Decode (); }
    else { std::cerr<<"Wrong Number Was Written !!!"<<std::endl; throw; }
}

void Cube::Code ()
{
    std::cout<<"Enter Your Text \n";
    std::vector <std::string> Arrtexts;
    std::string text;
    std::cin.get() ;
    std::getline(std::cin, text);

    while(text.length() % CubeLength != 0)
    {
        text.push_back(' ') ;
    }
    while(text.length())
    {    
        Arrtexts.push_back(text.substr(0,CubeLength));
        text.erase(0,CubeLength);
    }

    std::cout<<"\nYour Text Is: \n";

    for(int i =0;i<Arrtexts.size();++i)
    {     
        std::cout<<Arrtexts[i];
    }

    std::cout<<"\nYour Encrypted Text \n";

    std::vector <Cube> ArrCube;

    for(int i = 0;i < Arrtexts.size(); ++i)
    {
        ArrCube.push_back(Cube(Arrtexts[i],_MyKey));
    }

    for(int i = 0;i < ArrCube.size(); ++i)
    {
        ArrCube[i].Decrypt();
    }

    std::cout<<"\nKey Of The Text ==> ";
    for(int i = 0;i < Arrtexts.size(); ++i)
    {
    std::cout<< i+1<< _MyKey1;
    }
    
}


void Cube::Decode ()
{
    std::cout<<"Enter Your Key \n";
    std::vector <std::string> ArrKeys;
    std::string key;
    std::cin.get();    
    std::getline(std::cin,key); // Example of Key 1:R:L:!2:D:U:!
    while(true) 
    {
        if(key.find('!') < key.length())
        {
            break;

        } else {
            std::cout << "Invalid Key !!!" << std::endl ;
            std::cout << "Try Again:";
            std::cin >> key;
            continue ;
        }
    }

    for(int i = 0; i < key.length(); ++i)
    {   
        ArrKeys.push_back(key.substr(0, key.find("!") +1 ));
        key.erase(0, (key.find("!")+1));
    }

    std::cout<<"Enter Your Text \n";
    std::vector<std::string> Arrtexts;
    std::string text;
    std::getline(std::cin,text);

    for(int i = 0;i < text.length(); ++i)
    {    
        Arrtexts.push_back(text.substr(0, CubeLength));
        text.erase(0, CubeLength);
    }

    std::vector <Cube> ArrCube;
    for(int i=0;i<ArrKeys.size(); ++i)
    {
        ArrCube.push_back(Cube(Arrtexts[i], ArrKeys[i]));
    }

    std::cout<<"\nYour Decrypted Text Is \n";
    for(int i = 0;i < ArrCube.size(); ++i)
    {
        ArrCube[i].Decrypt();
    }

}


Cube::Cube (const std::string & Text, const std::string & Key)
{
    _Text = Text;
    _Key = Key;
}

void Cube::Print()
{
    for(int i = 0;i < 8; ++i)
    {
        std::cout << _Text[i];
    }   
}

void Cube::MoveUp()
{
   std::swap(_Text[0], _Text[1]);
   std::swap(_Text[6], _Text[5]);
   std::swap(_Text[0], _Text[6]);
   std::swap(_Text[2], _Text[7]);
   std::swap(_Text[3], _Text[4]);
   std::swap(_Text[2], _Text[4]);
}

void Cube::MoveDown()
{
   std::swap(_Text[0], _Text[1]);
   std::swap(_Text[5], _Text[6]);
   std::swap(_Text[1], _Text[5]);
   std::swap(_Text[2], _Text[7]);
   std::swap(_Text[3], _Text[7]);
   std::swap(_Text[7], _Text[4]);
}

void Cube::MoveLeft()
{
    std::swap(_Text[0], _Text[1]);
    std::swap(_Text[2], _Text[3]);
    std::swap(_Text[0], _Text[2]);
    std::swap(_Text[4], _Text[5]);
    std::swap(_Text[6], _Text[7]);
    std::swap(_Text[4], _Text[6]);
}

void Cube::MoveRight()
{
    std::swap(_Text[0], _Text[1]);
    std::swap(_Text[1], _Text[2]);
    std::swap(_Text[2], _Text[3]);
    std::swap(_Text[4], _Text[5]);
    std::swap(_Text[5], _Text[6]);
    std::swap(_Text[6], _Text[7]);
}

void Cube::Decrypt()
{  
    for(int i = 0;i < _Key.length(); ++i)
    { 

        switch (_Key[i])
            {
            case 'R':
                MoveRight();
                break;
            
            case 'L':
                MoveLeft();
                break;

            case 'U':
                MoveUp();
                break;

            case 'D':
                MoveDown();      
                break;

            default:
                break;
            }
    }  
       Print();
}

int main ()
{
    Cube obj;
    obj.Start();

}
