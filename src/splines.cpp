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

	namespace quadratic {
		uint64_t N;							//Número de equações
		Eigen::VectorXd xCoord, yCoord;		// Coordenadas x e y dos pontos de entrada
		Eigen::MatrixXd A;					// AX=B
		Eigen::VectorXd X, B;				// AX=B

		Eigen::MatrixXd coefficients;		// Coeficientes das parábolas encontradas

		void setPointCoord(Eigen::VectorXd x, Eigen::VectorXd y) {
			N = x.size() - 1;
			xCoord = x;
			yCoord = y;
		}

		void setCoefficients(Eigen::VectorXd coeff) {
			coefficients = Eigen::MatrixXd::Zero(N, 3);

			for (uint64_t i = 0; i < N; i++) {
				coefficients.row(i) = coeff.segment(i * 3, 3);
			}
		}

		void setMatrixA(Eigen::VectorXd x, Eigen::MatrixXd& out) {
			out = Eigen::MatrixXd::Zero(3 * N, 3 * N);

			for (uint64_t n = 0; n < N; n++) {

				out.block<1, 3>(2 * n, 3 * n) << x(n) * x(n), x(n), 1;
				out.block<1, 3>(2 * n + 1, 3 * n) << x(n + 1) * x(n + 1), x(n + 1), 1;
			}

			for (uint64_t n = 0; n < N - 1; n++)
				out.block<1, 6>(2 * N + n, 3 * n) << 2 * x(n + 1), 1, 0, -2 * x(n + 1), -1, 0;

			out(3 * N - 1, 0) = 1;

		}
	}
}