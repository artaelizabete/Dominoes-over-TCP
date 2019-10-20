/**
 * @file    UsersManager.cpp
 * @author  Andrés Salinas Lima
 * @date    18/10/2019
 * @brief   Código de la clase UsersManager: Gestiona la lista de usuarios
 *          conectados y les permite registrarse e iniciar sesión.
 */


#include "UsersManager.h"


void UsersManager::addUser(int socketD) {
    User user(socketD);
    users.push_back(user);
}

void UsersManager::removeUser(int socketD) {
    for (auto user = users.begin(); user != users.end(); user++)
        if (user->getSocketDescriptor() == socketD) {
            users.erase(user);
            break;
        }
}

const User &UsersManager::getUser(int socketD) const {
    for (auto &user : users)
        if (user.getSocketDescriptor() == socketD)
            return user;

    return *new User(-1);
}