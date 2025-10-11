#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "Variable.hpp"

struct Regression
{

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

    std::vector<Variable> *observation;

    Regression()
    {
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

    void readData(std::string name)
    {
        std::ifstream file(name);
        if (!file)
        {
            std::cerr << "Error opening file: " << name << std::endl;
            return;
        }
        else
        {

            file >> nbrows >> nbcols;
            std::cout << "Number of rows: " << nbrows << std::endl;
            std::cout << "Number of columns: " << nbcols << std::endl;
            label = new float[nbrows];
            predictor = new float *[nbrows];
            for (int i = 0; i < nbrows; i++)
            {
                predictor[i] = new float[nbcols];
            }
            file;
            std::cout << "Reading labels..." << std::endl;
            for (int i = 0; i < nbrows; i++)
            {
                file >> label[i];
            }
            file;

            std::cout << "Reading predictors..." << std::endl;
            for (int i = 0; i < nbrows; i++)
            {
                for (int j = 0; j < nbcols; j++)
                {
                    file >> predictor[i][j];
                }
            }
        }
    }

    void displayData()
    {
        std::cout << "Labels:" << std::endl;
        for (int i = 0; i < nbrows; i++)
        {
            std::cout << label[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Predictors:" << std::endl;
        for (int i = 0; i < nbrows; i++)
        {
            for (int j = 0; j < nbcols; j++)
            {
                std::cout << predictor[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};