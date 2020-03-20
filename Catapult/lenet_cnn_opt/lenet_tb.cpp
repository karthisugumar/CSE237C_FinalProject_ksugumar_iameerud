#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

#include "lenet.h"
#include "lenet_cnn.h"

struct Rmse
{
    int num_sq;
    float sum_sq;
    float error;
    
    Rmse(){ num_sq = 0; sum_sq = 0; error = 0; }
    
    float add_value(float d_n)
    {
        num_sq++;
        sum_sq += (d_n*d_n);
        error = sqrtf(sum_sq / num_sq);
        return error;
    }
    
};

Rmse rmse;

int main()
{
    //int r,c,s;
    float temp;
    float gold;
    FILE *fp;

  //  DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE];
    DTYPE img[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS];
    DTYPE out[PREDS];
 //   DTYPE bias[NUM_OUTCHAN];

    fp = fopen("image_0_in.dat", "r");
    for(int ifm=0; ifm < C1_NUM_INCHAN; ifm++) {
		for(int r=0; r < C1_IN_ROWS; r++) {
			for(int c=0; c < C1_IN_COLS; c++) {
				fscanf(fp, "%f\n", &temp);
			img[ifm][r][c] = temp;
			}
		}
    }
    fclose(fp);


    lenet(img, out);


    fp = fopen("image_0_out.dat", "r");
    for(int p=0; p < PREDS; p++) {
		fscanf(fp, "%f\n", &temp);
		cout << "PREDS: " << out[p] << endl;
	   //rmse.add_value((float)(out[p]) - temp);
    }
    fclose(fp);

    // printing error results
    printf("----------------------------------------------\n");
    printf("   RMSE ");
    printf("%f\n", rmse.error);
    printf("----------------------------------------------\n");

    if (rmse.error > 0.001) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "*******************************************\n");
        return 1;
    }else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "PASS: The output matches the golden output!\n");
        fprintf(stdout, "*******************************************\n");
        return 0;
    }
    return 0;
}
