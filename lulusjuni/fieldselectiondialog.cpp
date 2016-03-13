#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}
