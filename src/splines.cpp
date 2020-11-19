#include "includes/splines.h"

namespace spline {
	void drawPoints(Eigen::MatrixXd points) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glPointSize(5.0f);

		glBegin(GL_POINTS);
		for (int i = 0; i < points.rows(); i++) glVertex3d(points(i, 0), points(i, 1), 0);
		glEnd();
	}

	void drawPoints(Eigen::VectorXd x, Eigen::VectorXd y) {
		if (x.size() != y.size())
			std::cout << "Os vetores X e Y não devem ter tamanhos diferentes!" << std::endl;

		glColor3f(0.f, 0.f, 0.f);
		glPointSize(5.f);

		glBegin(GL_POINTS);
		for (int i = 0; i < x.size(); i++) glVertex3d(x(i), y(i), 0);
		glEnd();
	}

	void drawAxis(double xmin, double xmax, double ymin, double ymax) {
		glColor3f(0.f, 0.f, 1.f);
		glLineWidth(0.5f);

		glBegin(GL_LINES);
		glVertex3d(xmin, 0, 0);
		glVertex3d(xmax, 0, 0);
		glVertex3d(0, ymin, 0);
		glVertex3d(0, ymax, 0);
		glEnd();
	}

	void drawFunction(function f, double xa, double xb) {
		glColor3f(1.f, 1.f, 0.f);
		glLineWidth(5.0f);

		int points = 100;
		double increment = (xa - xb) / ((double)points - 1);
		double num = xa;

		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < points; i++) {
			glVertex3d(num, f(num), 0);
			num += increment;
		}
		glEnd();
	}
}