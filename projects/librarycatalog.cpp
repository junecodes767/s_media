#include <iostream>
#include<iomanip>
#include<ctime>
//library catalog system
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Book{
private:
    string title,author,genre;
    int isbn;
    int yop;
    bool as;
    
public:
//* default constructor
    Book(): title (""), author (""), genre (""),isbn(0),yop(0), as(true){

    }
    Book (string title, string author,string genre, int isbn, int yop, bool as){
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->isbn = isbn;
        this->yop = yop;
        this->as = as; 
    }
    
    //*setters
    void setTitle(string t){
        t=title;
    }

    void setAuthor(string a){
        a=author;
    }
    void setGenre(string g){
        g=genre;
    }

    void setIsbn(string i){
        i=isbn;
    }

    void setYop(int y){
        y=yop;
    }
    void setAs(bool a){
        a=as;
    }

//* getters

    string getTitle(){
    return title;
}
    string getAuthor(){
    return author;}

    string getGenre(){
    return genre;}

    int getIsbn(){
    return isbn;

    auto getYop(){
    return yop;}

    bool getAs(){
        return as;
    }

};

class Library{
    private:
    Book newBookInstance;
    vector <Book> book_catalog;
    
 
 
 public:
  void addBook(){
    auto& book= newBookInstance;
      cout<<"Enter book title:"<<endl;
      cin>>book.setTitle();
      
      cout<<"Enter book author:"<<endl;
      cin>>book.setAuthor();
      
      cout<<"Enter book genre:"<<endl;
      cin>>book.setGenre();
      
      cout<<"Enter book isbn:"<<endl;
      cin>>book.setIsbn();
      
      cout<<"Enter book year of publication YY:"<<endl;
      cin>> book.setYop();
      
      book.setAs()=true;
      
      book_catalog.push_back(book);
  }
  
  
  void removeBook(){
      
      int isbn;
      cout<<"Enter book isbn:";
      cin>>isbn;
      for(auto it=book_catalog.begin();it != book_catalog.end();){
          if(it->isbn==isbn){
              book_catalog.erase(it)
              
          }else{
              it++
          }
      }
    
      
  }
  void displayBook(){
       
      for(auto& books:book_catalog)
          cout<< book_catalog.getTitle()<<""<<(book_catalog.getAs()==true?"Available":"Not Available")<<endl;
      }
      
  
}

Book getBook(){
    string title,author;
    cout<<"Enter book name: "<<endl;
    cin>>title;
    
    cout<<"Enter book author:";
    cin<<author;
    auto target= find(book_catalog.begin(),book_catalog.end(),title,author);
    
    if (target!=book_catalog.end()){
        int index = distance(book_catalog.begin(),target));
        cout<<target;
        
    }
}

void borrowedBooks(){
    
     
    for(auto it=book_catalog.begin(); it!=book_catalog.end();){
          cout<< book_catalog[it]<<" ";
      }
}


void returnedBooks(){
    cout<<"Enter book name:";
    cin>> string name;
        auto target= find(book_catalog.begin(),book_catalog.end(),name);

    if (target!=book_catalog.end()){
        int index = distance(book_catalog.begin(),target));
        newBookInstance.setAs(false);
        
    }
}

};

class User{
    private:
    string name;
    int cardnumber;
    string borrowedBooks;
    

    User():name("")cardnumber(0);
    void setName(string n){
            name=n;


    }
    void setCardnumber(int c){
            cardnumber =c;
}
};


class libraryCatalog{
   User newUser;
   Library library;
   
   map <int,User>userLog;
   map <int,vector<Book>>borrowedBooks;
   void addUsers(){
       string name;
       int cardNumber;
       cout<<"Enter user name:"<<endl;
       cin>>newUser.setName(name);
       
       cout<<"Enter library card number:"<endl;
       cin>>newUser.setCardnumber(cardNumber);
       
       userLog[cardNumber] newUser;
       

   }
   //? come to this, figure out the whole book thing
   void User_borrowedBooks(const Book& book,int cardNumber){
       
            cout<<"Enter"

      auto userIt = userLog.find(cardNumber);
        if (userIt != userLog.end()) {
            //* User found, add the borrowed book to the corresponding vector
            borrowedBooks[cardNumber].push_back(book);
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "User with card number " << cardNumber << " not found." << endl;
       
        
        
    }
       
       
   void displayBookbyUser(){
        // Check if the user with the given card number exists
        auto userIt = userLog.find(cardNumber);
        if (userIt != userLog.end()) {
            // User found, display the borrowed books
            cout << "Books borrowed by " << userIt->second.getName() << " (Card Number: " << userIt->second.getCardnumber() << "):" << endl;

            // Check if the user has borrowed any books
            auto booksIt = borrowedBooks.find(cardNumber);
            if (booksIt != borrowedBooks.end()) {
                for (const auto& book : booksIt->second) {
                    // Display book information
                    // Assuming Book class has a member function to display book information
                    // Replace this with the actual implementation based on your Book class
                    displayBookInformation(book);
                }
            } else {
                cout << "No books borrowed." << endl;
            }
        } else {
            cout << "User with card number " << cardNumber << " not found." << endl;
        }
    }
    
    
    
};

int main() {
//library catalog
User user;
Library library;
bool running=true;
while(running){
    cout<<"Welcome to the Portmouth Library."<<endl<<"PLease choose your category; 1:User ,2:Book:";
        cin>> int option;
        
        if(option==1){
            cout<<"Choose number for corresponding action: 1 add user, 2: Update user borrowed books:"
            cin>> int choice;
            
            switch(choice){
                case 1:
                user.addUsers();
                break;
                
                case 2:
                user.User_borrowedBooks();
                break;
                default:
                cout<<"Follow instructions!";
              
            }
              running=false;
        }else if{
            cout<<"Choose number for corresponding action: 1 add book,2:remove book, 3:display books,4: borrowed books, 5: returned books.";
            cin>>int choice
            
            switch(choice){
                case 1:
                addBook();
                break;
                case 2:
                removeBook();
                break;
                case 3:
                displayBook();
                break;
                case 4:
                borrowedBooks();
                break;
                case 5:
                returnedBooks();
                break;
                default:
                cout<<"Follow instructions!";
                
            }
            running=false;
        }
    
    
    
}



    return 0;
}