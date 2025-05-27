#include "sessionutils.h"
#include <QWidget>

namespace sessionutils {
    void performSignOff(QWidget* widget) {
        if (widget) {
            widget->close();
        }
    }
}
