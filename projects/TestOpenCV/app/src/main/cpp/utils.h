//
// Created by dingjikerbo on 2018/8/27.
//

#ifndef TESTOPENCV_UTILS_H
#define TESTOPENCV_UTILS_H

#include <time.h>
#include <android/log.h>

/* return current time in milliseconds */
static inline int getCurrentMillisecond() {
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	return static_cast<int>(static_cast<uint64_t>(t.tv_sec) * 1000 +
	                        static_cast<uint64_t>(t.tv_nsec) / 1000000);
}

/* return current time in microseconds */
static inline int getCurrentMicrosecond() {
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	return static_cast<int>(static_cast<uint64_t>(t.tv_sec) * 1000000 +
	                        static_cast<uint64_t>(t.tv_nsec) / 1000);
}

#define LOG_TAG "bush"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

#endif //TESTOPENCV_UTILS_H
