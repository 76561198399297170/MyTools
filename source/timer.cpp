/// @file timer.cpp
/// @brief 定时器类实现
/// @date 2025-06-21
#include "timer.h"

/// @details 有参构造方法只提供两个常用参数，其他需要手动设置
Timer::Timer(int duration, std::function<void()> callback)
	: m_duration(duration), m_callback(callback)
{

}

/// @details 拷贝构造方法完全复制other所有数据
Timer::Timer(const Timer& other)
{
	this->is_auto_restart = other.is_auto_restart;
	this->is_reached = other.is_reached;
	this->is_running = other.is_running;

	this->m_callback = other.m_callback;
	this->m_current_time = other.m_current_time;
	this->m_duration = other.m_duration;
}

/// @details 自动重启通常用作循环触发回调函数，启动则重复执行，关闭则触发后需手动执行 ReStart() 重启标记
void Timer::SetAutoRestart(bool is_auto)
{
	this->is_auto_restart = is_auto;
}

/// @details 后续手动设定回调函数
void Timer::SetCallback(std::function<void()> callback)
{
	this->m_callback = callback;
}

/// @details 重新设定定时器设定时长
/// @attention 重新设定时长不会重置当前时长，但会更新是否到达 is_reached 标记
void Timer::SetDuration(int duration)
{
	this->m_duration = duration;
	this->is_reached = this->m_current_time >= this->m_duration;
}

/// @details 获取定时器完成进度float数据类型百分比
/// @attention 计算顺序为若设定时间小于等于0则始终为100%，若当前时间小于等于0始终为0%，若两者皆否才正常计算百分比
float Timer::GetPercentage()
{
	if (this->m_duration <= 0) return 100.0f;
	if (this->m_current_time <= 0) return 0.0f;
	float res = (float)this->m_current_time / this->m_duration * 100.0f;

	return res < 100.0f ? res : 100.0f;
}

/// @details 传入上次调用定时器更新状态间隔时长以更新定时器状态
/// @note 函数不会跳过任何数据，若定时器运行中即使负数时长也会进行计时
/// @attention 传入间隔时长需要确保所使用的单位一致，函数不进行单位转换
void Timer::Update(int delta)
{
	if (!this->is_running || (!this->is_auto_restart && this->is_reached)) return;

	this->m_current_time += delta;
	if (this->m_current_time >= this->m_duration)
	{
		if (this->is_auto_restart) this->m_current_time -= this->m_duration;
		if ((!this->is_reached || this->is_auto_restart) && this->m_callback) this->m_callback();
		this->is_reached = !this->is_auto_restart;
	}
}

/// @details 定时器暂停，即使调用 Update(int delta) 不会执行任何工作
/// @note 此操作不会变更标志，定时器停止计时以更新状态
void Timer::Pause()
{
	this->is_running = false;
}

/// @details 定时器启动，计时功能正常运行以更新状态
void Timer::Start()
{
	this->is_running = true;
}

/// @details 重置定时器将设定定时器为初始状态
/// @note 此操作将会改变是否到达设定时长标志为false并将当前时间重置为0并暂停计时器，需手动启动定时器
void Timer::ReSet()
{
	this->m_current_time = 0;
	this->is_reached = false;
	this->Pause();
}

/// @details 获取当前是否到达设定时长
/// @attention 若设定自动触发则无论如何返回结果始终为false
bool Timer::IsReached()
{
	if (this->is_auto_restart) return false;
	return this->is_reached;
}
