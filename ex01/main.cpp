/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:22:29 by zchtaibi          #+#    #+#             */
/*   Updated: 2025/04/15 21:37:32 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Contact
{
    private:
        std::string firstName;  
        std::string lastName;  
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void setContact(const std::string& fName, const std::string& lName, const std::string& nName,
            const std::string& pNumber, const std::string& dSecret)
        {
            firstName = fName;
            lastName = lName;
            nickName = nName;
            phoneNumber = pNumber;
            darkestSecret = dSecret;
        }
        std::string getFirstName() const {return firstName;};
        std::string getLastName() const {return lastName;};
        std::string getNickName() const {return nickName;};
        std::string getPhoneNumber() const {return phoneNumber;};
        std::string getDarkestSecret() const {return darkestSecret;};
        void print()
        {
            std::cout << "the contact info: "<< std::endl;
            std::cout << "firstName: " << firstName << std::endl;
            std::cout << "lastName: " << lastName << std::endl;
            std::cout << "nickName: " << nickName << std::endl;
            std::cout << "phoneNumber: " << phoneNumber << std::endl;
            std::cout << "darkestSecret: " << darkestSecret << std::endl;
        }
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int     oldestIndex;
        int     count;
    public:
        PhoneBook () : oldestIndex(0), count(0) {}
        void addContact(const Contact& contact)
        {
            contacts[oldestIndex] = contact;
            oldestIndex = (oldestIndex + 1) % 8;
            if (count <= 8)
                count++;
        }
        void displayAllContacts()
        {
            std::cout << "|" << std::setw(10) << "Index" << "|";
            std::cout << std::setw(10) << "First Name" << "|";
            std::cout << std::setw(10) << "Last Name" << "|";
            std::cout << std::setw(10) << "Nickname" << std::endl;
            int i = -1;
            while (++i < count)
            {
                std::cout << i << "   ";
                std::cout << contacts[i].getFirstName() << "   ";
                std::cout << contacts[i].getLastName() << "   ";
                std::cout << contacts[i].getNickName() << std::endl;
            }
        }
        void displayContact(int index) const
        {
            if (index < 0 || index >= count)
            {
                std::cout << "Error: Index out of range!" << std::endl;
                return;
            }
            const Contact& contact = contacts[index];
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickName() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
        }
};

std::string getInput(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return (input);
}

int main()
{
    PhoneBook PhoneBook;

    std::cout << "welcome to My Awesome PhoneBook" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::string input;
        
        std::cin >> input;
        if (input == "ADD")
        {
            Contact newContact;
            std::string firstName = getInput("Enter firstName: ");  
            std::string lastName = getInput("Enter lastName: ");  
            std::string nickName = getInput("Enter nickName: ");
            std::string phoneNumber = getInput("Enter phoneNumber: ");
            std::string darkestSecret = getInput("Enter darkestSecret: ");
            newContact.setContact(firstName, lastName, nickName,
                phoneNumber, darkestSecret);
            PhoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (input == "SEARCH")
        {
            int i;
            PhoneBook.displayAllContacts();
            std::cout << "Enter index to display: ";
            std::cin >> i;
            PhoneBook.displayContact(i);
            std::cout << "Did you want somhing else?: ";
        }
        else if (input == "EXIT")
            break;
        else
            std::cout << "Please Use ADD, SEARCH or EXIT." << std::endl;
    }
	return (0);
}

// class Contact {
// private:
//     std::string firstName;
//     std::string lastName;
//     std::string nickname;
//     std::string phoneNumber;
//     std::string darkestSecret;

// public:
//     Contact() {}

//     void setContact(const std::string& first, const std::string& last, 
//                    const std::string& nick, const std::string& phone, 
//                    const std::string& secret) {
//         firstName = first;
//         lastName = last;
//         nickname = nick;
//         phoneNumber = phone;
//         darkestSecret = secret;
//     }

//     std::string getFirstName() const { return firstName; }
//     std::string getLastName() const { return lastName; }
//     std::string getNickname() const { return nickname; }
//     std::string getPhoneNumber() const { return phoneNumber; }
//     std::string getDarkestSecret() const { return darkestSecret; }

//     bool isEmpty() const {
//         return firstName.empty();
//     }
// };

// class PhoneBook {
// private:
//     Contact contacts[8];
//     int oldestIndex;
//     int count;

//     std::string formatField(const std::string& field) const {
//         if (field.length() <= 10)
//             return field;
//         return field.substr(0, 9) + ".";
//     }

// public:
//     PhoneBook() : oldestIndex(0), count(0) {}

//     void addContact(const Contact& contact) {
//         contacts[oldestIndex] = contact;
//         oldestIndex = (oldestIndex + 1) % 8;
//         if (count < 8)
//             count++;
//     }

//     void displayAllContacts() const {
//         std::cout << "|" << std::setw(10) << "Index" << "|";
//         std::cout << std::setw(10) << "First Name" << "|";
//         std::cout << std::setw(10) << "Last Name" << "|";
//         std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

//         for (int i = 0; i < count; i++) {
//             std::cout << "|" << std::setw(10) << i << "|";
//             std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
//             std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
//             std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << "|" << std::endl;
//         }
//     }

//     void displayContact(int index) const {
//         if (index < 0 || index >= count) {
//             std::cout << "Error: Index out of range!" << std::endl;
//             return;
//         }

//         const Contact& contact = contacts[index];
//         std::cout << "First Name: " << contact.getFirstName() << std::endl;
//         std::cout << "Last Name: " << contact.getLastName() << std::endl;
//         std::cout << "Nickname: " << contact.getNickname() << std::endl;
//         std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
//         std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
//     }

//     int getCount() const {
//         return count;
//     }
// };

// std::string getInput(const std::string& prompt) {
//     std::string input;
//     do {
//         std::cout << prompt;
//         std::getline(std::cin, input);
//         if (std::cin.eof())
//             exit(0);
//         if (input.empty())
//             std::cout << "Field cannot be empty. Try again." << std::endl;
//     } while (input.empty());
    
//     return input;
// }

// int main() {
//     PhoneBook phoneBook;
//     std::string command;

//     std::cout << "Welcome to the 80s AWESOME PHONEBOOK!" << std::endl;
//     std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

//     while (true) {
//         std::cout << "> ";
//         std::getline(std::cin, command);
        
//         if (std::cin.eof())
//             break;

//         if (command == "ADD") {
//             Contact newContact;
//             std::string firstName = getInput("Enter first name: ");
//             std::string lastName = getInput("Enter last name: ");
//             std::string nickname = getInput("Enter nickname: ");
//             std::string phoneNumber = getInput("Enter phone number: ");
//             std::string darkestSecret = getInput("Enter darkest secret: ");
            
//             newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
//             phoneBook.addContact(newContact);
//             std::cout << "Contact added successfully!" << std::endl;
//         }
//         else if (command == "SEARCH") {
//             if (phoneBook.getCount() == 0) {
//                 std::cout << "Phonebook is empty!" << std::endl;
//                 continue;
//             }
            
//             phoneBook.displayAllContacts();
            
//             std::cout << "Enter index to display: ";
//             std::string indexStr;
//             std::getline(std::cin, indexStr);
//             if (std::cin.eof())
//                 break;
                
//             // Convert string to integer and check for valid input
//             // try {
//             //     int index = std::stoi(indexStr);
//             //     phoneBook.displayContact(index);
//             // } catch (std::exception& e) {
//             //     std::cout << "Error: Invalid index!" << std::endl;
//             // }
//         }
//         else if (command == "EXIT") {
//             std::cout << "Goodbye! All your contacts are lost forever!" << std::endl;
//             break;
//         }
//         else {
//             std::cout << "Invalid command. Use ADD, SEARCH or EXIT." << std::endl;
//         }
//     }

//     return 0;
// }