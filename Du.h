#pragma once

#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;


const double g0 = 9.80665;

void gertransfermatrixfromstw (double Om,double u,double i, double A[3][3]){ //матрица перехода из stw
	double csi = cos(i);
	double sni = sin(i);
	double csom = cos(Om);
	double snom = sin(Om);
	double csu = cos(u);
	double snu = sin(u);
	A[0][0]	= csu*csom-snu*snom*csi;
	A[0][1]	= csu*snom+snu*csom*csi;
	A[0][2]	= snu*sni;
	A[1][0]= -csom*snu-csu*snom*csi;
	A[1][1]= -snom*snu+csu*csom*csi;
	A[1][2]= csu*sni;
	A[2][0]= sni*snom;
	A[2][1]= -sni*csom;
	A[2][2]= csi;
}
void vctrxvctr (double x[3], double y[3],double z[3]){ 
	z[0] = x[1] * y[2] - x[2] * y[1];
	z[1] = x[0] * y[2] - x[2] * y[0];
	z[2] = x[0] * y[1] - x[1] * y[0];
}
void det3x3 (double A[3][3], double det){ 
	det = A[2][0]*(A[0][1] * A[1][2] - A[0][2] * A[1][1]) - A[2][1]*(A[0][0] * A[1][2] - A[0][2] * A[1][0]) + A[2][2]*(A[0][0] * A[1][1] - A[0][1] * A[1][0]);
}
void det2x2 (double A[2][2], double det){ 
	det = A[0][0] * A[1][1] - A[1][0] * A[0][1];
}
void findobr3x3 (double A[3][3],double F[3][3]){ 
	//double det,M[3][3];
	//det3x3 ( A, det);
	//if (det !=0){
	//	
	//}
}
void gertransmatfstw (double r[8], double A[3][3]){ //матрица перехода из stw
	double X[3],Y[3],Z[3],T1[3],T2[3],r_;
	r_ = sqrt (r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
	X[0] = r[0]/r_;	X[1] = r[1]/r_;	X[2] = r[2]/r_;
	T1[0] = r[0];	T1[1] = r[1];	T1[2] = r[2];
	T2[0] = r[3];	T2[1] = r[4];	T2[2] = r[5];
	vctrxvctr (T1, T2, Z);
	vctrxvctr (Z, T1, Y);
	r_ = sqrt (Z[0] * Z[0] + Z[1] * Z[1] + Z[2] * Z[2]);
	Z[0] = Z[0]/r_;	Z[1] = Z[1]/r_;	Z[2] = Z[2]/r_;
	r_ = sqrt (Y[0] * Y[0] + Y[1] * Y[1] + Y[2] * Y[2]);
	Y[0] = Y[0]/r_;	Y[1] = Y[1]/r_;	Y[2] = Y[2]/r_;
	A[0][0]	= X[0];//Y[0];//X[0];
	A[0][1]	= X[1];//Y[1];//X[1];
	A[0][2]	= X[2];//Y[2];//X[2];
	A[1][0]	= Y[0];//X[0];//Y[0];
	A[1][1]	= Y[1];//X[1];//Y[1];
	A[1][2]	= Y[2];//X[2];//Y[2];
	A[2][0]	= Z[0];
	A[2][1]	= Z[1];
	A[2][2]	= Z[2];
}
void getGRfStw(double stw[3],double A[3][3],double Gr[3]){ 
	Gr[0]	= A[0][0] * stw[0] + A[0][1] * stw[1] + A[0][2] * stw[2];	
	Gr[1]	= A[1][0] * stw[0] + A[1][1] * stw[1] + A[1][2] * stw[2];
	Gr[2]	= A[2][0] * stw[0] + A[2][1] * stw[1] + A[2][2] * stw[2];
	
}
void gertransabg (double alpha,double delta, double A[3][3]){ 
	
}

void RK4OneStepDu (void (*f)(double , double [] ,double [],double [] ,double ), double t,double xx[8], double h,double F[3],double udm ) { // Метод Рунге-Кутта 4-го порядка
    double K1[8],K2[8],K3[8],K4[8],ffx[8];
	double h2;
	int count;
	h2=h/2;
	f(t,xx,K1,F,udm);
	for ( count = 0; count < 8; count++){
		ffx[count] = xx[count]+h2*K1[count];
	}
	f(t+h2,ffx,K2,F,udm); 
	for (count = 0; count < 8; count++){
		ffx[count] = xx[count]+h2*K2[count];
	}
	f(t+h2,ffx,K3,F,udm);
	for (count = 0; count < 8; count++){
		ffx[count] = xx[count]+h2*K3[count];
	}
	f(t+h,ffx,K4,F,udm);
	for (count = 0; count < 8; count++){
		xx[count] = xx[count]+h*(K1[count]+K4[count]+2*(K2[count]+K3[count]))/6.;
	}
	

}
void RightPartDu(double t, double fx[8],double dfx[8],double F[3],double udm){ //Правая часть уравнений
	 struct Vector3x1 X;
	 X.x = fx[0];
	 X.y = fx[1];
	 X.z = fx[2];
	 double  r=norm(X), r3=r*r*r;
	 double p_ = sqrt( F[0]*F[0] + F[1]*F[1] + F[2]*F[2] );
	 int count;
	 for (count = 0; count < 3; count++){
		dfx[count] = fx[count+3];
	 }
	 for (count = 3; count < 6; count++){
		dfx[count] = -mu*fx[count-3]/r3 + F[count-3]/fx[6];
	 }
	 dfx[6]= -udm;
	 dfx[7]= p_/fx[6];
}
