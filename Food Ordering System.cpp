#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>
#include<conio.h>
#include <windows.h>  //K. kaj ta ki ei headerer // 13th line e COORD er object declare korar jonno use kora hoise. COORD ekta structure, jar kaj holo console e kono ekta character er position nirdesh kora.

using namespace std;



COORD coord={0,0};//Global object.

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//default function ///K. kivabe korse kivabe // coord object er x & y te je value ta ashtese console er sei coordinate e cursor set kortese. value ta ashtese ei function orthat gotoxy function jekhane jekhane call kora hoise sekhan thekei. 167th line e dekho, orokom joto jaygay call kora hoise & je value gula send kora hoise sekhane sei point e cursor set hobe.
}

void clearLine(){
    printf("                                                                              ") ;
}



int resFlag;//what res will come first
float finalBill=0.00;
float Dw=0.00;


class reg{
    public:
        char name[50];
        char add[50];
};

class db{ //file save
    private:
        reg R1;// K. ekhane reg mane ki? //32th line e dekho reg ekta class creat kora hoise. ekhane oi class er object R1 declare kora hoise.
    protected:
        int flag;
    public:
        void form(void);//reg working
};

class mainMenu{
    protected:
        char choice;
        char resName;
    public:
        void show(void);
};

class foodMenu{
    private:
        float flag;
    protected:
        int choice;
        char choice2;
        int quantity;
    public:
        void setMenuFlag(int f){ //up float flag call
            this->flag = f;
        }
        int getMenuFlag(){
            return flag;
        }
        void bMenu(void);
        void lMenu(void);
        void dMenu(void);
};

class calculator{
    protected:
        float bill;
    public:
        float cash(float p, int am);
};

class receipt{
    public:
        void showReceipt(void);
};

class restaurant{ //food price show
    private:
        float bprice[5];
        float lprice[5];
        float dprice[5];
        float price;
    protected:
        char choice;
    public:
        void resList(void);
        void setBfPrice(float p1, float p2, float p3, float p4, float p5);
        void setLunchPrice(float p1, float p2, float p3, float p4, float p5);
        void setDinnerPrice(float p1, float p2, float p3, float p4, float p5);
        float getBfPrice(int p);
        float getLunchPrice(int p);
        float getDinnerPrice(int p);
};

class restaurant1: public restaurant{ //K. keno evabe inheritage koreso? // inheritance er feature use korte chaisilam but pore restarurant class er kajgula porer din likhsilam, lekhar shomoy vule gesilam je oigula inherit kora ase.
    public:
        void res1Menu(void);
};

class restaurant2: public restaurant{
    public:
        void res2Menu(void);
};









void db :: form(void){
    system("cls");
    int j=0,k=0;
    char Name[50],address[50];
    cout <<"\n.......................Enter your Name and Address please......................"<<endl<<endl;
    cout <<"                              press 'Esc' to quit..."<<endl<<endl<<endl;
    FILE *fp;
    fp=fopen("Dreg.txt","ab+");//K. keno likhso? kivabe kaj kore // ei program ta run korle Dreg.txt namer ekta text file create hoy dekhso? oi file e registration kora memberder data save hoy. fopen ekta default function, ei function ta use hoy file ta open korar jonno & ab+ use kora hoise age je data gula ase segular por ekhon je data pabe seta save houar jonno. fopen namer ekta image disi dekho, ab+ er poriborte r ki ki use kora jay & kontar kaj ki seta okhane lekha ase.
    fflush(stdin);
    cout <<"\nName: ";gets(Name);
    cout <<"\nAddress: ";gets(address);
    strupr(Name);//for capital letter
    strupr(address);
    while(fread(&R1,sizeof(R1),1,fp) == 1){ //checking reg name,1 yes,0 no// K. logic ta kivabe kaj korse // 135 namer image ta dekho.
    if(strcmp(Name,R1.name) == 0)j=1; //not find reg name then save newly// K. logic ta kivabe kaj korse // 131th line e je name input neoa hoise seta & file theke je name ta read korse seta compare kortese. strcmp er value 0 mane holo string 2 ta same, mane name 2 ta same. tokhon j er value ami 1 set korsi.
    if(strcmp(address,R1.add) == 0)k=1;// K. logic ta kivabe kaj korse // 132th line e je address input neoa hoise seta & file theke je name ta read korse seta compare kortese. strcmp er value 0 mane holo string 2 ta same, mane address 2 ta same. tokhon k er value ami 1 set korsi.
    }
    if(j==1&&k==1){// K. logic ta kivabe kaj korse // j & k er value 1 mane ki chilo? 136 & 137 line er comment dekho. input neoa name & address r file e paoa name & address same. same hole se age registered member, tokhon ei if er vetorer kaj hobe. same na hole 146 line er else er kaj hobe.
        Dw=10.00;
        cout <<"\n           Congratulations, Sir. You are already a registered member."<<endl;
        cout <<"\n                     You're getting 10% off on your meal."<<endl;
        cout <<"\n                         press any key to continue...";
        getch();
    }
    else{
        strcpy(R1.name,Name);// K. logic ta kivabe kaj korse // 131 line e input neoa name ta R1 er vtorer name e copy kora hoise.
        strcpy(R1.add,address);// K. logic ta kivabe kaj korse// 131 line e input neoa address ta R1 er vtorer address e copy kora hoise.
        fwrite(&R1,sizeof(R1),1,fp);// K. logic ta kivabe kaj korse // 147 r 148 line e copy kora name & address file e save kora hoise.
        fclose(fp);
        cout <<"\n\n                        Registration is done successfully." <<endl;
        cout <<"\n                           press any key to continue...";
        getch();
    }
    restaurant r;
    r.resList();
}

