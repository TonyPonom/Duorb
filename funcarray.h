#pragma once

#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;


#define PI 3.14159265359
#define PI2 6.28318530718

const double mu= 398600.4415;//гравитационаая постоянная
const double Re = 6371.0;// радиус земли
const double tograd = 180/PI;//перевод в градусы
const double torad = PI/180;//первод в радианы
const double Wer=0.7292115e-4;//угловая скорость вращения земли
struct Nip
{
	double lat;
	double lon;
	double h;
	struct Vector3x1 Grv;
	double gammamin;
	std::string name; 
	double *gamma;
	double *time;
	
};
double norm(double vector[3] ) {	//длинна вектора
	return( sqrt (vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]));
};
double Distant(double vector[3], double vector2[3] ) {	//расстояние между двумя точками
	double vector3[3];
	vector3[0] = vector[0] - vector2[0];
	vector3[1] = vector[1] - vector2[1];
	vector3[2] = vector[2] - vector2[2];
	return( norm(vector3));
};
void getsquare(double vector[3], double v[3],double s[3]) { //нахождения вектора интеграла площадей
	s[0] = vector[1] * v[2] - vector[2] * v[1];
	s[1] = vector[2] * v[0] - vector[0] * v[2];
	s[2] = vector[0] * v[1] - vector[1] * v[0];
};
void getlaplasa(double vector[3], double v[3],double s[3],double rvec,double f[3]) {	//нахождени вектора интеграла лапласа
	f[0] = v[1] * s[2] - s[1] * v[2] - mu * (vector[0] / rvec);
	f[1] = v[2] * s[0] - s[2] * v[0] - mu * (vector[1] / rvec);
	f[2] = v[0] * s[1] - s[0] * v[1] - mu * (vector[2] / rvec);
};
double get_e(double f[3]) { //нахождение эксцентриситета
	return(norm(f) / mu);
}
double get_param(double s[3]) {	//фокальный параметр
	return((norm(s)*norm(s)) / mu);
}
void onevector(double f[3], double r,double one[3]) { // единичный вектор
	one[0] = f[0] / r;
	one[1] = f[1] / r;
	one[2] = f[2] / r;
};
double get_i(double s[3], double r) { //наклонение орбиты
	return(acos(s[2] / r));
}
double get_Om(double s[3], double vector[3], double r, double i, double rvec) {	// долгота восходящего узла
	double Om;
	double sni = sin(i);
	if (i==0)
	{
		if (vector[1] >= 0) {
			Om = acos((vector[0]) / rvec);
		}
		else {
			Om = PI2 - acos((vector[0]) / rvec);
		}
	}
	else {
		if ((s[0] * sni / r) >= 0) {
			Om = acos((-s[1]) / (r*sni));
		}
		else
		{
			Om = PI2 - acos((-s[1]) / (r*sni));
		}
	}
	return(Om);
}
double get_u( double vector[3],double rvec, double i,double Om) {	//аргумент широты
	double u;
	if (i == 0) {
		if (vector[1] >= 0) {
			u = acos((vector[0]) / rvec);
		}
		else {
			u = PI2 - acos((vector[0]) / rvec);
		}

	}
	else
	{
		if (vector[2] >= 0) {
			u = acos((vector[0] * cos(Om) + vector[1] * sin(Om)) / rvec);
		}
		else {
			u = PI2 - acos((vector[0] * cos(Om) + vector[1] * sin(Om)) / rvec);
		}
	}
	return(u);
}
double get_w(double fone[3], double e, double i, double Om,double u) {	//аргумент перицента (fone-единичный вектор интеграла лапласа)
	double w,sw,cw;
	if (e == 0) {
		w = u;
	}
	else {
		if (cos(i)==0)
		{
			sw = fone[2];
			cw = fone[1] / sin(Om);
		}
		else
		{
			sw = (-fone[0]*sin(Om) + fone[1]*cos(Om)) / cos(i);
			cw = fone[0] * cos(Om) + fone[1]*sin(Om);
		}
		if (sw >= 0)
		{
			w = acos(cw);
		}
		else
		{
			w =PI2 - acos(cw);
		}
	}

	return(w);
}
double getMajorAxis(double param, double e) {	//большая полуось
	return(param / (1 - e * e));
}
double getteta(double u, double w) {	//истинная аномалия
	return(u-w);
}
double getrper(double a, double e) {	//радиус перигея
	return((1 - e) * a);
}
double getrap(double a, double e) {	//радиус апогея
	return((1 + e) * a);
}
double gethper(double rper) { //высота перигея при расчете с одинаковым радиусом земли
	return(rper-Re);
}
double gethap(double rap) {	//высота апогея при расчете с одинаковым радиусом земли
	return(rap - Re);
}
double getr(double p, double teta, double e) {	//длинна радиуса-вектора
	return(p/(1+e*cos(teta)));
}
void getXGrKP(double u, double Om, double i, double r,double X[3]) { //нахождение координат x,y,z в ГрКП
	double csu = cos(u);
	double snu = sin(u);
	double csOm = cos(Om);
	double snOm = sin(Om);
	double csi = cos(i);
	X[0] = r * (csu*csOm - snu * snOm*csi);
	X[1] = r * (csu*snOm + snu * csOm*csi);
	X[2] = r * (snu * sin(i));

}
void getVGrKP(double vect[3], double Vr, double omega, double r, double Om, double u, double i, double V[3]) { //нахождение скорости V.x,V.y,V.z в ГрКП
	double csu = cos(u);
	double snu = sin(u);
	double csOm = cos(Om);
	double snOm = sin(Om);
	double csi = cos(i);
	V[0] = (Vr / r) * vect[0] - r * omega * (snu*csOm + csu * snOm*csi);
	V[1] = (Vr / r) * vect[1] - r * omega * (snu*snOm - csu * csOm*csi);
	V[2] = (Vr / r) * vect[2] - r * omega * (-csu * sin(i));
}
double getradialspeed(double p, double teta, double e) {	//радиальная скорость
	return(sqrt(mu / p)*e*sin(teta));
}
double getanglespeed(double p, double r) { //угловая скорость
	return(sqrt(mu * p)/(r*r));
}
double getparam(double rper, double e) {	//фокальный параметр (rper-радиус перигея)
	return(rper*(1+e));
}
void getorbparam(double X[3], double V[3], double &ec, double &a, double &i, double &Om, double &u, double &w, double &teta) {	//нахождени  параметров орбиты
	double s[3];
	double f[3];
	getsquare(X, V, s);
	double R_ = norm(X);
	getlaplasa(X, V, s, R_,f);
	double p = get_param(s);
	ec = get_e(f);
	double rs = norm(s);
	double sone[3];
	onevector(s, rs,sone);
	double rf = norm(f);
	double fone[3];
	onevector(f, rf,fone);
	i = get_i(s, rs);
	Om = get_Om(s, X, rs, i, R_);
	u = get_u(X, R_, i, Om);
	w = get_w(fone, ec, i, Om, u);
	teta = getteta(u, w);
	a = getMajorAxis(p, ec);
}
void getGrKP(double X[3], double V[3], double ec, double a, double i, double Om, double u, double w, double teta ) {	//нахожение координат в ГрКП (ec=e)
	double p = getparam(getrper(a, ec), ec);
	double r = getr(p, teta, ec);
	getXGrKP(u, Om, i, r, X);
	double omega = getanglespeed(p, r);
	double Vr = getradialspeed(p, teta, ec);
	getVGrKP(X, Vr, omega, r, Om, u, i, V);
}
double getperiod(double a) {	//период
	return(PI2*a*sqrt(a / mu));
}
double getdjul(int day, int mon, int year, int hour, int min, int sec)	//юлианская дата
{
long int i1=(mon-14)/12,
	i2=year+4800+i1,
	i3=day-32075+1461*i2/4,
	i4=i3+367*(mon-2-i1*12)/12-3*((i2+100)/100)/4;
	return  (i4-.5+hour/24.+min/1440.+sec/86400.);
}

