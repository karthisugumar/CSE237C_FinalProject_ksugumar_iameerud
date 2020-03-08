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
    float gold;
    FILE *fp;

    DTYPE in[PREDS];
    DTYPE out[PREDS];
    
    fp = fopen("softmax_in.dat", "r");
	for(int p=0; p<PREDS; p++) {
		fscanf(fp, "%f\n", &temp);
		//cout << "IN: " << temp << endl;
	in[p] = temp;
	}
    fclose(fp);

    softmax(in, out);

    fp = fopen("softmax_out.dat", "r");
	for(int p=0; p < PREDS; p++) {
		fscanf(fp, "%f\n", &temp);
		//cout << "OUT: " << out[p] << endl;
	rmse.add_value(out[p] - temp);
	}
    fclose(fp);

    // printing error results
    printf("----------------------------------------------\n");
    printf("   RMSE ");
    printf("%f\n", rmse.error);
    printf("----------------------------------------------\n");

    if (rmse.error > 0.01) {
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
