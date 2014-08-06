#include <opencv\cv.h>
#include <opencv\highgui.h>

int main(int argc, char* argv[]){

	IplImage* input;
	IplImage* output;

	char filePath[] = "lena.jpg";

	// グレイスケールで画像読み込み
	input = cvLoadImage(filePath, CV_LOAD_IMAGE_COLOR);
	// 画像のメモリ領域確保
	output = cvCreateImage(cvGetSize(input), IPL_DEPTH_8U, 1);

	// エッジ抽出
	cvCanny(input, output, 64, 128);

	// 表示
	cvNamedWindow("input", CV_WINDOW_AUTOSIZE);
	cvShowImage("input", input);
	cvNamedWindow("output", CV_WINDOW_AUTOSIZE);
	cvShowImage("output", output);
	cvWaitKey(0);
	cvDestroyAllWindows();

	// 画像の解放
	cvReleaseImage(&input);
	cvReleaseImage(&output);

	return 0;
}