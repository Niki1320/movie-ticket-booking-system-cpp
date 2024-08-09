#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include<conio.h>
using namespace std;
int prices(int seatch,int numticket);
class Landingpage; 
class Movies;
class Theatres;
class Database;
static int normalseats[4]={100,120,87,120};
static int premiumseats[4]={30,40,40,35};
static int sofaseats[4]={6,7,12,10};
static void ticket_func(int, int, int, int, map<string, int>);
int option;

class Theatres;
class Movies{
  //shd be a friend of theatres
  
  string moviename;
  
  public:
  int moviechoice;
  string menu[7]={"Oppenheimer","Barbie","MI7","The Notebook","Charlie777","Hhb","Angry Birds"};
     Movies(){

     }
      
      
  friend string assignnames(Movies, int);
  void display(vector<string>result){
    for(auto it:result){
      cout<<it<<"\t";
  }
  cout<<endl;
  } 
  void moviedisplay();//Memberfunction outside class
  //void updatemovies() //we can add more movies using vec.push_back
  //void theatres_showing(vector<Theatres> &theatres_showing); //for displaying theatres playing that movie

};
string assignnames(Movies m1,int mch){
  return(m1.menu[mch]);
}
void Movies::moviedisplay(){
   
      vector<string>movielist{"1.Oppenheimer","2.Barbie","3.MI7","4.The Notebook","5.Charlie777","6.Hhb","7.Angry Birds"};
      int moviechoice;
      cout<<"Choose from the following list";
      for(auto it:movielist){  //Concept of auto iterator
          cout<<it<<endl;
      }
      cout<<endl;
      
}

// template <typename S>
    

class Theatres {

  //shd be a friend of movies
  vector<string> theatre {"1. Garuda Mall", "2. Vega City", "3. UB City", "4. Lulu Mall"};
  int theatreChoice;
  public:
    Theatres() {}
    //friend class Movies;
    friend class Database;
    // Theatres (int choice) {
    //   theatreChoice = choice;
    // }
  Theatres (int choice) : theatreChoice(choice) {};
    ostream& operator << (ostream &out)
    {
      for (auto i : theatre) {
        out << i << endl;
      }
      return out;
    }
    void theatreDisplay() {
      cout << "Select the number corresponding to the theatre of your choice: " << endl;
      //cout << theatre << endl;
      for(auto it:theatre) cout<<it<<"\t";
    }      
void display(vector<string>result){
    for(auto it:result){
      cout<<it<<"\t";
  }}
};
class Database{
    public:
    vector<string>theatrelist{"1. Garuda Mall","2. Vega City","3. UB City","4. Lulu Mall"};
    vector<vector<string>>theatre_menu{{"Barbie","Oppenheimer","Hhb","Angry Birds"},{"Oppenheimer","MI7","Barbie","Hhb"},{"Barbie","The Notebook","Hhb","MI7"},{"Oppenheimer","Barbie","MI7","Angry Birds"}};
     
  Database(){
    
  }
  friend vector<string>findmymovie(Database,string);
     

};
vector<string>findmymovie(Database db1,string movieindex){
  vector<string>availabletheatres;
  for(int i=0;i<db1.theatrelist.size();i++){
    for(int j=0;j<db1.theatre_menu[i].size();j++){
        if(db1.theatre_menu[i][j]==movieindex){
            availabletheatres.push_back(db1.theatrelist[i]);
        }
    }
  }
  return availabletheatres;
}
static void ticket_func(int numticket, map<string,int> seatmap, int seatch,int tch) {
    if(seatch==1) normalseats[tch-1]-=numticket;
    else if(seatch==2) premiumseats[tch-1]-=numticket;
    else if(seatch==3) sofaseats[tch-1]-=numticket;
}
class Finalticket:public Database,public Movies{

    public:
    Finalticket(){

    }
    void finalticket(int tch, int mch, int numticket, int seatch, map<string,int> seatmap) {
        Database db3;
        Movies m7;
        string way;
    cout<<option<<endl;
    if(option==1){
        way=menu[mch-1];
    }
    if(option==2){
        way=theatre_menu[tch-1][mch-1];
    }
    cout<<endl;
    cout<<"\t"<<"Thanks for booking with CineNinja"<<endl;
    cout<<endl;
    cout<<"Movie name: "<<way;
    
    cout<<endl;
    cout<<"Theatre : "<<theatrelist[tch-1]<<endl;
    cout<<endl;
    cout<<prices(seatch, numticket);
    cout<<endl;
    cout<<endl;
    


}


};

int prices(int seatch,int numticket){
    int finalprice;
    if(seatch==1){
        cout<<"Normal seats: "<<numticket<<" tickets"<<endl<<"Price: ";
        return 150*numticket;
    }
    else if(seatch==2){
        cout<<"Premium seats: "<<numticket<<" tickets"<<endl<<"Price: ";
        return 250*numticket;
    }
    else {
        cout<<"Sofa seats: "<<numticket<<" tickets"<<endl<<"Price: ";
        return 550*numticket;
    }
}

void booking_func(int tch, int mch) {
    static map<string,int> seatmap;   //static var
    int seatch, numticket;
    seatmap["1. Normal"]=normalseats[tch-1];
    seatmap["2. Premium"]=premiumseats[tch-1];
    seatmap["3. Sofa"]=sofaseats[tch-1];
    cout<<"Choose your seat type:"<<endl;
    for(auto it:seatmap) cout<<it.first<<"\t"<<it.second<<endl;
    cin>>seatch;
    cout<<"Enter number of tickets:";
    cin>>numticket;
    ticket_func(numticket, seatmap, seatch,tch);
    Finalticket ft1;
    ft1.finalticket(tch, mch, numticket, seatch, seatmap);
}



//void ticketbooker();
int pathfunction(int choice) {
  int tch, mch;
  Movies m1;
  if(choice==1){
    
        //for the constructor its useless
    m1.moviedisplay();
    cin >> mch;
        //index no corresponding to the movie
    //Movies m2 = Movies(mch);
    string moviename=assignnames(m1,mch-1);
    //cout<<moviename<<endl;
    //recieved the moviename
    Database db1;
    vector<string>result=findmymovie(db1,moviename);
    m1.display(result);
    cout<<"Enter your theatre choice:";
    cin >> tch;
  }
  else if (choice == 2) {
    Theatres t1;
    t1.theatreDisplay();
    cin >> tch;
    Database db2;
    vector<string> result = db2.theatre_menu[tch-1];
    t1.display(result);
    cout<<"Enter your movie choice:";
    cin >> mch;
    // Theatres t2 = Theatres(tch);
    // cout << "Movies available: " << endl;
    // m1.moviedisplay();
    // cin >> mch;
    // Movies m2 = Movies(mch);
  }
  booking_func(tch,mch);
}

int main(){
  int choice;
  
  cout<<"Hello Welcome to \"CineNinja\" the best for quick movie tickets"<<endl;
  cout<<endl;
  cout<<"How may I help you today"<<endl;
  cout<<"type 1 to choose a movie"<<endl<<"type 2 to select a theatre"<<endl;
  cin>>choice;
  option=choice;
  do{
  
  pathfunction(choice);
  cout<<"Hello Welcome to \"CineNinja\" the best for quick movie tickets"<<endl;
  cout<<endl;
  cout<<"How may I help you today"<<endl;
  cout<<"type 1 to choose a movie"<<endl<<"type 2 to select a theatre"<<endl;
  cin>>choice;
  }while(choice <=2);  
  
  return 0;
}