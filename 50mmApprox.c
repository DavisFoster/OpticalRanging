#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

double focalLengthComp(double dist, int method);

int main()
{

	double dist; 		 //distance from sensor to in-focus subject (m)
	double sensorHeight; //height of image sensor (mm)
	double sensorWidth;	 //width of image sensor (mm)
	double fLenEff; 	 //effective focal length (mm)
	int pixelHeight;	 //vertical pixel height (px)
	int pixelWidth;		 //horizontal pixel width (px)
	double subHeight;	 //subject height (px)
	double subWidth;	 //subject width (px)
	double objHeight;	 //subject height (m)
	double objWidth;	 //subject width (m)

	fLenEff = focalLengthComp(.5, 0);
	printf("%f\n",fLenEff);
	
	fLenEff = focalLengthComp(.5, 1);
	printf("%f\n",fLenEff);


}

double focalLengthComp(double dist, int method) //Focal length varies with focus distance.  This function attempts to compensate based on focal distance
{
	double fLenCor = 50.0; 
	switch(method){
		case 0:
			fLenCor = (-0.1668*dist + 50.075);
			break;
		case 1:
			fLenCor = (49.4115 - 1.98574*log(dist));
			break;
		default:
			fLenCor = 50;	
	}

	return fLenCor;
}