#ifndef COMMON_VECTOR4_H
#define COMMON_VECTOR4_H

#include "vector3.h"

template <typename T> class Vector4 {
	//cartesian (x, y, z) point
	Vector3<T> _xyz;
	//extruder location
	T _e;
	public:
		//initialize to all 0's
		Vector4() : _xyz(), _e(0) {}
		//initialize from components
		Vector4(T x, T y, T z, T e) : _xyz(x, y, z), _e(e) {}
		//initialize from a cartesian (x, y, z) point plus an extruder coordinate
		//
		//allow for initialization from a different precision (eg a Vector3<double>)
		template <typename T2> Vector4(const Vector3<T2> &xyz, T2 e) : _xyz(xyz.x(), xyz.y(), xyz.z()), _e(e) {}
		//initialize from another Vector4, possibly of a different precision
		template <typename T2> Vector4(const Vector4<T2> &v) : _xyz(v.x(), v.y(), v.z()), _e(v.e()) {}

		//cast to a tuple of <x, y, z, e>
		std::tuple<T, T, T, T> tuple() const {
			return std::make_tuple(x(), y(), z(), e());
		}
		operator std::tuple<T, T, T, T>() const {
			return tuple();
		}

		//string representation
		std::string str() const {
			return "Vector4(" + std::to_string(x()) + ", " + std::to_string(y()) + ", " + std::to_string(z()) + ", " + std::to_string(e()) + ")";
		}
		operator std::string() const {
			return str();
		}

		//return the x, y, z components as a <Vector3>
		const Vector3<T>& xyz() const {
			return _xyz;
		}
		//return the e (extruder) component
		const T e() const {
			return _e;
		}
		//return the x component
		const T x() const {
			return _xyz.x();
		}
		//return the y component
		const T y() const {
			return _xyz.y();
		}
		//return the z component
		const T z() const {
			return _xyz.z();
		}
		
};

//4-component (x, y, z) vector using (32-bit) floats
typedef Vector4<float> Vector4f;
//4-component (x, y, z) vector using higher precision (64-bit) doubles
typedef Vector4<double> Vector4d;

#endif