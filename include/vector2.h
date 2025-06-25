/// @file vector2.h
/// @brief 二维向量类定义，实现简单记录物体坐标与计算
/// @date 2025-06-22
#ifndef _VECTOR_2_H_
#define _VECTOR_2_H_

#include <cmath>
#include <algorithm>

/// @class
/// @brief 简单二维向量坐标点，支持简单数学计算方法
/// @warning 数据类型为float注意请勿超过数据范围导致溢出
class Vector2 
{
public:
	/// @brief 默认构造函数
	Vector2() = default;

	/// @brief 有参构造函数
	/// @param x 横轴坐标
	/// @param y 纵轴坐标
	Vector2(float x, float y);

	/// @brief 拷贝构造函数
	/// @param duration 定时时长
	Vector2(const Vector2& other);

	/// @brief 移动构造函数
	Vector2(Vector2&& other) noexcept;

	/// @brief 默认析构函数
	~Vector2() = default;

public:
	/// @brief 拷贝赋值运算符
	Vector2& operator=(const Vector2& other);

	/// @brief 移动赋值运算符
	Vector2& operator=(Vector2&& other) noexcept;

	/// @brief 向量加法运算符
	Vector2 operator+(const Vector2& other) const;
	
	/// @brief 向量减法运算符
	Vector2 operator-(const Vector2& other) const;

	/// @brief 向量取反运算符
	Vector2 operator-() const;

	/// @brief 向量数乘运算符
	Vector2 operator*(float scalar) const;

	/// @brief 向量数除运算符
	Vector2 operator/(float scalar) const;

	/// @brief 复合加法赋值运算符
	Vector2& operator+=(const Vector2& other);

	/// @brief 复合减法赋值运算符
	Vector2& operator-=(const Vector2& other);

	/// @brief 复合数乘赋值运算符
	Vector2& operator*=(float scalar);

	/// @brief 复合除法赋值运算符
	Vector2& operator/=(float scalar);

	/// @brief 等于比较运算符
	bool operator==(const Vector2& other) const;

	/// @brief 不等于比较运算符
	bool operator!=(const Vector2& other) const;
public:

public:

public:
	/// @brief 计算向量长度
	/// @return 坐标点向量的长度
	float Length() const;

	/// @brief 计算向量长度平方
	/// @return 坐标点向量的长度平方
	float LengthSquared() const;

	/// @brief 计算向量长度平方
	/// @return 坐标点向量的长度平方
	Vector2 Normalized() const;

	/// @brief 计算向量长度平方
	/// @return 坐标点向量的长度平方
	Vector2& Normalize();

public:
	float m_x; ///< 横轴坐标
	float m_y; ///< 纵轴坐标

};

/// @brief 向量数乘运算符（标量在前）
Vector2 operator*(float scalar, const Vector2& vec);

/// @brief 计算向量点积
/// @param v1 向量1
/// @param v2 向量2
/// @return 向量1与向量2点积结果
float Dot(const Vector2& v1, const Vector2& v2);

/// @brief 计算向量叉积
/// @param v1 向量1
/// @param v2 向量2
/// @return 向量1与向量2叉积结果
float Cross(const Vector2& v1, const Vector2& v2);

/// @brief 计算向量夹角
/// @param v1 向量1
/// @param v2 向量2
/// @return 向量1与向量2夹角弧度
float Angle(const Vector2& v1, const Vector2& v2);

/// @brief 计算向量投影
/// @param v1 被投影向量1
/// @param v2 投影目标向量2
/// @return 投影后向量
Vector2 Project(const Vector2& v1, const Vector2& v2);

/// @brief 计算线性插值
/// @param v1 起始向量1
/// @param v2 目标向量2
/// @param t 差值系数
/// @return 插值向量结果
Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t);

/// @brief 将向量限制在指定长度内
/// @param vec 限制向量
/// @param max_len 最大长度
/// @return 限制后向量
Vector2 ClampMagnitude(const Vector2& vec, float max_len);

#endif