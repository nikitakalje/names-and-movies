#include <iostream>

using namespace std;
void PrintNamesInOrder(string names[], int nNames);
void PrintNamesStartingWith(string names[], int nNames, char letter);
bool SameSpecies(struct Animal a, Animal b);
Animal Cheapest(string type, Animal a[], int size);

struct Animal
{
  string name;
  string gender;
  int age;
  double price;
  string animal;
};
class Movie
{
  public:
    string GetName();
    string GetRating();
    int GetAmount();
    Movie();
    Movie(string n, string r, double a);
    double MovieShowing(int n);
    Movie MergeMovie(Movie m);

    //Precondition: none
    //Postcondition: value of rating is set to r
    void SetRating(string r)
    {
      rating=r;
    }
    //Precondition: none
    //Postcondition: value of amount is set to a
    void SetAmount(double a)
    {
      amount=a;
    }
    //Precondition: none
    //Postcondition: value of name is set to n
    void SetName(string n)
    {
      name=n;
    }

  private:
    string name;
    string rating;
    double amount;
};

Movie::Movie() : name("n"), rating("G"), amount(0)
{
//  cout<<"I'm creating a new Movie with name: "<<name<<endl;
}

Movie::Movie(string n, string r, double a): name(n), rating(r), amount(a)
{
//  cout<<"I'm creating a new Movie with rating: "<< rating<<endl;
}
int main()
{
  string names[6]={"Tim", "Jill", "June", "Tony", "Tina", "Bob"};
  cout<<"Names: ";
  for(int i=0; i<6; i++)
  {
    cout<<names[i]<< " ";
  }
  cout<<endl;
  int num=6;
  PrintNamesInOrder(names,num);

  cout<<endl;

  Animal shelter[5]={{"Bob", "male", 2, 5.5, "Dog"}, {"Sally", "female", 1, 7.5, "Cat"},
  {"Jane", "female", 3, 4.5, "Dog"}, {"Polly", "female", 7, 10, "Cat"}, {"Joe", "male", 8, 3, "Cat"}};

  //cout<<"Animals: ";
  for(int i=0; i<5; i++)
  {

    for(int j=0; j<5; j++)
    {
      //cout<<shelter[i][j]<<" ";
    }
    //cout<<shelter[i]<< " ";
  }
  cout<<endl;
  Animal a = Cheapest("Dog", shelter, 5);
  cout<<"Cheapest animal: "<<a.name<<endl;

  if(SameSpecies(shelter[0], shelter[1]))
  {
    cout<<"Same species: Yes"<<endl;
  }
  else
  {
    cout<<"Same species: No"<<endl;
  }

  cout<<endl;

  Movie M1;
  Movie M2("Harry Potter", "PG", 1000);
  Movie M5("Percy Jackson", "G", 2500);
  Movie M3("Harry Potter", "R", 2500);


  cout<<"First Movie: "<<M2.GetName()<<" "<<M2.GetRating()<<" "<<M2.GetAmount()<<endl;
  cout<<"Second Movie: "<<M3.GetName()<<" "<<M3.GetRating()<<" "<<M3.GetAmount()<<endl;

  M1.SetName("Disney");

  M1.SetRating("G");
  M1.MovieShowing(5);
  cout<<M1.GetName()<<" "<<M1.GetRating()<<" "<<M1.GetAmount()<<endl;

  Movie M4=M2.MergeMovie(M3);

  cout<<"Merge Movies with Most restrictive setting, add amounts: ";

  cout<<M4.GetName()<<" "<<M4.GetRating()<<" "<<M4.GetAmount()<<endl;
  return 0;
}
void PrintNamesInOrder(string names[], int nNames)
{
      cout<<"Print names in order: "<<endl;
  for(int i=65; i<90; i++)
  {

    PrintNamesStartingWith(names, nNames, i);
  }

}
void PrintNamesStartingWith(string names[], int nNames, char letter)
{
  for(int i=0; i<nNames; i++)
  {
    if(names[i].at(0)==letter)
    {
      cout<<names[i]<<endl;
    }
  }
}

Animal Cheapest(string type, Animal a[], int size)
{
  Animal cheapest;

  //cheap=a[0];
  bool first=true;
  for(int i=0; i<size; i++)
  {

    if(first&&a[i].animal==type)
    {
      cheapest=a[i];

      first=false;
    }
    if(a[i].animal==type)
    {
      if(a[i].price<cheapest.price)
      {
        cheapest=a[i];
      }
    }
  }

  return cheapest;
}
//returns true if a and b are same species
bool SameSpecies(Animal a, Animal b)
{
  if(a.animal==b.animal)
  {
    return true;
  }
  else return false;
}
//Precondition: There has to be a name to return
//Postcondition: name of the Movie is returned
string Movie::GetName()
{
  return name;
}

//Precondition: There has to be a rating to return
//Postcondition: rating of the Movie is returned
string Movie::GetRating()
{
  return rating;
}

//Precondition: There has to be an amount to return
//Postcondition: amount of money for the Movie is returned
int Movie::GetAmount()
{
  return amount;
}

//Precondition: int for the amount of customers is passed in
//Postcondition: the amount of the total money earned based on customers is returned
double Movie::MovieShowing(int n)
{
  SetAmount(n*12);
  return GetAmount();
}

//Precondition: object for the specific movie is passed in
/*Postcondition: object is compared to other object and one object is returned
if names are same, then most restrictive rating is set and add amounts
if not then name is set to cannot combine
*/
Movie Movie::MergeMovie(Movie m)
{
  Movie mov;

  if(this->GetName()==m.GetName())
  {
    if(this->GetRating()=="G" || m.GetRating()=="G")
    {
      mov.SetRating("G");
    }
    else if(this->GetRating()=="PG" || m.GetRating()=="PG")
    {
      mov.SetRating("PG");
    }
    else if(this->GetRating()=="PG-13" || m.GetRating()=="PG-13")
    {
      mov.SetRating("PG-13");
    }
    if(this->GetRating()=="R" || m.GetRating()=="R")
    {
      mov.SetRating("R");
    }
    mov.SetName(m.GetName());
    mov.SetAmount(this->GetAmount()+m.GetAmount());
  }
  else
  {
    mov.SetName("Could not Combine");
  }
  return mov;
}
