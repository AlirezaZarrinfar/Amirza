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
void Show_Internal_Menu();
void Entrance_Internal(int a);
void Edit_Profile();
void Wheel_Of_Luck();
void Continue_Game(bool IsContinue);
void Choose_Level(int User_level);
void Select_Level();

string name;
string password;
int level;
int coin;
int extraWords;
int chance;
int user_idx;

string help = "";
string helpword = "";
int helpsize = 0;
int counter = 0 ;
int idx = 0;

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
    string Name;
    bool flag1 = false;
    do {
    flag1 = false;
    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Username : " ;
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
            flag1 = true;
            break;
        }
    }}}
    while(flag1 == true);
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
    name = Name;
    password = Password; 
    coin = 0; 
    level = 1; 
    chance = 0; 
    extraWords = 0;
    user_idx = n;
    ouser.close();
    cout << "Successfully Done !!" << endl;
    Show_Internal_Menu();
    }
}

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
    bool flag1 = false;
    string Username ;
    int temp = -1;
    do
    {
    flag1 = false;
    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Username : " ;
    cin >> Username ;
    if (Username == "*")
    {
        Show_Main_Menu();
        return;
    }
    else
    {
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
        flag1 = true;
    }
    }}
    while (flag1 == true);
    bool flag2 = false;
    string Password ;
    do
    {
    flag2 = false;
    cout << "!! Enter * To Main Menu !!" << endl;
    cout << "Please Enter Your Password : ";
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
        name = Users[temp][0];
        password = Users[temp][1];
        level = stoi(Users[temp][2]);
        coin = stoi(Users[temp][3]);
        extraWords = stoi(Users[temp][4]);
        chance = stoi(Users[temp][5]);
        user_idx = temp;
        Show_Internal_Menu();
    }
    else
    {
         cout << "Your Password Is Incorrect" << endl;
         flag2 = true;
    }}}
    while (flag2 == true);
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

void Show_Internal_Menu()
{
    cout << "****** Internal Menu ******" << endl;
    cout << "1.Continue game" << endl;
    cout << "2.Choose level" << endl;
    cout << "3.Wheel of Luck" << endl;
    cout << "4.Edit profile" << endl;
    cout << "5.Logout" << endl;
    int EntranceNum;
    cout << "Please Enter Your Choice : ";
    cin >> EntranceNum;
    Entrance_Internal(EntranceNum);
}

void Entrance_Internal(int a)
{
if (a == 4)
{
    Edit_Profile();
    return;
}
else if (a == 3)
{
    Wheel_Of_Luck();
    return;
}
else if (a == 5)
{
    Show_Main_Menu();
    return;
}
else if (a == 1)
{
    Continue_Game(false);
    return;
}
else if (a == 2)
{
    Select_Level();
    return;
}
else
{
    cout << "Please Enter The Correct Number !!"<<endl;
    Show_Internal_Menu();
}
}

void Edit_Profile()
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
    bool flag1 = false; 
    bool flag2 = false;
    do
    {
    flag1 = false;
    cout << "Enter * To Internal Menu !!" << endl;
    cout << "Please Enter Your Password : ";
    string pass;
    string newusername;
    cin >> pass;
    if (pass == "*")
    {
        Show_Internal_Menu();
        return;
    }
    else
    {
    if (pass == password)
    {
        do
        {
        flag2 = false;
        cout << "Please Enter Your New Username : ";
        cin >> newusername;
        for (int i = 0 ; i < n ; i++)
        {
            if (newusername == Users[i][0])
            {
                cout << "This Username Is Already Used"<<endl;
                flag2 = true;
            }
        }
        }
        while(flag2 == true);
        Users[user_idx][0] = newusername;
        cout << "Please Enter Your New Password : ";
        cin >> Users[user_idx][1];
    ofstream ouser("./user.txt");
    ouser << n << "\n";
    for (int i = 0 ; i < n;i++)
    {
        for (int j = 0 ; j < 6; j++)
        {
            ouser << Users[i][j] << "\t";
        }
        ouser << "\n";
    }
    ouser.close();
    cout << "Successfully Done !!" <<endl;
    Show_Internal_Menu();
    return;
    }
    else
    {
        cout << "Your Password Is Wrong !!"<<endl;
        flag1 = true;
    }
    }}
    while(flag1 == true);
}}

