/**
 * @file mainwindow.cpp
 * @author abdelrahman elsayed
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<string>
#include<QString>
#include<QMessageBox>
#include"math_operation.h"
/**
 * @brief Construct a new Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**
 * @brief Destroy the Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief makePlot
 * @param min : minimum value for variable x
 * @param max : maximum value for variable x
 * @param expression : math expression that will substitute in
 */
void MainWindow::makePlot(double min,double max,std::string exp){
    if(exp==""){
        QMessageBox::warning(this,"Warning","please enter function to use !");
        return;
    }
    if((min>max) || (min==max)){
        QMessageBox::warning(this,"Warning","please enter vaild min max values !");
        return;
    }

    min_x_axis=min;
    max_x_axis=max;
    min_y_axis=-10;
    max_y_axis=10;

    // generate some data:
    int size=(max-min)/0.1;
    QVector<double> x(size+1), y(size+1); // initialize with entries 0..100

    x[0]=min;
    try{
        y[0]=math_operation::vaildate_input_get_result(exp,x[0]);
        for (int i=1; i<size+1; ++i)
        {
          x[i] = x[i-1]+0.1; // x goes from min to max with sep 0.1
          y[i] = math_operation::vaildate_input_get_result(exp,x[i]);
        }
        // create graph and assign data to it:
        ui->customplot->addGraph();
        ui->customplot->graph(0)->setData(x, y);

        // give the axes some labels:
        ui->customplot->xAxis->setLabel("x");
        ui->customplot->yAxis->setLabel("y");

        // set axes ranges, so we see all data:
        ui->customplot->xAxis->setRange(min_x_axis, max_x_axis);
        ui->customplot->yAxis->setRange(min_y_axis, max_y_axis);
        ui->customplot->replot();
    } catch (Invaild_Expression &e) {
        QMessageBox::warning(this,e.what(),"please enter vaild function !");
    }
}

/**
 * @brief on_draw_button_clicked
 */
void MainWindow::on_draw_button_clicked()
{
    double min=ui->min_spin->value();
    double max=ui->max_spin->value();
    std::string expression=ui->exp_input->text().toStdString();
    makePlot(min,max,expression);
}


/**
 * @brief on_zoom_in_h_button_clicked
*/
void MainWindow::on_zoom_in_h_button_clicked()
{
    if(min_x_axis<max_x_axis){
        min_x_axis+=1;
        max_x_axis-=1;

    }else{
        min_x_axis=ui->min_spin->value();
        max_x_axis=ui->max_spin->value();
    }
    ui->customplot->xAxis->setRange(min_x_axis, max_x_axis);
    ui->customplot->replot();
}

/**
 * @brief on_zoom_out_h_button_clicked
 */
void MainWindow::on_zoom_out_h_button_clicked()
{
    if(min_x_axis<max_x_axis){
        min_x_axis-=1;
        max_x_axis+=1;

    }else{
        min_x_axis=ui->min_spin->value();
        max_x_axis=ui->max_spin->value();
    }
    ui->customplot->xAxis->setRange(min_x_axis, max_x_axis);
    ui->customplot->replot();
}

/**
 * @brief on_zoom_in_v_button_clicked
 */
void MainWindow::on_zoom_in_v_button_clicked()
{
    if(min_y_axis<max_y_axis){
        min_y_axis+=1;
        max_y_axis-=1;

    }else{
        min_y_axis=-10;
        max_y_axis=10;
    }
    ui->customplot->yAxis->setRange(min_y_axis, max_y_axis);
    ui->customplot->replot();
}

/**
 * @brief on_zoom_out_v_button_clicked
 */
void MainWindow::on_zoom_out_v_button_clicked()
{
    if(min_y_axis<max_y_axis){
        min_y_axis-=1;
        max_y_axis+=1;

    }else{
        min_y_axis=-10;
        max_y_axis=10;
    }
    ui->customplot->yAxis->setRange(min_y_axis, max_y_axis);
    ui->customplot->replot();
}

