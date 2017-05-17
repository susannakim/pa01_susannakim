// stats.cxx - implements statistician class as defined in stats.h
// Susanna Kim, 4/12/17

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{
  statistician::statistician() {
    count = 0;
    total = 0;
  }
  
  void statistician::next(double r) {
    if (count == 0) {
      total = r;
      tiniest = r;
      largest = r;
    }
    else {
      total += r;
      if (r < tiniest)
	tiniest = r;
      if (r > largest)
	largest = r;
    }
    count++;
  }

  void statistician::reset() {
    count = 0;
    total = 0;
  }

  double statistician::mean() const {
    assert(length() > 0);
    return (total/count);
  }

  double statistician::minimum() const {
    assert(length() > 0);
    return tiniest;
  }

  double statistician::maximum() const {
    assert(length() > 0);
    return largest;
  }

  statistician operator +(const statistician& s1, const statistician& s2) {
    statistician s3;
    if (s1.length() == 0)
      return s2;
    if (s2.length() == 0)
      return  s1;
    s3.count = s1.length() + s2.length();
    s3.total = s1.sum() + s2.sum();
    if (s1.minimum() < s2.minimum())
      s3.tiniest = s1.minimum();
    else
      s3.tiniest = s2.minimum();
    if (s1.maximum() > s2.maximum())
      s3.largest = s1.maximum();
    else
      s3.largest = s2.maximum();
    return s3;
  }

  statistician operator *(double scale, const statistician& s) {
    statistician s3;
    if (s.length() == 0)
      return s;
    s3.count = s.length();
    s3.total = scale * s.sum();
    if (scale < 0) {
      s3.tiniest = scale * s.maximum();
      s3.largest = scale * s.minimum();
    }
    else {
      s3.tiniest = scale * s.minimum();
      s3.largest = scale * s.maximum();
    }
    return s3;
  }

  bool operator ==(const statistician& s1, const statistician& s2) {
    if (s1.length() != s2.length())
      return false;
    if (s1.length() == 0)
      return true;
    return ((s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()) && (s1.sum() == s2.sum()));
  }
// STUDENT WORK HERE
    
}