void Wheel_Of_Luck()
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
    cout << endl << "Your Luck(s) Is/Are : " << chance<<endl;
    cout << "Enter * To Menu !!"<<endl;
    cout << "Enter 1 To Rotate The Wheel"<<endl;
    cout << "50 coins\n" << "70 coins\n" << "90 coins\n" << "110 coins\n" << "150 coins\n" << "220 coins\n";
    string enter ;
    cin >> enter;
    if (enter == "*")
    {
        Show_Internal_Menu();
        return;
    }
    else if (enter == "1")
    {
        if (chance > 0)
        {
        srand(time(0));
        int RandomNum = rand()%100+1;
        if (RandomNum > 0 && RandomNum <= 30)
        {
            coin += 50;
            cout << "You Won 50 Coins !!"<<endl;
        }
        else if (RandomNum > 30 && RandomNum <= 50)
        {
            coin += 70;
            cout << "You Won 70 Coins !!"<<endl;
        }
        else if (RandomNum > 50 && RandomNum <= 70)
        {
            coin += 90;
            cout << "You Won 90 Coins !!"<<endl;
        }
        else if (RandomNum > 70 && RandomNum <= 85)
        {
            coin += 110;
            cout << "You Won 110 Coins !!"<<endl;
        }
        else if (RandomNum > 85 && RandomNum <= 95)
        {
            coin += 150;
            cout << "You Won 150 Coins !!"<<endl;
        }
        else if (RandomNum > 95 && RandomNum <= 100)
        {
            coin += 220;
            cout << "You Won 220 Coins !!"<<endl;
        }
        chance -- ;
        Users[user_idx][3] = to_string(coin);
        Users[user_idx][5] = to_string(chance);

        ofstream ouser("./user.txt");
        ouser << n << "\n";
        for (int i = 0 ; i < n;i++)
        {
            for (int j = 0 ; j < 6; j++)
            {
            ouser << Users[i][j] << "\t";
            }
            ouser << "\n";
        }
        ouser.close();
        }
        else
        {
            cout << "You Dont Have Enough Chance !!"<< endl;
        }
        Show_Internal_Menu();
        return;
    }
    else
    {
        cout << "Please Enter A Correct Number"<<endl;
        Wheel_Of_Luck();
        return;
    }
}
}

