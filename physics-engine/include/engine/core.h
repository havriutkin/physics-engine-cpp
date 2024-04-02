#pragma once

#include <math.h>

#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

namespace cyclone {

	typedef float real;

	class Vector3 {
	public:
		real x;
		real y;
		real z;

		// Default constructor defines zero vector
		Vector3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector3(const real x, const real y, const real z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		void invert() {
			this->x = -x;
			this->y = -y;
			this->z = -z;
		}

		real magnitude() {
			return sqrtf(x * x + y * y + z * z);
		}

		real squaredMagnitude() {
			return x * x + y * y + z * z;
		}

		void normalize() {
			const real length = this->magnitude();

			if (length > 0) {
				this->x = x / length;
				this->y = y / length;
				this->z = z / length;
			}
		}


		// Scalar multiplication
		void operator*=(const real value) {
			this->x *= value;
			this->y *= value;
			this->z *= value;
		}

		Vector3 operator*(const real value) {
			return Vector3(x * value, y * value, z * value);
		}


		// Vector addition
		void operator+=(const Vector3& vec) {
			this->x += vec.x;
			this->y += vec.y;
			this->z += vec.z;
		}

		Vector3 operator+(const Vector3& vec) {
			return Vector3(this->x + vec.x,
				this->y + vec.y,
				this->z + vec.z);
		}


		// Vector subtraction
		void operator-=(const Vector3& vec) {
			this->x -= vec.x;
			this->y -= vec.y;
			this->z -= vec.z;
		}

		Vector3 operator-(const Vector3& vec) {
			return Vector3(this->x - vec.x,
				this->y - vec.y,
				this->z - vec.z);
		}


		// Component product
		void componentProductUpdate(const Vector3& vec) {
			this->x *= vec.x;
			this->y *= vec.y;
			this->z *= vec.z;
		}

		Vector3 componentProduct(const Vector3& vec) {
			return Vector3(this->x * vec.x,
				this->y * vec.y,
				this->z * vec.z);
		}


		// Scalar product
		real scalarProduct(const Vector3& vec) {
			return this->x * vec.x + this->y * vec.y + this->z * vec.z;
		}

		real operator*(const Vector3& vec) {
			return this->x * vec.x + this->y * vec.y + this->z * vec.z;
		}


		// Vector product
		Vector3 vectorProduct(const Vector3& vec) {
			return Vector3(this->y * vec.z - this->z * vec.y,
				this->z * vec.x - this->x * vec.z,
				this->x * vec.y - this->y * vec.x);
		}

		void operator%=(const Vector3& vec) {
			real old_x = this->x;
			real old_y = this->y;
			real old_z = this->z;

			this->x = old_y * vec.z - old_z * vec.y;
			this->y = old_z * vec.x - old_x * vec.z;
			this->z = old_x * vec.y - old_y * vec.x;
		}

		Vector3 operator%(const Vector3& vec) {
			return Vector3(this->y * vec.z - this->z * vec.y,
				this->z * vec.x - this->x * vec.z,
				this->x * vec.y - this->y * vec.x);
		}
	};

}

#endif // !ENGINE_CORE_H