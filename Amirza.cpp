#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

void Show_Main_Menu();
void Sign_Up();
void Entrance(int a);
void Login();
void Rank();
void Challenge();

int main()
{     
Show_Main_Menu();
return 0;
}

void Entrance(int a)
{
if (a == 1)
{
   Sign_Up();
   return;
}
else if (a == 2)
{
   Login();
   return ;
}
else if (a == 3)
{
   Rank();
   return;
}
else if (a == 4)
{
    Challenge();
}
else if (a == 5)
{
    exit(0);
}
else
{
    cout << "Please Enter The Correct Number !!"<<endl;
    Show_Main_Menu();
}
}

void Show_Main_Menu()
{
    cout << "Welcome to this game" << endl;
    cout << "****** Main Menu ******" << endl;
    cout << "1.Sign up" << endl;
    cout << "2.Login" << endl;
    cout << "3.Rank" << endl;
    cout << "4.Challange" << endl;
    cout << "5.Exit" << endl;
    int EntranceNum;
    cout << "Please Enter Your Choice : ";
    cin >> EntranceNum;
    Entrance(EntranceNum);
}

void Sign_Up()
{
    ifstream iuser("./user.txt");
    if (!iuser)
    {
        cout << "File Not Found !!!" << endl;
    }
    else
    {
    int n;
    iuser >> n;
    string Users[n][6];
    for (int i = 0;i<n;i++)
    {
        for(int j = 0;j<6;j++)
        {
           iuser >> Users[i][j] ;
        }
    }
    iuser.close();

    label:

    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Username : " ;
    string Name;
    cin >> Name;
    if (Name == "*")
      {
          Show_Main_Menu();
          return;
      }
      else
      {
    for (int i = 0;i<n;i++)
    {
        if (Users[i][0] == Name)
        {
            cout << "This Username Is Already Taken !!"<< endl;
            goto label;
        }
    }
    cout << "Please Enter Your Password : ";
    string Password;
    cin >> Password;

    ofstream ouser("./user.txt");

    ouser << n+1 << "\n";
    for (int i = 0 ; i < n;i++)
    {
        for (int j = 0 ; j < 6; j++)
        {
            ouser << Users[i][j] << "\t";
        }
        ouser << "\n";
    }
    ouser << Name << "\t" << Password << "\t" << "1" << "\t" << "0" << "\t" << "0" << "\t" << "0";
    ouser.close();
    cout << "Successfully Done !!" << endl;
    Show_Main_Menu();
    }
}}

void Login()
{
    ifstream iuser("./user.txt");
    if (!iuser)
    {
        cout << "File Not Found !!!" << endl;
    }
    else
    {
    int n;
    iuser >> n;
    string Users[n][6];
    for (int i = 0;i<n;i++)
    {
        for(int j = 0;j<6;j++)
        {
           iuser >> Users[i][j] ;
        }
    }
    iuser.close();

    label :
    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Username : " ;
    string Username ;
    cin >> Username ;
    if (Username == "*")
    {
        Show_Main_Menu();
        return;
    }
    else
    {
    int temp = -1;
    for (int i = 0;i<n;i++)
    {
        if (Users[i][0]==Username)
        {
            temp = i;
            break;
        }
    }
    if (temp == -1)
    {
        cout << "Your Username Not Found !!"<<endl;
        goto label;
    }
    label2 :
    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Password : ";
    string Password ;
    cin >> Password ;
    if (Password == "*")
    {
        Show_Main_Menu();
        return;
    }
    else
    {
    if (Password == Users[temp][1])
    {
         cout << "Your Password Is Correct";
    }
    else
    {
         cout << "Your Password Is Incorrect" << endl;
         goto label2;
    }
}
}
}
}

void Rank()
{
    ifstream iuser("./user.txt");
    if (!iuser)
    {
        cout << "File Not Found !!!" << endl;
    }
    else
    {
    int n;
    iuser >> n;
    string Users[n][6];
    for (int i = 0;i<n;i++)
    {
        for(int j = 0;j<6;j++)
        {
           iuser >> Users[i][j] ;
        }
    }
    iuser.close();

    int max = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        if (stoi(Users[i][2]) > max)
        {
           max = stoi(Users[i][2]);
        }
    }    
    int count = 1;
    for(int i = max ; i >= 0 ; i --)
    {
        for(int j = 0; j<n;j++)
        {
            if (stoi(Users[j][2])==i)
            {
                cout << count << " - " << Users[j][0] << "\tRank : " << Users[j][2]<< endl;
                count ++;
            }
        }
    }    
    cout << "Please Enter A Key To Main Menu" << endl;
    getch();
    Show_Main_Menu();
}

}

