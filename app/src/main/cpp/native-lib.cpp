#include <jni.h>
#include <string>

#include "libusb_utils.h"
#include <jni.h>
#include <assert.h>

std::string connect_device(int fileDescriptor)
{
    libusb_context *ctx;
    libusb_device_handle *devh;
    int r = 0;

    libusb_set_option(nullptr, LIBUSB_OPTION_NO_DEVICE_DISCOVERY, NULL);        //
    libusb_init(nullptr);
    libusb_wrap_sys_device(nullptr, (intptr_t)fileDescriptor, &devh);

    auto device = libusb_get_device(devh);
    print_device(device, devh);

    libusb_detach_kernel_driver(devh, 0);
    libusb_claim_interface(devh, 0);
    libusb_release_interface(devh, 0);

    unsigned char mesg2[2] = {0x00,0x00};
    libusb_control_transfer(devh, 0b00100001, 0x1, 0x0201, 0x0200, mesg2, sizeof(mesg2), 500);
    libusb_control_transfer(devh, 0b00100001, 0x1, 0x0202, 0x0200, mesg2, sizeof(mesg2), 500);

    libusb_reset_device(devh);


    return get_device_name(device, devh);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_libusbAndroidTest_MainActivity_initializeNativeDevice(
        JNIEnv* env,
        jobject /* this */,
        jint fileDescriptor) {


    std::string deviceName = connect_device(fileDescriptor);

    return env->NewStringUTF(deviceName.c_str());
}
