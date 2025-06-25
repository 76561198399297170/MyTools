/// @file timer.cpp
/// @brief ��ʱ����ʵ��
/// @date 2025-06-21
#include "timer.h"

/// @details �вι��췽��ֻ�ṩ�������ò�����������Ҫ�ֶ�����
Timer::Timer(int duration, std::function<void()> callback)
	: m_duration(duration), m_callback(callback)
{

}

/// @details �������췽����ȫ����other��������
Timer::Timer(const Timer& other)
{
	this->is_auto_restart = other.is_auto_restart;
	this->is_reached = other.is_reached;
	this->is_running = other.is_running;

	this->m_callback = other.m_callback;
	this->m_current_time = other.m_current_time;
	this->m_duration = other.m_duration;
}

/// @details �Զ�����ͨ������ѭ�������ص��������������ظ�ִ�У��ر��򴥷������ֶ�ִ�� ReStart() �������
void Timer::SetAutoRestart(bool is_auto)
{
	this->is_auto_restart = is_auto;
}

/// @details �����ֶ��趨�ص�����
void Timer::SetCallback(std::function<void()> callback)
{
	this->m_callback = callback;
}

/// @details �����趨��ʱ���趨ʱ��
/// @attention �����趨ʱ���������õ�ǰʱ������������Ƿ񵽴� is_reached ���
void Timer::SetDuration(int duration)
{
	this->m_duration = duration;
	this->is_reached = this->m_current_time >= this->m_duration;
}

/// @details ��ȡ��ʱ����ɽ���float�������Ͱٷֱ�
/// @attention ����˳��Ϊ���趨ʱ��С�ڵ���0��ʼ��Ϊ100%������ǰʱ��С�ڵ���0ʼ��Ϊ0%�������߽Է����������ٷֱ�
float Timer::GetPercentage()
{
	if (this->m_duration <= 0) return 100.0f;
	if (this->m_current_time <= 0) return 0.0f;
	float res = (float)this->m_current_time / this->m_duration * 100.0f;

	return res < 100.0f ? res : 100.0f;
}

/// @details �����ϴε��ö�ʱ������״̬���ʱ���Ը��¶�ʱ��״̬
/// @note �������������κ����ݣ�����ʱ�������м�ʹ����ʱ��Ҳ����м�ʱ
/// @attention ������ʱ����Ҫȷ����ʹ�õĵ�λһ�£����������е�λת��
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

/// @details ��ʱ����ͣ����ʹ���� Update(int delta) ����ִ���κι���
/// @note �˲�����������־����ʱ��ֹͣ��ʱ�Ը���״̬
void Timer::Pause()
{
	this->is_running = false;
}

/// @details ��ʱ����������ʱ�������������Ը���״̬
void Timer::Start()
{
	this->is_running = true;
}

/// @details ���ö�ʱ�����趨��ʱ��Ϊ��ʼ״̬
/// @note �˲�������ı��Ƿ񵽴��趨ʱ����־Ϊfalse������ǰʱ������Ϊ0����ͣ��ʱ�������ֶ�������ʱ��
void Timer::ReSet()
{
	this->m_current_time = 0;
	this->is_reached = false;
	this->Pause();
}

/// @details ��ȡ��ǰ�Ƿ񵽴��趨ʱ��
/// @attention ���趨�Զ�������������η��ؽ��ʼ��Ϊfalse
bool Timer::IsReached()
{
	if (this->is_auto_restart) return false;
	return this->is_reached;
}
