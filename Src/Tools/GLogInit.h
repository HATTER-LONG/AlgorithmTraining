#pragma once
#include <glog/logging.h>
#include <string>

class GLogInit {
public:
    GLogInit(std::string programName, std::string logFilePath = "") {
        FLAGS_log_dir = logFilePath;
        google::InitGoogleLogging(programName.c_str());
        google::SetStderrLogging(google::INFO); // 设置级别高于 google::INFO 的日志同时输出到屏幕
        FLAGS_colorlogtostderr = true;          // 设置输出到屏幕的日志显示相应颜色
        FLAGS_logbufsecs = 0;                   // 缓冲日志输出，默认为30秒，此处改为立即输出
        FLAGS_max_log_size = 100;               // 最大日志大小为 100MB
        FLAGS_stop_logging_if_full_disk = true; // 当磁盘被写满时，停止日志输出

        google::InstallFailureSignalHandler(); // 捕捉 core dumped
        // 默认捕捉 SIGSEGV 信号信息输出会输出到
        // stderr，可以通过下面的方法自定义输出>方式：
        google::InstallFailureWriter([](const char* data, auto size) {
            std::string str = std::string(data, size);
            LOG(ERROR) << str;
        });
    }

    ~GLogInit() { google::ShutdownGoogleLogging(); }
};