double startime(int day, int mon, int year, int hour, int min, int sec) {	//звездное время
	double d = getdjul(day, mon, year, hour, min, sec) - 2451545.0;
	double M = (hour * 60 * 60 + min * 60 + sec)/86164.1;
	double tau = d / 36525;
	double s = 1.7533685592 + 0.0172027918051* d + 6.2831853072 * M + 6.7707139e-6 * tau * tau - 4.50876e-10 * tau * tau * tau;
	return(s);
}
void getlatilon(double &lat, double &lon,double X[3], double t) {	//нахождение широты и долготы
	lat=asin(X.z/norm(X)); // широта
	lon=atan2(X[1],X[0])-Wer*t;	//долгота
	while (lon < -PI) { lon = PI2 + lon;}
}
double getsnova_u(double teta, double w) {	//аргумент широты
	return(teta + w);
}
double getecanomal(double teta, double e) {	//эксцентрическая аномалия
	return(2 *atan( sqrt((1 - e) / (1 + e))*tan(teta / 2)));
}
void kepler(double a, double e, double &E, double t) {	//решение уравнения Кеплера (тут t-текущее время минус момент прохождение перигея)
	double deltaE = 10000;
	double epsilon = 1e-8;
	double M = sqrt(mu / (a*a*a))*t;
	E = M;
	double fE, fEpr, deltaE1;
	while (abs(deltaE)>epsilon) {
		fE = E - e*sin(E) - M;
		fEpr = 1 - e*cos(E);
		deltaE1 = -(fE / fEpr);
		if (abs(deltaE1) - abs(deltaE)>0) {
			break;
		}
		else { deltaE = deltaE1; }
		E = E + deltaE;
		if (E >= PI2) {
			E = E - PI2;
		}
	}
}
double get__truean(double E, double e) {	//истинная аномалия
	double truean=2 * atan(sqrt((1 + e) / (1 - e))*tan(E / 2));
	return(truean);
}
double gettper(double t, double midan, double n) {	//момент прохождения перигея (t-начальное время)
	return(t - midan / n);
}
double getn(double period) {	//средняя угловая скорость
	return(PI2 / period);
}
double getmidan(double Ean,double e) {	//средняя аномалия
	return(Ean-e*sin(Ean));
}
void gertransfermatrix (double t, double A[3][3]){ //матрица перехода
	double csalph = cos(Wer*t);
	double snalph =	sin(Wer*t);
	A[0][0]	= csalph;
	A[0][1]	= snalph;
	A[0][2]	= 0;
	A[1][0]	= -snalph;
	A[1][1]	= csalph;
	A[1][2]	= 0;
	A[2][0]	= 0;
	A[2][1]	= 0;
	A[2][2]	= 1;
}
double getanglebetwvectors(double vec1[3],double vec2[3]){ //угл между векторами
	return(acos((vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2])/(norm(vec1)*norm(vec2))));
}
void getGRvNip(double lat,double lon,double h,double v[3]){ //Координаты НИПа в ГРв
	double cslat = cos(lat);
	v[0]	= cslat*cos(lon)*h;	
	v[1]	= cslat*sin(lon)*h;
	v[3]	= sin(lat)*h;
}
void getGRvSat(double Gro[3],double A[3][3],double v[3]){ // Координаты спутника в ГРв
	v[0]	= A[0][0] * Gro[0] + A[0][1] * Gro[1];	
	v[1]	= A[1][0] * Gro[0] + A[1][1] * Gro[1];
	v[3]	= Gro[3];
}
double getangleplace(double vec1[3],double  vec2[3]){ // угл места
	return( (PI/2) - acos((vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[3]*vec2[3])/(norm(vec1)*norm(vec2))));
}
bool isFisible (double gammamin, double gamma){ // видим ли спутник
	if (gamma >= gammamin ){
		return(true);
	}else{return(false);}
}
void getDistSatNip(double Grv[3],double GrNip[3],double v[3]){ //вектор дальности
	v[0]	= Grv[0] - GrNip[0];	
	v[1]	= Grv[1] - GrNip[1];
	v[2]	= Grv[2] - GrNip[2];
}
void RK4OneStep (void (*f)(double, struct Vector3x1&, struct Vector3x1&, struct Vector3x1&, struct Vector3x1&,struct Vector3x1&), double t,  struct Vector3x1 &X, struct Vector3x1 &V,  double h,struct Vector3x1 &F ) { // Метод Рунге-Кутта 4-го порядка
    struct Vector3x1 KX1,KV1,KX2,KV2,KX3,KV3,KX4,KV4,XX,VV;
	double h2;
	h2=h/2;
	f(t,X,V,KX1,KV1,F);   	
	XX.x=X.x+h2*KX1.x;	XX.y=X.y+h2*KX1.y;	XX.z=X.z+h2*KX1.z;
	VV.x=V.x+h2*KV1.x;	VV.y=V.y+h2*KV1.y;	VV.z=V.z+h2*KV1.z;
	f(t+h2,XX,VV,KX2,KV2,F); 
	XX.x=X.x+h2*KX2.x;	XX.y=X.y+h2*KX2.y;	XX.z=X.z+h2*KX2.z;
	VV.x=V.x+h2*KV2.x;	VV.y=V.y+h2*KV2.y;	VV.z=V.z+h2*KV2.z;
	f(t+h2,XX,VV,KX3,KV3,F);
	XX.x=X.x+h*KX3.x;	XX.y=X.y+h*KX3.y;	XX.z=X.z+h*KX3.z;
	VV.x=V.x+h*KV3.x;	VV.y=V.y+h*KV3.y;	VV.z=V.z+h*KV3.z;
	f(t+h,XX,VV,KX4,KV4,F);
	X.x = X.x+h*(KX1.x+KX4.x+2*(KX2.x+KX3.x))/6.;
	X.y = X.y+h*(KX1.y+KX4.y+2*(KX2.y+KX3.y))/6.;
	X.z = X.z+h*(KX1.z+KX4.z+2*(KX2.z+KX3.z))/6.;
	V.x = V.x+h*(KV1.x+KV4.x+2*(KV2.x+KV3.x))/6.;
	V.y = V.y+h*(KV1.y+KV4.y+2*(KV2.y+KV3.y))/6.;
	V.z = V.z+h*(KV1.z+KV4.z+2*(KV2.z+KV3.z))/6.;

}
void RightPart(double t, struct Vector3x1 &X, struct Vector3x1 &V, struct Vector3x1 &dX, struct Vector3x1 &dV,struct Vector3x1 &F){ //Правая часть уравнений
	 double  r=norm(X), r3=r*r*r;
     dX.x = V.x;
	 dX.y = V.y;
	 dX.z = V.z;
	 dV.x=-mu*X.x/r3 + F.x;
	 dV.y=-mu*X.y/r3 + F.y;
	 dV.z=-mu*X.z/r3 + F.z;
	 //double A[3][3];	 
     //gertransfermatrix ( t, A);
     //dX = getGRvSat(X, A);
}
void RK4 (void (*f)(double, struct Vector3x1&, struct Vector3x1&, struct Vector3x1&, struct Vector3x1&, struct Vector3x1&), double &t,  struct Vector3x1 &X, struct Vector3x1 &V,  double h,  double tend ) { // Метод Рунге-Кутта 4-го порядка
	int T = 1;
	struct Vector3x1 F;
	F.x=0; F.y=0; F.z=0;
	if (h < 0){ T = -1;}
	while (T*t < T*tend){
		RK4OneStep (RightPart, t, X, V, h, F );
		t += h;
	}
	if (t > tend){
		t = t - h;
		h = tend - t;
		RK4OneStep (RightPart, t, X, V, h, F );
		t += h; 
	}

}
