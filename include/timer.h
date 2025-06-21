/// @file timer.h
/// @brief ��ʱ���ඨ�壬ͨ���ص�����ʵ�ֶ�ʱ����
/// @date 2025-06-21
#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

/// @class
/// @brief �򵥶�ʱ����֧�ֶ�ʱ�ص����Զ�����
class Timer
{
public:
	/// @brief Ĭ�Ϲ��캯��
	Timer() = default;

	/// @brief �вι��캯��
	/// @param duration ��ʱʱ��
	/// @param callback ��ʱ����ʱִ�еĻص�����
	Timer(int duration, std::function<void()> callback);

	/// @brief �������캯��
	/// @param duration ��ʱʱ��
	Timer(const Timer& other);

	/// @brief Ĭ����������
	~Timer() = default;

public:

public:
	/// @brief �趨��ʱ���Ƿ��Զ�����
	/// @param is_auto true�Զ�������false�ֶ�����
	void SetAutoRestart(bool is_auto);

	/// @brief �趨��ʱ���ص�����
	/// @param callback ��ʱ������ʱִ�еĻص�����
	void SetCallback(std::function<void()> callback);

	/// @brief �趨��ʱ����ʱʱ��
	/// @param duration ��ʱʱ��
	void SetDuration(int duration);

public:
	/// @brief ��ȡ��ʱ����ɰٷֱ�
	/// @return [0.0f, 100.0f]����Ϊ��ǰ��ʱ����ɰٷֱ�
	float GetPercentage();

public:
	/// @brief ���¶�ʱ��״̬
	/// @param delta �����ϴε��ü��ʱ��
	void Update(int delta);

	/// @brief ��ͣ��ʱ��
	void Pause();

	/// @brief ������ʱ��
	void Start();

	/// @brief ������ʱ��
	void ReSet();

	/// @brief �ж϶�ʱ���Ƿ񵽴��趨ʱ��
	/// @return true�ѵ��falseδ����
	bool IsReached();

private:
	bool is_reached = false; ///< ��ʱ���Ƿ񵽴��趨ʱ����־

private:
	bool is_running = false; ///< ��ʱ���Ƿ��������б�־
	bool is_auto_restart = true; ///< ��ʱ���Ƿ��Զ�������־

	int m_duration = 0; ///< ��ʱ���趨ʱ��
	int m_current_time = 0; ///< ��ʱ����ǰʱ��

	std::function<void()> m_callback = [&]() {}; ///< ��ʱ������ʱִ�еĻص�����
};

#endif