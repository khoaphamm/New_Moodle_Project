#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string username;
    std::string password;

    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    bool login(const std::string& username, const std::string& password);

    bool changePassword(const std::string& oldPassword, const std::string& newPassword);
};

#endif // USER_H