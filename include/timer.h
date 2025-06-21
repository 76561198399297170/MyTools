/// @file timer.h
/// @brief 定时器类定义，通过回调函数实现定时功能
/// @date 2025-06-21
#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

/// @class
/// @brief 简单定时器，支持定时回调与自动重启
class Timer
{
public:
	/// @brief 默认构造函数
	Timer() = default;

	/// @brief 有参构造函数
	/// @param duration 定时时长
	/// @param callback 定时到达时执行的回调函数
	Timer(int duration, std::function<void()> callback);

	/// @brief 拷贝构造函数
	/// @param duration 定时时长
	Timer(const Timer& other);

	/// @brief 默认析构函数
	~Timer() = default;

public:

public:
	/// @brief 设定定时器是否自动重启
	/// @param is_auto true自动重启，false手动重启
	void SetAutoRestart(bool is_auto);

	/// @brief 设定计时器回调函数
	/// @param callback 计时器到达时执行的回调函数
	void SetCallback(std::function<void()> callback);

	/// @brief 设定定时器定时时长
	/// @param duration 定时时长
	void SetDuration(int duration);

public:
	/// @brief 获取定时器完成百分比
	/// @return [0.0f, 100.0f]数据为当前定时器完成百分比
	float GetPercentage();

public:
	/// @brief 更新定时器状态
	/// @param delta 距离上次调用间隔时长
	void Update(int delta);

	/// @brief 暂停定时器
	void Pause();

	/// @brief 启动定时器
	void Start();

	/// @brief 重启定时器
	void ReSet();

	/// @brief 判断定时器是否到达设定时长
	/// @return true已到达，false未到达
	bool IsReached();

private:
	bool is_reached = false; ///< 定时器是否到达设定时长标志

private:
	bool is_running = false; ///< 定时器是否正在运行标志
	bool is_auto_restart = true; ///< 定时器是否自动重启标志

	int m_duration = 0; ///< 定时器设定时长
	int m_current_time = 0; ///< 定时器当前时长

	std::function<void()> m_callback = [&]() {}; ///< 计时器到达时执行的回调函数
};

#endif