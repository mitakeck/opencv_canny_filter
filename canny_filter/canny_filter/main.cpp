#include <opencv\cv.h>
#include <opencv\highgui.h>

int main(int argc, char* argv[]){

	IplImage* input;
	IplImage* output;

	char filePath[] = "lena.jpg";

	// �O���C�X�P�[���ŉ摜�ǂݍ���
	input = cvLoadImage(filePath, CV_LOAD_IMAGE_COLOR);
	// �摜�̃������̈�m��
	output = cvCreateImage(cvGetSize(input), IPL_DEPTH_8U, 1);

	// �G�b�W���o
	cvCanny(input, output, 64, 128);

	// �\��
	cvNamedWindow("input", CV_WINDOW_AUTOSIZE);
	cvShowImage("input", input);
	cvNamedWindow("output", CV_WINDOW_AUTOSIZE);
	cvShowImage("output", output);
	cvWaitKey(0);
	cvDestroyAllWindows();

	// �摜�̉��
	cvReleaseImage(&input);
	cvReleaseImage(&output);

	return 0;
}