void Challenge()
{
    srand(time(0));
    int RandomNum = rand()%17+1;

    ifstream ilevels ("./levels.txt");
    string temp;

    for (int i = 0 ; i < RandomNum; i++)
    {
        getline(ilevels,temp);
    }

    string letters ;
    ilevels >> letters;
    int w1;
    ilevels >> w1;
    int w2;
    ilevels >> w2;
    int wordnum = w1 + w2;
    string words [wordnum];
    string wordAnswers [wordnum];
    for (int i = 0;i<wordnum;i++)
    {
        ilevels >> words[i];
    }
    string player1 , player2;
    int p1_Score = 0;
    int p2_Score = 0;
    cout << "Please Enter Player 1 Name : ";
    cin >> player1;
    cout << "Please Enter Player 2 Name : ";
    cin >> player2;
    cout << endl << endl;

    int count = 0;
    int wordans = 0;
    while(true)
    {
        cout << player1 << "  Score : " << p1_Score << "\t\t";
        cout << player2 << "  Score : " << p2_Score << endl;
        
        if (count % 2 == 0)
        {
            cout << "It's " << player1 << "'s Turn"<<endl;
            cout << "letters : " << letters << endl;
            cout << "----" << endl;
            for(int i = 0 ; i < wordans;i++)
            {
                cout << wordAnswers[i] << endl;
            }
            cout << "----" << endl;
            cout << "if you want go back to main menu enter * : "<<endl;
            cout << player1 << " enter word: ";
            string enter;
            cin >> enter ;
            if (enter == "*")
            {
                cout << player2 << " Won !! "<<endl;
                break;
            }
            else
            {
            for(int i = 0;i<wordnum;i++)
            {
                if (enter == words[i])
                {
                    cout << "Your Answer Is Correct !!" << endl;
                    wordAnswers[wordans] = words[i];
                    wordans ++;
                    p1_Score += words[i].size();
                    words[i] = "";
                    count ++;
                    break;
                }
                else if (enter == wordAnswers[i])
                {
                    cout << "This Word Is Already Used Please Try Again !!" <<endl;
                    break;
                }
                if (i == wordnum - 1)
                {
                    cout << "Your Answer Is Wrong !!" << endl;
                    count ++;
                }
            }
        }
        }
        else if (count % 2 == 1)
        {
            cout << "It's " << player2 << "'s Turn"<<endl;
            cout << "letters : " << letters << endl;
            cout << "----" << endl;
            for(int i = 0 ; i < wordans;i++)
            {
                cout << wordAnswers[i] << endl;
            }
            cout << "----" << endl;
            cout << "if you want go back to main menu enter * : "<<endl;
            cout << player2 << " enter word: ";
            string enter;
            cin >> enter ;
            if  (enter == "*")
            {
                cout << player1 << " Won !! "<<endl;
                break;
            }
            else
            {
            for(int i = 0;i<wordnum;i++)
            {
                if (enter == words[i])
                {
                    cout << "Your Answer Is Correct !!" << endl;
                    wordAnswers[wordans] = words[i];
                    wordans ++;
                    p2_Score += words[i].size();
                    words[i] = "";
                    count ++;
                    break;
                }
                else if (enter == wordAnswers[i])
                {
                    cout << "This Word Is Already Used Please Try Again !!" <<endl;
                    break;
                }
                if (i == wordnum - 1)
                {
                    cout << "Your Answer Is Wrong !!" << endl;
                    count ++;
                }
            }
        }
        }
        bool flag = false;
        for (int i = 0 ; i < wordnum ; i++)
        {
            if (words[i] != "")
            {
            flag = true;
            break;
            }
        }
        if (flag == false)
        {
            if (p1_Score > p2_Score)
            {
                cout << player1 << " Won !!"<<endl<<player1 << " : "<<p1_Score<<"\t"<<player2 << " : "<<p2_Score<<endl;
            }
            else if (p1_Score < p2_Score)
            {
                cout << player2 << " Won !!"<<endl<<player1 << " : "<<p1_Score<<"\t"<<player2 << " : "<<p2_Score<<endl;
            }
            else if (p1_Score == p2_Score)
            {
                cout << "Draw !!"<<endl<<player1 << " : "<<p1_Score<<"\t"<<player2 << " : "<<p2_Score<<endl;
            }
            break;
        }
    }
    count = 0;
    Show_Main_Menu();
}