void Continue_Game(bool IsContinue)
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
 string temp;
 ifstream ilevels ("./levels.txt");
 int Season;
 ilevels >> Season;
 int LevelNum[Season] ;
 for (int i = 0 ; i < Season ; i++)
 {
     ilevels >> LevelNum[i];
 }
 if (IsContinue == true)
 {
 for (int i = 0 ; i < Season ; i++)
 {
     if(level == LevelNum[i]+1)
     {
        chance ++;
        Users[user_idx][5] = to_string(chance);
        ofstream ouser("./user.txt");
        ouser << n << "\n";
        for (int i = 0 ; i < n;i++)
        {
            for (int j = 0 ; j < 6; j++)
            {
             ouser << Users[i][j] << "\t";
            }
            ouser << "\n";
        }
        ouser.close();
     }
 }
 }
    for (int i = 0 ; i < level; i++)
    {
        getline(ilevels,temp);
    }
    string letters ;
    ilevels >> letters;
    int NumMainWords;
    ilevels >> NumMainWords;
    int NumExtraWords;
    ilevels >> NumExtraWords;
    string Main_Words [NumMainWords];
    string MainWordsAns [NumMainWords];
    int MainWordAnsIdx = 0;
    string Extra_Words [NumExtraWords];
    string ExtraWordsAns [NumMainWords];
    int ExtraWordAnsIdx = 0;
    for (int i = 0;i<NumMainWords;i++)
    {
        ilevels >> Main_Words[i];
    }
    for (int i = 0;i<NumExtraWords;i++)
    {
        ilevels >> Extra_Words[i];
    }

    int leveltemp = level;
    int Seasons =0;
    for (int i = 0 ; leveltemp > 0;i ++)
    {
        leveltemp -= LevelNum[i];
        Seasons ++;
    }
    while(true)
    {
    if (extraWords == 6)
    {
        coin += 50 ;
        extraWords = 0;
    }
    cout << "Season : " 
    << Seasons 
    << "\t\t" 
    << "Level : " 
    << level 
    << "\t\t" 
    << "Coin : " 
    << coin 
    << "\t\t" 
    << "ExtraWords : "
    << extraWords << endl << endl;
    cout << letters << endl;
    cout << "-------"<<endl;
    for (int i = 0 ; i < MainWordAnsIdx;i++)
    {
        cout << MainWordsAns[i]<<endl;
    }
    cout << "-------"<<endl;
    cout << helpword;
    for (int i = 0;i < helpsize - counter ; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Enter Word : ";
    string enter;
    cin >> enter;
    if (enter == "*")
    {
        Users[user_idx][3] = to_string(coin);
        Users[user_idx][4] = to_string(extraWords);
        ofstream ouser("./user.txt");
        ouser << n << "\n";
        for (int i = 0 ; i < n;i++)
            {
                for (int j = 0 ; j < 6; j++)
                {
                ouser << Users[i][j] << "\t";
                }
            ouser << "\n";
            }
        ouser.close();
        Show_Internal_Menu();
        return;
    }
    else if (enter == "#")
    {
        if (coin < 80)
        {
            cout << "Your Coins Isn't Enough !"<<endl;
        }
        else
        {
        if (help == "")
        {
            for (int i = 0;i<NumMainWords;i++)
            {
                if (Main_Words[i] != "")
                {
                    idx = i;
                    help = Main_Words[i];
                    helpsize = help.size();
                    break;
                }
            }
        }
        helpword = helpword + help[counter];
        coin = coin - 80;
        counter ++;
        if (help == helpword)
        {
            help = "";
            helpword = "";
            helpsize = 0;
            counter = 0 ; 
            MainWordsAns[MainWordAnsIdx] = Main_Words[idx];
            MainWordAnsIdx ++;
            Main_Words[idx] = "";
            idx = 0;
        }

    }}
    else if (enter == "$")
    {
        int count =0;
        int lsize = letters.size();
        char arrletters[lsize] ;
        while(count < lsize)
        {
        srand(time(0));
        int RandomNum = rand() %  lsize;
        bool flag = false;
        for (int i = 0;i<count;i++)
        {
            if (arrletters[i] == letters[RandomNum])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
        arrletters[count] = letters[RandomNum];
        count ++;
        }}
        letters = arrletters;
    }
    else 
    {
        for (int i = 0 ;i<NumMainWords+NumExtraWords;i++)
        {
            if (enter == Main_Words[i])
            {
               if (enter == help)
               {
                    help = "";
                    helpword = "";
                    helpsize = 0;
                    counter = 0 ; 
                    idx = 0;  
               }
               MainWordsAns[MainWordAnsIdx] = Main_Words[i];
               MainWordAnsIdx ++;
               Main_Words[i] = "";
               cout << "Your Answer Is Correct"<< endl ;
               break;
            }
            else if (enter == Extra_Words[i])
            {
               ExtraWordsAns[ExtraWordAnsIdx] = Extra_Words[i];
               ExtraWordAnsIdx ++;
               Extra_Words[i] = "";
               cout << "Your Answer Is ExtraWord"<<endl ;
               extraWords++;
               break;
            }
            else if (enter == MainWordsAns[i])
            {
                cout << "Your Answer Is Already Found , Try Again !"<<endl;
                break;
            }
            else if (enter == ExtraWordsAns[i])
            {
                cout << "Your Answer Is Already Found In ExtraWords, Try Again !"<<endl;
                break;
            }
            if (i == NumMainWords+NumExtraWords - 1)
            {
                cout << "Your Answer Is Wrong !!" << endl;
            }
        }
        bool flag = false;
        for (int i = 0 ; i < NumMainWords ; i++)
        {
            if (Main_Words[i] != "")
            {
            flag = true;
            break;
            }
        }
        if (flag == false)
        {
            cout << "You Won !!"<<endl;
            level ++;
            coin = coin + 100;
            Users[user_idx][2] = to_string(level);
            Users[user_idx][3] = to_string(coin);
            Users[user_idx][4] = to_string(extraWords);
            ofstream ouser("./user.txt");
            ouser << n << "\n";
            for (int i = 0 ; i < n;i++)
            {
                for (int j = 0 ; j < 6; j++)
                {
                ouser << Users[i][j] << "\t";
                }
            ouser << "\n";
            }
            ouser.close();
            break;
        }
    }
    }
    Continue_Game(true);
}}

void Select_Level()
{
    cout << "Please Enter A Level : ";
    int levelselect ;
    cin >> levelselect;
    if (levelselect <= level && levelselect > 0)
    {
        Choose_Level(levelselect);
        return;
    }
    else
    {
        cout << "This Level Is Lock For You"<<endl;
        Select_Level();
    }
}

