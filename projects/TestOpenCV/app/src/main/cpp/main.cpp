#include <jni.h>
#include <string>

#include "utils.h"

#include <opencv2/opencv.hpp>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_inuker_testopencv_MainActivity_stringFromJNI(
		JNIEnv *env,
		jobject /* this */) {
	std::string hello = "Hello from C++";

	cv::Mat src = cv::imread("/sdcard/image/t1280.jpg"), dst;

	int times = 1000;

	cv::setNumThreads(1);

	int start = getCurrentMicrosecond();
	for (int i = 0; i < times; i++) {
		cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, cv::INTER_NEAREST);
	}
	int end = getCurrentMicrosecond();

	LOGD("resize nn takes %.3fms", (end-start)/1000.0f/times);

	cv::imwrite("/sdcard/image/out/cvOut.jpg", dst);

	return env->NewStringUTF(hello.c_str());
}
