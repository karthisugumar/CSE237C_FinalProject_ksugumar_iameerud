#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

#include "types.h"


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
    DTYPE img[NUM_INCHAN][IN_ROWS][IN_COLS], prediction[10];
    float gold;
    FILE *fp;

    DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE];
    DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS];
    DTYPE bias[NUM_OUTCHAN];

    fp = fopen("conv1_out_7.dat", "r");
    for(int r=0; r < IN_ROWS; r++) {
        for(int c=0; c < IN_COLS; c++) {
        	fscanf(fp, "%f\n", &temp);
        img[0][r][c] = temp;
        }
    }
    fclose(fp);


    fp = fopen("conv1_kernel.dat", "r");
    for(int ofm=0; ofm < 6; ofm++) {
		for(int r=0; r < KSIZE; r++) {
			for(int c=0; c < KSIZE; c++) {
				fscanf(fp, "%f\n", &temp);
//				cout << "KERNEL: " << temp << endl;
			filt[ofm][0][r][c] = temp;
			}
		}
    }
    fclose(fp);

    fp = fopen("conv1_bias.dat", "r");
    for(int r=0; r < NUM_OUTCHAN; r++) {
        fscanf(fp, "%f\n", &temp);
 //       cout << "BIAS: " << temp << endl;
        bias[r] = temp;
    }
    fclose(fp);

    conv2d(img, filt, out, bias);

    fp = fopen("conv1_out_7.dat", "r");
    for(int ofm=0; ofm < 6; ofm++) {
    	for(int r=0; r < OUT_ROWS; r++) {
			for(int c=0; c < OUT_COLS; c++) {
				fscanf(fp, "%f\n", &temp);
				cout << "OUT: " << temp << endl;
			rmse.add_value(out[ofm][r][c] - temp);
        	}
    	}
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
