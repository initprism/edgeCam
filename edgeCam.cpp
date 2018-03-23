#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
			cout << "Can not open capture !!!" << endl;
			return 0;
		}
	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), 
								(int)capture.get(CAP_PROP_FRAME_HEIGHT));
	cout << "Size = " << size << endl;
	//imshow("frame", NULL);
	waitKey(100); // not working because of no window


		int delay = 30;
			int frameNum = -1;
				Mat frame, grayImage, edgeImage;
					namedWindow("frame", WINDOW_AUTOSIZE);
						namedWindow("edgeImage", WINDOW_AUTOSIZE);

							while (1)
									{
											capture >> frame;
											if (frame.empty())
												break;
									
											cvtColor(frame, grayImage, COLOR_BGR2GRAY);
											Canny(grayImage, edgeImage, 80, 150, 3);
									
											imshow("frame", frame);
											imshow("edgeImage", edgeImage);
											
											int ckey = waitKey(delay);
											if (ckey == 27) break;
										}
								return 0;
}
