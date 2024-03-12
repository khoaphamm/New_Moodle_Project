#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string username;
    std::string password;

    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    bool login(const std::string& username, const std::string& password) {
        // Implement login logic here
        return this->username == username && this->password == password;
    }

    void logout() {
        // Implement logout logic here
    }

    bool changePassword(const std::string& oldPassword, const std::string& newPassword) {
        // Implement password change logic here
        if (this->password == oldPassword) {
            this->password = newPassword;
            return true;
        }
        return false;
    }

    virtual void viewProfile() const;
};

#endif // USER_H