#include "pch.h"
#include <iostream>

#define CVUI_IMPLEMENTATION
#define WINDOW_NAME "CVUI Hello World!"
#include "cvui.h"

int main()
{
	auto cam = cv::VideoCapture(0);
	//auto knn = cv::ml::KNearest::create();

	auto frame = cv::Mat(200, 500, CV_8UC3);
	bool histEqYCbCr = false, median = false, lap = false;
	int medianSize = 3, lapSize = 1;

	cvui::init(WINDOW_NAME);
	while (true) {
		cam >> frame;

		cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
		cv::medianBlur(frame, frame, medianSize);
		cv::equalizeHist(frame, frame);

		int layoutIdx = 1;
		cvui::counter(frame, 20, 20 * (layoutIdx++), &medianSize, 2);
		cvui::checkbox(frame, 20, 20 * (layoutIdx++), "Laplacian", &lap);
		cvui::imshow(WINDOW_NAME, frame);
		if (cv::waitKey(20) == 27) {
			break;
		}
	}

	return 0;
}