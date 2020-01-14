#pragma once

#include <Eigen/Core>

#define UTILS_PI 3.14192653589793238

using namespace Eigen;

namespace utils_math
{

// LEGACY skew
inline Eigen::Matrix3d skew(const Eigen::Vector3d v)
{
  Eigen::Matrix3d mat;
  mat << 0.0, -v(2), v(1),
         v(2), 0.0, -v(0),
         -v(1), v(0), 0.0;
  return mat;
}


static const Eigen::Matrix<double, 2, 3> I_2x3 = [] {
  Eigen::Matrix<double, 2, 3> tmp;
  tmp << 1.0, 0, 0,
         0, 1.0, 0;
  return tmp;
}();

static const Eigen::Matrix3d I_3x3 = [] {
  Eigen::Matrix3d tmp = Eigen::Matrix3d::Identity();
  return tmp;
}();

static const Eigen::Matrix2d I_2x2 = [] {
  Eigen::Matrix2d tmp = Eigen::Matrix2d::Identity();
  return tmp;
}();


static const Eigen::Vector3d e_x = [] {
  Eigen::Vector3d tmp;
  tmp << 1.0, 0, 0;
  return tmp;
}();

static const Eigen::Vector3d e_y = [] {
  Eigen::Vector3d tmp;
  tmp << 0, 1.0, 0;
  return tmp;
}();

static const Eigen::Vector3d e_z = [] {
  Eigen::Vector3d tmp;
  tmp << 0, 0, 1.0;
  return tmp;
}();

template <typename T>
Eigen::Matrix<T,3,3> skew(const Eigen::Matrix<T,3,1>& v)
{
  Eigen::Matrix<T,3,3> mat;
  mat << (T)0.0, -v(2), v(1),
         v(2), (T)0.0, -v(0),
         -v(1), v(0), (T)0.0;
  return mat;
}

} // namespace utils_math
