#include <jni.h>
#include <string>

#include <opencv2/opencv.hpp>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_inuker_testopencv_MainActivity_stringFromJNI(
		JNIEnv *env,
		jobject /* this */) {
	std::string hello = "Hello from C++";

	cv::Mat src = cv::imread("/sdcard/image/t1280.jpg"), dst;
	cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, cv::INTER_NEAREST);
	cv::imwrite("/sdcard/image/out/cvOut.jpg", dst);

	return env->NewStringUTF(hello.c_str());
}
