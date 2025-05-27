#include "patientmenu.h"
#include "sessionutils.h" 


PatientMenu::PatientMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose); // Ensure the menu is deleted when closed

}

void PatientMenu::on_signoffButton_clicked() {
	sessionutils::performSignOff(this); // Use the template function
}
