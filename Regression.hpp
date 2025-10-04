#include<vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "Variable.hpp"


struct Regression{

    int nbrows;
    int nbcols;
    float coefficient;
    float intercept;
    float covariance;
    float R_square;
    float x_mean;
    float y_mean;
    float *label;
    float **predictor;


    std::vector<Variable>* observation;

    Regression(){
        nbrows = 0;
        nbcols = 0;
        coefficient = 0;
        intercept = 0;
        covariance = 0;
        R_square = 0;
        x_mean = 0;
        y_mean = 0;
        label = nullptr;
        predictor = nullptr;
        std::cout << "Regression is initialized" << std::endl;
    }

    void readData(std::string name){
        std::ifstream file(name);

      if (!file)
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        else
        {
            std::string line;
            while (std::getline(file, line))
            {

             
            }
            file.close();
        }




    }




};