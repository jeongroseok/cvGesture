#include "pch.h"
#include <iostream>

#define CVUI_IMPLEMENTATION
#define WINDOW_NAME "CVUI Hello World!"
#include "cvui.h"

int main()
{
	cv::Mat frame = cv::Mat(200, 500, CV_8UC3);

	cvui::init(WINDOW_NAME);
	uint8_t count = 0;

	while (true) {
		frame = cv::Scalar(49, 52, 49);

		cvui::text(frame, 110, 40, "Hello, world!");
		if (cvui::button(frame, 110, 70, "Button")) {
			count++;
		}
		cvui::printf(frame, 110, 100, "%d", count);

		cvui::imshow(WINDOW_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}

	return 0;
}