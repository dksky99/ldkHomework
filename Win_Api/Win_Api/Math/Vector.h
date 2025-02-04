#pragma once
class Vector
{
public:
	Vector() : x(0.0f), y(0.0f) {}
	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	~Vector() {}

	static Vector UP()
	{
		return Vector(0, -1);
	}
	static Vector Down()
	{
		return Vector(0, 1);
	}
	static Vector Right()
	{
		return Vector(1, 0);
	}
	static Vector Left()
	{
		return Vector(-1, 0);
	}
	Vector operator+(const Vector& other) const 
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return Vector(this->x + other.x, this->y + other.y); // 
	}
	Vector operator-(const Vector& other) const
	{
		Vector result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;

		return Vector(this->x - other.x, this->y - other.y); // 
	}
	Vector operator*(float value) const 
	{
		Vector result;
		result.x = this->x * value;
		result.y = this->y * value;

		return result;
	}
	Vector& operator=(const Vector& other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}
	Vector& operator+=(const Vector& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}
	Vector& operator-=(const Vector& other)
	{
		this->x -= other.x;
		this->y -= other.y;

		return *this;
	}
	Vector operator++(int)
	{
		Vector result(*this);
		this->x += 1.0f;
		this->y += 1.0f;

		return result;
	}
	bool operator==(const Vector& other) const
	{
		if (other.x == x)
		{
			if (other.y == y)
			{
				return true;
			}
		}

		return false;
	}
	float Length() const 
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}

	void Noramlize()
	{
		float l = Length();
		x /= l;
		y /= l;

	}
	Vector NormalVector() const
	{
		Vector result = *this;
		result.Noramlize();
		return result;
	}

	float Dot(const Vector& other) const
	{

		//������ 0�� ������ �����̶� ��
		return x*other.x+y*other.y;
	}

	float Cross(const Vector& other) const
	{
		//������ 0�̶�� �����̶� ��
		return x*other.y-y*other.x;
	}

	//v1 �� v2�� �ٸ� ������ �糡�� �ڽ��� �� �������� �������� �̷��� ������� �� ���� ������ �����Ͽ� ���� +,-�� ���� �������� -�� ������ �����ϴ°�.
	//�ݽð�������ΰ��� +�� ������ �ð�������� ���� -�����´�.
	float IsBetween(const Vector& v1, const Vector& v2)
	{

		float cross1 = this->Cross(v1);
		float cross2 = this->Cross(v2);

		return cross1 * cross2 < 0;

	}
	Vector Rotate(float theta)
	{
		float cosTheta = std::cosf(theta);
		float sinTheta = std::sinf(theta);

		return {
		x * cosTheta - y * sinTheta,
		x * sinTheta + y * cosTheta 
		};
	}
	Vector Rotate(const Vector& target)
	{
		float cosTheta = Dot(target);
		float sinTheta = Cross(target);

		return {
		x * cosTheta - y * sinTheta,
		x * sinTheta + y * cosTheta
		};
	}
	void PrintV()
	{
	}

	float x;
	float y;
};
