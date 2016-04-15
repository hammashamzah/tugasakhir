#ifndef BACKGROUNDMODELTUNINGDIALOG_H
#define BACKGROUNDMODELTUNINGDIALOG_H

#include <QDialog>

namespace Ui {
class BackgroundModelTuningDialog;
}

class BackgroundModelTuningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BackgroundModelTuningDialog(QWidget *parent = 0);
    ~BackgroundModelTuningDialog();

public slots:

    void on_slider_morp_element_size_1_valueChanged(int value);

    void on_slider_gaussian_size_1_valueChanged(int value);

    void on_slider_min_area_2_valueChanged(int value);

    void on_slider_max_area_2_valueChanged(int value);

    void on_slider_morp_element_size_2_valueChanged(int value);

    void on_slider_gaussian_size_2_valueChanged(int value);

    void on_pushButton_load_released();

    void on_slider_min_area_1_valueChanged(int value);

    void on_slider_max_area_1_valueChanged(int value);

    void on_slider_pixel_threshold_1_valueChanged(int value);

    void on_slider_transformed_threshold_1_valueChanged(int value);

    void on_slider_pixel_threshold_2_valueChanged(int value);

    void on_slider_transformed_threshold_2_valueChanged(int value);
private:
    Ui::BackgroundModelTuningDialog *ui;
    QVector<QVector<int> > parameters;
signals:
    void setValueParameter(QVector< QVector<int> >);


};

#endif // BACKGROUNDMODELTUNINGDIALOG_H