void mainMenu :: show(void){
    while (1){
        system("cls");
        char choice;
        cout <<"  ** Please select the meal that you would like to purchase **  "<<endl<<endl;
        cout <<"                         [A] Breakfast"<<endl<<endl;
        cout <<"                         [B] Lunch"<<endl<<endl;
        cout <<"                         [C] Dinner"<<endl<<endl;
        cout <<"                    press 'Esc' to quit..."<<endl<<endl<<endl;
        cout <<"                   Enter your choice here : ";
        choice = getche();

        if (choice == 27) { break ; }//esc ascii value
        else if (choice == 'A' || choice == 'a') { foodMenu f; f.bMenu(); break; }
        else if (choice == 'B' || choice == 'b') { foodMenu f; f.lMenu(); break; }
        else if (choice == 'C' || choice == 'c') { foodMenu f; f.dMenu(); break; }
        else { gotoxy(0, 14); cout <<"          !!!wrong input. press any key to try again!!!";}
        getche();
    }
}

float calculator :: cash(float p, int am){
    this->bill = (p-(p*(Dw/100)))*am;
    return bill;
}

void receipt :: showReceipt(){
    system("cls"); gotoxy(0, 7);
    cout <<"    your total bill is TK "<<finalBill<<". please pay at the counter."<<endl;
    cout <<"             thank you so much for visiting us."<<endl;
    cout <<"                   please do come again."; getche();
}

void foodMenu :: bMenu(){
    while(1){
        restaurant res;

        if(resFlag==1){ res.setBfPrice(15.0, 25.0, 20.0, 50.0, 30.0);}
        if(resFlag==2){ res.setBfPrice(18.0, 30.0, 25.0, 60.0, 35.0);}

        system("cls");
        cout <<"                        *  Breakfast Menu  *"<<endl<<endl;
        cout <<"  ** Please select the food that you would like to purchase **  "<<endl<<endl;
        cout <<"                   [1] Toast & Tea - TK "<<res.getBfPrice(0)<<endl;
        cout <<"                   [2] Egg-Muffin - TK "<<res.getBfPrice(1)<<endl;
        cout <<"                   [3] Ruti & Daal-Bhaji - TK "<<res.getBfPrice(2)<<endl;
        cout <<"                   [4] Alu-Porata - TK "<<res.getBfPrice(3)<<endl;
        cout <<"                   [5] Nan & Vaji - TK "<<res.getBfPrice(4)<<endl<<endl;
        cout <<"                       Enter your choice here: ";
        cin >> choice;
        cout <<"                   Enter the quantity you want: ";
        cin >> quantity;
        cout <<"           would you like to order anything else?  y/n";
        choice2 = getche();
        calculator calc;
        finalBill+=calc.cash(res.getBfPrice(choice-1), quantity);
        if(choice2=='y' || choice2=='Y'){ continue;}
        else { receipt r; r.showReceipt(); break; }
    }
}

void foodMenu :: lMenu(){
    while (1){
        restaurant res;

        if(resFlag==1){ res.setLunchPrice(130.0, 120.0, 95.0, 120.0, 100.0);}
        if(resFlag==2){ res.setLunchPrice(140.0, 125.0, 100.0, 130.0, 110.0);}

        system("cls");
        cout <<"                         *  Lunch Menu  * "<<endl<<endl;
        cout <<"  ** Please select the food that you would like to purchase **  "<<endl<<endl;
        cout <<"              [1] Fried-Rice & Chiken-Curry - TK "<<res.getLunchPrice(0)<<endl;
        cout <<"              [2] Fried-Rice & Beef-Curry- TK "<<res.getLunchPrice(1)<<endl;
        cout <<"              [3] Rice & Fish-Curry- TK "<<res.getLunchPrice(2)<<endl;
        cout <<"              [4] Biriani - TK "<<res.getLunchPrice(3)<<endl;
        cout <<"              [5] Teheri- TK "<<res.getLunchPrice(4)<<endl<<endl;
        cout <<"                  Enter your choice here: ";
        cin >> choice;
        cout <<"                   Enter the quantity you want: ";
        cin >> quantity;
        cout <<"           would you like to order anything else?  y/n";
        choice2 = getche();
        calculator calc;
        finalBill+=calc.cash(res.getLunchPrice(choice-1), quantity);// K. kivabe kaj hosse // je food item select kora hoise setar price & quantity calculator class er cash function e pathano hoitese calc.cash er maddhome. sekhane calculation hoye last final bill er sathe add hoitese finalVill+= er maddhome.
        if(choice2=='y' || choice2=='Y'){ continue;}
        else { receipt r; r.showReceipt(); break; }
    }
}

