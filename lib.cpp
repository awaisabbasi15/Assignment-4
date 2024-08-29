
#include <iostream>
#include <string>

// Base Class: Item (Abstract)
class Item {
public:
    Item(int id, std::string title, bool availability) : id(id), title(title), availability(availability) {}
    virtual ~Item() {}

    // Pure Virtual Functions
    virtual void getItemDetails() = 0;
    virtual bool checkAvailability() = 0;
    virtual void checkOut() = 0;
    virtual void checkIn() = 0;

protected:
    int id;
    std::string title;
    bool availability;
};

// Derived Class: Book
class Book : public Item {
public:
    Book(int id, std::string title, std::string author, std::string ISBN, bool availability)
        : Item(id, title, availability), author(author), ISBN(ISBN) {}

    void getItemDetails() override {
        std::cout << "Book Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << ISBN << std::endl;
    }

    bool checkAvailability() override {
        return availability;
    }

    void checkOut() override {
        availability = false;
    }

    void checkIn() override {
        availability = true;
    }

private:
    std::string author;
    std::string ISBN;
};

// Derived Class: Journal
class Journal : public Item {
public:
    Journal(int id, std::string title, std::string publisher, int issueNumber, bool availability)
        : Item(id, title, availability), publisher(publisher), issueNumber(issueNumber) {}

    void getItemDetails() override {
        std::cout << "Journal Title: " << title << std::endl;
        std::cout << "Publisher: " << publisher << std::endl;
        std::cout << "Issue Number: " << issueNumber << std::endl;
    }

    bool checkAvailability() override {
        return availability;
    }

    void checkOut() override {
        availability = false;
    }

    void checkIn() override {
        availability = true;
    }

private:
    std::string publisher;
    int issueNumber;
};

// Class: Member
class Member {
public:
    Member(int id, std::string name, std::string contactInfo, int loanLimit)
        : id(id), name(name), contactInfo(contactInfo), loanLimit(loanLimit) {}

    void borrowItem(Item* item) {
        // Implement borrowing logic here
    }

    void returnItem(Item* item) {
        // Implement returning logic here
    }

    void getLoanHistory() {
        // Implement loan history logic here
    }

private:
    int id;
    std::string name;
    std::string contactInfo;
    int loanLimit;
};
```
Note that this code only provides the class structure and basic member functions. You'll need to implement the logic for borrowing, returning, and getting loan history in the `Member` class. Additionally, you may want to add more functionality and error handling as needed.