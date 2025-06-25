/// @file vector2.h
/// @brief ��ά�����ඨ�壬ʵ�ּ򵥼�¼�������������
/// @date 2025-06-22
#ifndef _VECTOR_2_H_
#define _VECTOR_2_H_

#include <cmath>
#include <algorithm>

/// @class
/// @brief �򵥶�ά��������㣬֧�ּ���ѧ���㷽��
/// @warning ��������Ϊfloatע�����𳬹����ݷ�Χ�������
class Vector2 
{
public:
	/// @brief Ĭ�Ϲ��캯��
	Vector2() = default;

	/// @brief �вι��캯��
	/// @param x ��������
	/// @param y ��������
	Vector2(float x, float y);

	/// @brief �������캯��
	/// @param duration ��ʱʱ��
	Vector2(const Vector2& other);

	/// @brief �ƶ����캯��
	Vector2(Vector2&& other) noexcept;

	/// @brief Ĭ����������
	~Vector2() = default;

public:
	/// @brief ������ֵ�����
	Vector2& operator=(const Vector2& other);

	/// @brief �ƶ���ֵ�����
	Vector2& operator=(Vector2&& other) noexcept;

	/// @brief �����ӷ������
	Vector2 operator+(const Vector2& other) const;
	
	/// @brief �������������
	Vector2 operator-(const Vector2& other) const;

	/// @brief ����ȡ�������
	Vector2 operator-() const;

	/// @brief �������������
	Vector2 operator*(float scalar) const;

	/// @brief �������������
	Vector2 operator/(float scalar) const;

	/// @brief ���ϼӷ���ֵ�����
	Vector2& operator+=(const Vector2& other);

	/// @brief ���ϼ�����ֵ�����
	Vector2& operator-=(const Vector2& other);

	/// @brief �������˸�ֵ�����
	Vector2& operator*=(float scalar);

	/// @brief ���ϳ�����ֵ�����
	Vector2& operator/=(float scalar);

	/// @brief ���ڱȽ������
	bool operator==(const Vector2& other) const;

	/// @brief �����ڱȽ������
	bool operator!=(const Vector2& other) const;
public:

public:

public:
	/// @brief ������������
	/// @return ����������ĳ���
	float Length() const;

	/// @brief ������������ƽ��
	/// @return ����������ĳ���ƽ��
	float LengthSquared() const;

	/// @brief ������������ƽ��
	/// @return ����������ĳ���ƽ��
	Vector2 Normalized() const;

	/// @brief ������������ƽ��
	/// @return ����������ĳ���ƽ��
	Vector2& Normalize();

public:
	float m_x; ///< ��������
	float m_y; ///< ��������

};

/// @brief ���������������������ǰ��
Vector2 operator*(float scalar, const Vector2& vec);

/// @brief �����������
/// @param v1 ����1
/// @param v2 ����2
/// @return ����1������2������
float Dot(const Vector2& v1, const Vector2& v2);

/// @brief �����������
/// @param v1 ����1
/// @param v2 ����2
/// @return ����1������2������
float Cross(const Vector2& v1, const Vector2& v2);

/// @brief ���������н�
/// @param v1 ����1
/// @param v2 ����2
/// @return ����1������2�нǻ���
float Angle(const Vector2& v1, const Vector2& v2);

/// @brief ��������ͶӰ
/// @param v1 ��ͶӰ����1
/// @param v2 ͶӰĿ������2
/// @return ͶӰ������
Vector2 Project(const Vector2& v1, const Vector2& v2);

/// @brief �������Բ�ֵ
/// @param v1 ��ʼ����1
/// @param v2 Ŀ������2
/// @param t ��ֵϵ��
/// @return ��ֵ�������
Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t);

/// @brief ������������ָ��������
/// @param vec ��������
/// @param max_len ��󳤶�
/// @return ���ƺ�����
Vector2 ClampMagnitude(const Vector2& vec, float max_len);

#endif