void foodMenu :: dMenu(){
    while (1){
        restaurant res;

        if(resFlag==1){ res.setDinnerPrice(250.0, 125.0, 150.0, 1200.0, 180.0);}
        if(resFlag==2){ res.setDinnerPrice(270.0, 140.0, 170.0, 1300.0, 200.0);}

        system("cls");
        cout <<"                         *  Dinner Menu  * "<<endl<<endl;
        cout <<"  ** Please select the food that you would like to purchase **  "<<endl<<endl;
        cout <<"                 [1] Set Menu(7 items) - TK "<<res.getDinnerPrice(0)<<endl;
        cout <<"                 [2] Spagetti - TK "<<res.getDinnerPrice(1)<<endl;
        cout <<"                 [3] Chicken-Burger - TK "<<res.getDinnerPrice(2)<<endl;
        cout <<"                 [4] Pizza - TK "<<res.getDinnerPrice(3)<<endl;
        cout <<"                 [5] Porata & Resula - TK "<<res.getDinnerPrice(4)<<endl<<endl;
        cout <<"                     Enter your choice here: ";
        cin >> choice;
        cout <<"                   Enter the quantity you want: ";
        cin >> quantity;
        cout <<"           would you like to order anything else?  y/n";
        choice2 = getche();
        calculator calc;
        finalBill+=calc.cash(res.getDinnerPrice(choice-1), quantity);
        if(choice2=='y' || choice2=='Y'){ continue;}
        else { receipt r; r.showReceipt(); break; }
    }
}

void restaurant :: resList(void){
    while (1){
        system("cls");

        cout <<"  ** Please select the restaurant of your choice **  "<<endl<<endl;
        cout <<"                    [1] MIRPUR-1"<<endl<<endl;
        cout <<"                    [2] MIRPUR-2"<<endl<<endl;
        cout <<"                press 'Esc' to quit..."<<endl<<endl<<endl;
        cout <<"               Enter your choice here: ";
        choice = getche();

        if (choice == 27) { break ; }
        else if (choice == '1') { restaurant1 r; r.res1Menu(); break; }
        else if (choice == '2') { restaurant2 r; r.res2Menu(); break; }
        else{ gotoxy(0, 9); cout <<"    !!!wrong input. press any key to try again!!!";}
        getche();
    }
}

void restaurant :: setBfPrice(float p1, float p2, float p3, float p4, float p5){
    this->bprice[0]=p1;
    this->bprice[1]=p2;
    this->bprice[2]=p3;
    this->bprice[3]=p4;
    this->bprice[4]=p5;
}

void restaurant :: setLunchPrice(float p1, float p2, float p3, float p4, float p5){
    this->lprice[0]=p1;
    this->lprice[1]=p2;
    this->lprice[2]=p3;
    this->lprice[3]=p4;
    this->lprice[4]=p5;
}

void restaurant :: setDinnerPrice(float p1, float p2, float p3, float p4, float p5){
    this->dprice[0]=p1;
    this->dprice[1]=p2;
    this->dprice[2]=p3;
    this->dprice[3]=p4;
    this->dprice[4]=p5;
}

float restaurant :: getBfPrice(int p){//array num serially
    this->price=bprice[p];
    return price;
}

float restaurant :: getLunchPrice(int p){
    return lprice[p];
}

float restaurant :: getDinnerPrice(int p){
    return dprice[p];
}

void restaurant1 :: res1Menu(void){
    while (1){
        resFlag = 1;
        system("cls");
        cout <<"               ** Welcome to MIRPUR-1 Restaurant **          "<<endl;
        mainMenu m;
        m.show(); break;// 2 restu menu same so work polymorphisome
    }
}

void restaurant2 :: res2Menu(void){
    while (1){
        resFlag = 2;
        system("cls");
        cout <<"               ** Welcome to MIRPUR-2 Restaurant **          "<<endl<<endl<<endl;
        mainMenu m;
        m.show(); break;
    }
}







main(){
    db obj;
    while(1){
        system("cls");
        char choice;
        cout<<"               ** Welcome to FOOD ORDERING SYSTEM **             "<<endl;
        cout <<"                    press any key to continue...";
        getche();
        obj.form();//K. ekhan theke run suru korse then koi kivabe jasse // 122 line form > 156 reslist in 276 > 288 res1Menu in 332 or 289 res2Menu in 342 > 338 show in 159 or 348 show in 159 > 172 bMenu in 192 or 173 lMenu in 220 or 174 dMenu in 248 > 214 or 242 or 270 cash in 180 then return to 214 or 242 or 270 > 216 or 244 272 showReceipt in 185 ||
        system("cls"); gotoxy(0, 9);
        cout <<"           Do you want to close FOOD ORDERING SYSTEM?  y/n";
        choice = getche();
        if(choice=='n' || choice=='N'){ continue;}
        else { break; }
    }
}
