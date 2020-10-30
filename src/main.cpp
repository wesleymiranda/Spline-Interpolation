#include "include/splines.h"

double WIDTH = 800, HEIGHT = 600;
double XMIN = -3.5, XMAX = 3.5, YMIN = -1.5, YMAX = 1.5;
Eigen::VectorXd x(0), y(0);

//Coordenadas da tela para o plano de desenho(cartesiano)
void coordinateConversion(double& x, double& y) {
	x = x * ((XMAX - XMIN) / WIDTH) + XMIN;
	y = -y * ((YMAX - YMIN) / HEIGHT) - YMIN;
}

void setCoordenates(double xCoord, double yCoord) {
	x.conservativeResize(x.size() + 1);
	y.conservativeResize(y.size() + 1);
	coordinateConversion(xCoord, yCoord);
	x(x.size() - 1) = xCoord;
	y(y.size() - 1) = yCoord;
}