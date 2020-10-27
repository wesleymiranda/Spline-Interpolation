#pragma once

#include <iostream>
#include <GLFW\glfw3.h>
#include <Eigen\Dense>

namespace spline {

	typedef double (*function)(double);

	void drawPoints(Eigen::MatrixXd points);
	void drawPoints(Eigen::VectorXd x, Eigen::VectorXd y);
	void drawAxis(double xmin, double xmax, double ymin, double ymax);
	void drawFunction(function f, double xa, double xb);


	namespace quadratic {

		void setPointCoord(Eigen::VectorXd x, Eigen::VectorXd y);
		void setCoefficients(Eigen::VectorXd coeff);
		void setMatrixA(Eigen::VectorXd x, Eigen::MatrixXd& out);
		void setVectorB(Eigen::VectorXd y, Eigen::VectorXd& out);
		void solveEquations(Eigen::MatrixXd A, Eigen::VectorXd& X, Eigen::VectorXd B);
		void quadraticSpline(Eigen::VectorXd x, Eigen::VectorXd y);
		double quadFunction(double x, double a, double b, double c);
		void drawSpline(Eigen::VectorXd x, Eigen::MatrixXd coeff);
	}


	namespace cubic {

		void setPointCoord(Eigen::VectorXd x, Eigen::VectorXd y);
		void setDifferenceH(Eigen::VectorXd& x, Eigen::VectorXd& out);
		void setMatrixA(Eigen::VectorXd h, Eigen::MatrixXd& out);
		void setVectorB(Eigen::VectorXd h, Eigen::VectorXd y, Eigen::VectorXd& out);
		void setCoefficients(Eigen::VectorXd h, Eigen::VectorXd y, Eigen::VectorXd X, Eigen::MatrixXd& coeff);
		void cubicSpline(Eigen::VectorXd x, Eigen::VectorXd y);
		double cubicFunction(double x, double xk, double a, double b, double c, double d);
		void drawSpline(Eigen::VectorXd x, Eigen::MatrixXd coeff);
	}

	/*
	namespace parametric1 {
		void setPointCoord(Eigen::VectorXd x, Eigen::VectorXd y);
		void setDifferenceH(double interval_t = 1);
		void cubicFunction(double t, double tk, int line, double& x, double& y);
		void calculeCoefficients();
		void drawSplines();
		void parametricSpline(Eigen::VectorXd x_, Eigen::VectorXd y_);
	}
	*/

	namespace parametric {
		void setPointCoord(Eigen::VectorXd x, Eigen::VectorXd y);
		void setDifferenceH(double interval_t);
		void setMatrixA();
		void setVectorB();
		void cubicFunction(double t, double tk, int line, double& x, double& y);
		void solveEquations();
		void calculeCoefficients();
		void drawSplines();
		void parametricSpline(Eigen::VectorXd x_, Eigen::VectorXd y_);
	}
}