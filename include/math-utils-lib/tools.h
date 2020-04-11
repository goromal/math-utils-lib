#pragma once

#include <Eigen/Core>
#include <random>

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

template <typename T>
Eigen::Matrix<T,3,3> skew(const Eigen::Matrix<T,3,1>& v)
{
  Eigen::Matrix<T,3,3> mat;
  mat << (T)0.0, -v(2), v(1),
         v(2), (T)0.0, -v(0),
         -v(1), v(0), (T)0.0;
  return mat;
}

template <typename Derived>
void setNormalRandom(Eigen::MatrixBase<Derived>& M, std::normal_distribution<double>& N, std::default_random_engine& g)
{
  for (int i = 0; i < M.rows(); i++)
  {
    for (int j = 0; j < M.cols(); j++)
    {
      M(i,j) = N(g);
    }
  }
}

template <typename T, int R, int C>
Eigen::Matrix<T, R, C> randomNormal(std::normal_distribution<T>& N, std::default_random_engine& g)
{
  Eigen::Matrix<T,R,C> out;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      out(i,j) = N(g);
    }
  }
  return out;
}

template <typename T, int R, int C>
Eigen::Matrix<T, R, C> randomUniform(std::uniform_real_distribution<T>& N, std::default_random_engine& g)
{
  Eigen::Matrix<T,R,C> out;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      out(i,j) = N(g);
    }
  }
  return out;
}

template <typename T>
int sign(T in)
{
  return (in >= 0) - (in < 0);
}

template <typename T>
inline T random(T max, T min)
{
  T f = (T)rand() / RAND_MAX;
  return min + f * (max - min);
}

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
    // https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         std::iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         std::rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         std::rotate(k,itr2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}

} // end namespace utils_math
