#pragma once 
#include <QWidget>
#include "loginscreen.h"

namespace sessionutils {
    template<typename MenuType>
    void performSignOff(MenuType* currentMenu) { 
        LoginScreen* loginScreen = new LoginScreen();
        loginScreen->setAttribute(Qt::WA_DeleteOnClose);
        loginScreen->show();

        currentMenu->close();
    }
}