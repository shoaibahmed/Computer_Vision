#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
	int fps = 30;
	int delay = 1000 / fps;
	cv::Mat frame;
	cv::VideoCapture videoCapture(0);
	if (!videoCapture.isOpened())
	{
		cout << "Error: Unable to initialize webcam!" << endl;
		exit (-1);
	}

	videoCapture >> frame;
	while(!frame.empty())
	{
		cv::imshow("Webcam output", frame);
		videoCapture >> frame;
		char keyPressed = cv::waitKey(delay);
		if (keyPressed == 'q' || keyPressed == 'Q')
		{
			cout << "Program terminated by user!" << endl;
			break;
		}
	}
}