void Choose_Level(int User_level)
{
    if (User_level == level)
    {
        Continue_Game(false);
        return;
    }
    else
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


 string temp;
 ifstream ilevels ("./levels.txt");
 int Season;
 ilevels >> Season;
 int LevelNum[Season] ;
 for (int i = 0 ; i < Season ; i++)
 {
     ilevels >> LevelNum[i];
 }
    for (int i = 0 ; i < User_level; i++)
    {
        getline(ilevels,temp);
    }
    string letters ;
    ilevels >> letters;
    int NumMainWords;
    ilevels >> NumMainWords;
    int NumExtraWords;
    ilevels >> NumExtraWords;
    string Main_Words [NumMainWords];
    string MainWordsAns [NumMainWords];
    int MainWordAnsIdx = 0;
    string Extra_Words [NumExtraWords];
    string ExtraWordsAns [NumMainWords];
    int ExtraWordAnsIdx = 0;
    for (int i = 0;i<NumMainWords;i++)
    {
        ilevels >> Main_Words[i];
    }
    for (int i = 0;i<NumExtraWords;i++)
    {
        ilevels >> Extra_Words[i];
    }

    int leveltemp = User_level;
    int Seasons =0;
    for (int i = 0 ; leveltemp > 0;i ++)
    {
        leveltemp -= LevelNum[i];
        Seasons ++;
    }
    while(true)
    {
    cout << "Season : " 
    << Seasons 
    << "\t\t" 
    << "Level : " 
    << User_level
    << "\t\t" 
    << "Coin : " 
    << coin 
    << "\t\t" 
    << "ExtraWords : "
    << extraWords << endl << endl;
    cout << letters << endl;
    cout << "-------"<<endl;
    for (int i = 0 ; i < MainWordAnsIdx;i++)
    {
        cout << MainWordsAns[i]<<endl;
    }
    cout << "-------"<<endl;
    cout << helpword;
    for (int i = 0;i < helpsize - counter ; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Enter Word : ";
    string enter;
    cin >> enter;
    if (enter == "*")
    {
        Users[user_idx][3] = to_string(coin);
        ofstream ouser("./user.txt");
        ouser << n << "\n";
        for (int i = 0 ; i < n;i++)
            {
                for (int j = 0 ; j < 6; j++)
                {
                ouser << Users[i][j] << "\t";
                }
            ouser << "\n";
            }
        ouser.close();
        Show_Internal_Menu();
        return;
    }
    else if (enter == "#")
    {
        if (coin < 80)
        {
            cout << "Your Coins Isn't Enough !"<<endl;
        }
        else
        {
        if (help == "")
        {
            for (int i = 0;i<NumMainWords;i++)
            {
                if (Main_Words[i] != "")
                {
                    idx = i;
                    help = Main_Words[i];
                    helpsize = help.size();
                    break;
                }
            }
        }
        helpword = helpword + help[counter];
        coin = coin - 80;
        counter ++;
        if (help == helpword)
        {
            help = "";
            helpword = "";
            helpsize = 0;
            counter = 0 ; 
            MainWordsAns[MainWordAnsIdx] = Main_Words[idx];
            MainWordAnsIdx ++;
            Main_Words[idx] = "";
            idx = 0;
        }

    }}
    else if (enter == "$")
    {
        int count =0;
        int lsize = letters.size();
        char arrletters[lsize] ;
        while(count < lsize)
        {
        srand(time(0));
        int RandomNum = rand() %  lsize;
        bool flag = false;
        for (int i = 0;i<count;i++)
        {
            if (arrletters[i] == letters[RandomNum])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
        arrletters[count] = letters[RandomNum];
        count ++;
        }}
        letters = arrletters;
    }
    else 
    {
        for (int i = 0 ;i<NumMainWords+NumExtraWords;i++)
        {
            if (enter == Main_Words[i])
            {
               if (enter == help)
               {
                    help = "";
                    helpword = "";
                    helpsize = 0;
                    counter = 0 ; 
                    idx = 0;  
               }
               MainWordsAns[MainWordAnsIdx] = Main_Words[i];
               MainWordAnsIdx ++;
               Main_Words[i] = "";
               cout << "Your Answer Is Correct"<< endl ;
               break;
            }
            else if (enter == Extra_Words[i])
            {
               ExtraWordsAns[ExtraWordAnsIdx] = Extra_Words[i];
               ExtraWordAnsIdx ++;
               Extra_Words[i] = "";
               cout << "Your Answer Is ExtraWord"<<endl ;
               break;
            }
            else if (enter == MainWordsAns[i])
            {
                cout << "Your Answer Is Already Found , Try Again !"<<endl;
                break;
            }
            else if (enter == ExtraWordsAns[i])
            {
                cout << "Your Answer Is Already Found In ExtraWords, Try Again !"<<endl;
                break;
            }
            if (i == NumMainWords+NumExtraWords - 1)
            {
                cout << "Your Answer Is Wrong !!" << endl;
            }
        }
        bool flag = false;
        for (int i = 0 ; i < NumMainWords ; i++)
        {
            if (Main_Words[i] != "")
            {
            flag = true;
            break;
            }
        }
        if (flag == false)
        {
            cout << "You Won !!"<<endl;
            Users[user_idx][3] = to_string(coin);
            ofstream ouser("./user.txt");
            ouser << n << "\n";
            for (int i = 0 ; i < n;i++)
            {
                for (int j = 0 ; j < 6; j++)
                {
                ouser << Users[i][j] << "\t";
                }
            ouser << "\n";
            }
            ouser.close();
            break;
        }
    }
    }
    Choose_Level(++User_level);
}}}
