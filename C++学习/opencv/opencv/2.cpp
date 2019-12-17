#include <iostream>  
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
/*int main()
{
	Mat image1;
	Mat image2(6, 6, CV_8UC1);
	Mat image3(Size(7, 7), CV_8UC3);
	Mat image4(8, 8, CV_32FC2, Scalar(1, 3));
	Mat image5(Size(9, 9), CV_8UC3, Scalar(1, 2, 3));
	Mat image6(image2);
	cout << image1 << endl;
	cout << image2 << endl;
	cout << image3 << endl;
	cout << image4 << endl;
	cout << image5 << endl;
	cout << image6 << endl;
	return 0;
}*/
/*int main()
{
	Mat Image1(10, 8, CV_8UC1, Scalar(5));
	cout << "image1 row" << Image1.rows << endl;
	cout << "image1 col" << Image1.cols << endl;
	cout << Image1.rowRange(1, 3) << endl;
	cout << Image1.colRange(2, 4) << endl;

	Mat Image2(8, 8, CV_32FC2, Scalar(1, 5));
	Image2.create(10, 10, CV_8UC(3));
	cout << "image2 channels:" << Image2.channels() << endl;
	Image2.convertTo(Image2, CV_32F);
	cout << "image2 depth:" << Image2.depth() << endl;

	Mat Image3 =
		Mat::zeros(Image2.rows, Image2.cols, CV_8UC1);
	Image1.row(4) = Image1.row(5) * 2;
	cout << Image1 << endl;
	Mat Image4 = Image1.col(4);
	cout << Image4 << endl;
	Image1.col(1).copyTo(Image4);
	cout << Image4 << endl;
	return 0;
}*/
/*int main()
{
	Mat srcImage = imread("D:\\1.png");
	if (srcImage.empty())
		return -1;
	Mat srcGray;
	cvtColor(srcImage, srcGray, CV_RGB2GRAY);
	imshow("srcGray", srcGray);
	Mat blurDstImage;
	blur(srcGray, blurDstImage, Size(5, 5), Point(-1, -1));
	imshow("blurDstImage", blurDstImage);
	imwrite("blurDstImage.png", blurDstImage);
	waitKey(0);
	return 0;
}*/
/*int main()
{
	Mat srcImage = imread("D:\\1.png");
	if (!srcImage.data)
		return -1;
	Mat srcGray;
	cvtColor(srcImage, srcGray, CV_RGB2GRAY);
	imshow("srcGray", srcGray);
	imshow("srcImage", srcImage);
	waitKey(0);
	return 0;
}*/
/*int main()
{
	Mat srcImage = imread("D:\\1.png");
	if (!srcImage.data)
		return -1;
	Mat resultingImage(srcImage.size(), srcImage.type());
	Mat xMapImage(srcImage.size(), CV_32FC1);
	Mat yMapImage(srcImage.size(), CV_32FC1);
	int rows = srcImage.rows;
	int cols = srcImage.cols;
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			xMapImage.at<float>(j, i) = cols - i;
			yMapImage.at<float>(j, i) = rows - j;
		}
	}
	remap(srcImage, resultingImage, xMapImage, yMapImage, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
	imshow("srcImage", srcImage);
	imshow("resultingImage", resultingImage);
	waitKey(0);
	return 0;
}*/
Mat imageTranslation1(Mat &srcImage, int xOffset, int yOffset)
{
	int nRows = srcImage.rows;
	int nCols = srcImage.cols;
	Mat resultImage(srcImage.size(), srcImage.type());
	for (int i = 0; i < nRows; ++i)
	{
		for (int j = 0; j < nCols; ++j)
		{
			int x = j - xOffset;
			int y = i - yOffset;
			if (x >= 0 && y >= 0 && x < nCols&&y < nRows)
				resultImage.at<Vec3b>(i, j) = srcImage.ptr<Vec3b>(y)[x];
		}
	}
	return resultImage;
}

Mat imageTranslation2(Mat &srcImage, int xOffset, int yOffset)
{
	int nRows = srcImage.rows + abs(yOffset);
	int nCols = srcImage.cols + abs(xOffset);
	Mat resultImage(nRows, nCols, srcImage.type());
	for (int i = 0; i < nRows; ++i)
	{
		for (int j = 0; j < nCols; ++j)
		{
			int x = j - xOffset;
			int y = i - yOffset;
			if (x >= 0 && y >= 0 && x < nCols&&y < nRows)
				resultImage.at<Vec3b>(i, j) = srcImage.ptr<Vec3b>(y)[x];
		}
	}
	return resultImage;
}

Mat imageReduction1(Mat &srcImage, float kx, float ky)
{
	int nRows=cvRound(srcImage,)
}


int main()
{
	Mat srcImage = imread("D:\\1.jpg");
	if (!srcImage.data)
		return -1;
	imshow("srcImage", srcImage);
	int xOffset = 50, yOffset = 80;
	Mat resultImage1 = imageTranslation1(srcImage, xOffset, yOffset);
	imshow("resultImage1", resultImage1);
	Mat resultImage2 = imageTranslation2(srcImage, xOffset, yOffset);
	imshow("resultImage2", resultImage2);
	xOffset = -50, yOffset = -80;
	Mat resultImage3 = imageTranslation1(srcImage, xOffset, yOffset);
	imshow("resultImage3", resultImage3);
	waitKey(0);
	return 0;
}
