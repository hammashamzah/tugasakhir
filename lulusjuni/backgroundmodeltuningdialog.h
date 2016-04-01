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

    void on_slider_min_area_3_valueChanged(int value);

    void on_slider_max_area_3_valueChanged(int value);

    void on_slider_morp_element_size_3_valueChanged(int value);

    void on_slider_gaussian_size_3_valueChanged(int value);

    void on_pushButton_load_released();

    void on_slider_min_area_1_valueChanged(int value);

    void on_slider_max_area_1_valueChanged(int value);

private:
    Ui::BackgroundModelTuningDialog *ui;

signals:
	void valueMinArea_1(const int &value);
	void valueMinArea_2(const int &value);
	void valueMinArea_3(const int &value);
	void valueMaxArea_1(const int &value);
	void valueMaxArea_2(const int &value);
	void valueMaxArea_3(const int &value);
	void valueMorpElementSize_1(const int &value);
	void valueMorpElementSize_2(const int &value);
	void valueMorpElementSize_3(const int &value);
	void valueGaussianSize_1(const int &value);
	void valueGaussianSize_2(const int &value);
	void valueGaussianSize_3(const int &value);


};

#endif // BACKGROUNDMODELTUNINGDIALOG_H
