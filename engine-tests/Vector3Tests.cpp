#include "pch.h"
#include "../physics-engine/include/engine/core.h"

/* Constructor tests */

TEST(Vector3Tests, DefaultConstructor) {
	cyclone::Vector3 v;

	EXPECT_EQ(0, v.x);
	EXPECT_EQ(0, v.y);
	EXPECT_EQ(0, v.z);
}

TEST(Vector3Tests, Constructor) {
	cyclone::Vector3 v(1, 2, 3);

	EXPECT_EQ(1, v.x);
	EXPECT_EQ(2, v.y);
	EXPECT_EQ(3, v.z);
}


/* Invert, Magnitude, Normalize tests*/

TEST(Vector3Tests, Invert) {
	cyclone::Vector3 v(1, 2, 3);
	v.invert();

	EXPECT_EQ(-1, v.x);
	EXPECT_EQ(-2, v.y);
	EXPECT_EQ(-3, v.z);
}

TEST(Vector3Tests, Magnitude) {
	cyclone::Vector3 v(1, 2, 3);

	EXPECT_EQ(sqrtf(14), v.magnitude());
}

TEST(Vector3Tests, SquaredMagnitude) {
	cyclone::Vector3 v(1, 2, 3);

	EXPECT_EQ(14, v.squaredMagnitude());
}

TEST(Vector3Tests, Normalize) {
	cyclone::Vector3 v(1, 2, 3);
	v.normalize();

	EXPECT_EQ(1 / sqrtf(14), v.x);
	EXPECT_EQ(2 / sqrtf(14), v.y);
	EXPECT_EQ(3 / sqrtf(14), v.z);
}


/* Scalar multiplication tests */

TEST(Vector3Tests, ScalarMultipliationUpdateOperator) {
	cyclone::Vector3 v(1, 2, 3);
	float scalar = -2;

	v *= scalar;

	EXPECT_EQ(-2, v.x);
	EXPECT_EQ(-4, v.y);
	EXPECT_EQ(-6, v.z);
}

TEST(Vector3Tests, ScalarMultiplicationOperator) {
	cyclone::Vector3 v(1, 2, 3);
	float scalar = 2;

	cyclone::Vector3 result = v * scalar;

	EXPECT_EQ(2, result.x);
	EXPECT_EQ(4, result.y);
	EXPECT_EQ(6, result.z);
}


/* Vector addition tests */

TEST(Vector3Tests, VectorAddition) {
	cyclone::Vector3 lhs(-1, 0, 5);
	cyclone::Vector3 rhs(3, -2, 4);

	cyclone::Vector3 result = lhs + rhs;

	EXPECT_EQ(2, result.x);
	EXPECT_EQ(-2, result.y);
	EXPECT_EQ(9, result.z);
}

TEST(Vector3Tests, UpdateVectorAddition) {
	cyclone::Vector3 lhs(-1, 0, 5);
	cyclone::Vector3 rhs(3, -2, 4);

	lhs += rhs;

	EXPECT_EQ(2, lhs.x);
	EXPECT_EQ(-2, lhs.y);
	EXPECT_EQ(9, lhs.z);
}



/* Vector subtraction tests */

TEST(Vector3Tests, VectorSubtraction) {
	cyclone::Vector3 lhs(-1, 0, 5);
	cyclone::Vector3 rhs(3, -2, 4);

	cyclone::Vector3 result = lhs - rhs;

	EXPECT_EQ(-4, result.x);
	EXPECT_EQ(2, result.y);
	EXPECT_EQ(1, result.z);
}

TEST(Vector3Tests, UpdateVectorSubtraction) {
	cyclone::Vector3 lhs(-1, 0, 5);
	cyclone::Vector3 rhs(3, -2, 4);

	lhs -= rhs;

	EXPECT_EQ(-4, lhs.x);
	EXPECT_EQ(2, lhs.y);
	EXPECT_EQ(1, lhs.z);
}


/* Component product tests */

TEST(Vector3Tests, ComponentProduct) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	cyclone::Vector3 result = lhs.componentProduct(rhs);

	EXPECT_EQ(0, result.x);
	EXPECT_EQ(-6, result.y);
	EXPECT_EQ(-2, result.z);
}

TEST(Vector3Tests, ComponentProductUpdate) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	lhs.componentProductUpdate(rhs);

	EXPECT_EQ(0, lhs.x);
	EXPECT_EQ(-6, lhs.y);
	EXPECT_EQ(-2, lhs.z);
}


/* Scalar product tests */

TEST(Vector3Tests, ScalarProductMethod) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	float result = lhs.scalarProduct(rhs);

	EXPECT_EQ(-8, result);
}

TEST(Vector3Tests, ScalarProductOperator) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	float result = lhs * rhs;

	EXPECT_EQ(-8, result);
}


/* Vector product tests */

TEST(Vector3Tests, VectorProductMethod) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	cyclone::Vector3 result = lhs.vectorProduct(rhs);

	EXPECT_EQ(-6.5, result.x);
	EXPECT_EQ(9, result.y);
	EXPECT_EQ(36, result.z);
}

TEST(Vector3Tests, VectorProductUpdateOperator) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	lhs %= rhs;

	EXPECT_EQ(-6.5, lhs.x);
	EXPECT_EQ(9, lhs.y);
	EXPECT_EQ(36, lhs.z);
}

TEST(Vector3Tests, VectorProductOperator) {
	cyclone::Vector3 lhs(-9, 1.5, -2);
	cyclone::Vector3 rhs(0, -4, 1);

	cyclone::Vector3 result = lhs % rhs;

	EXPECT_EQ(-6.5, result.x);
	EXPECT_EQ(9, result.y);
	EXPECT_EQ(36, result.z);
}

