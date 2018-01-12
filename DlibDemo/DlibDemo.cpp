// DlibDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "opencv2/opencv.hpp"
#include "Debug.h"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include "unistd.h"
#include "dlibFaceDetection.h"
using namespace dlib;
using namespace std;
using namespace smartimage;

smartimage::FaceDetection *pFaceDetect = nullptr;
#define DLIB_NO_GUI_SUPPORT

int main(int argc, char** argv)
{

	string modePath = "data\\new_train_68.dat";
	string imgPath = "images\\1.jpg";
	//string imgPath = "F:\\StudyZone\\DlibFaceDetection\\image\\test.jpg";


	//char * outPath = "lightTest\\L1.jpg";
	//**************************************** face detection *******************************************
	cv::Mat pSrcImage;
	int32_t face_num;
	if (nullptr == pFaceDetect)
	{
		pFaceDetect = new FaceDetection();
		pFaceDetect->initFaceDetection(modePath);
		face_num = pFaceDetect->detectFaces(imgPath, pSrcImage);
	}
	else
	{
		face_num = pFaceDetect->detectFaces(imgPath, pSrcImage);
	}
	if (face_num < 1)
	{
		return 0;
	}
	full_object_detection shape = pFaceDetect->getDetectOneShape();
	//delete dlib
	pFaceDetect->uninitFaceDetection();
	delete pFaceDetect;
	pFaceDetect = nullptr;
	//****************************************end *******************************************

	DEBUG_IMSHOW("image", pSrcImage, shape);
	
	cout << "project finished...";
	cv::waitKey(0);
}
