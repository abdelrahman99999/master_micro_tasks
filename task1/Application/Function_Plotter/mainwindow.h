/**
 * @file mainwindow.h
 * @author abdelrahman elsayed
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Main Window object
     * 
     * @param parent 
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Main Window object
     * 
     */
    ~MainWindow();

private slots:
    /**
     * @brief on_draw_button_clicked
     */
    void on_draw_button_clicked();

    /**
     * @brief on_zoom_in_h_button_clicked
     */
    void on_zoom_in_h_button_clicked();

    /**
     * @brief on_zoom_out_h_button_clicked
     */
    void on_zoom_out_h_button_clicked();

    /**
     * @brief on_zoom_in_v_button_clicked
     */
    void on_zoom_in_v_button_clicked();

    /**
     * @brief on_zoom_out_v_button_clicked
     */
    void on_zoom_out_v_button_clicked();

private:
    Ui::MainWindow *ui;
    /**
     * @brief variables used to specifiy width,height of drawing
     */
    int min_x_axis;
    int max_x_axis;
    int min_y_axis=-10;
    int max_y_axis=10;
    /**
     * @brief makePlot
     * @param min : minimum value for variable x
     * @param max : maximum value for variable x
     * @param expression : math expression that will substitute in
     */
    void makePlot(double min,double max,std::string expression);

};
#endif // MAINWINDOW_H
