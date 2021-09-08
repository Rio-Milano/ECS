#ifndef VECTOR2
#define VECTOR2

template<class X, class Y>

struct Vector2
{
	Vector2() = default;

	~Vector2() = default;

	X x;
	Y y;
};

using Vector2f = Vector2<float, float>;

#endif
