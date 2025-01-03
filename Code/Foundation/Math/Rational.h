
#pragma once

#include <Foundation/Basics.h>

/// \brief A class which can be used to represent rational numbers by stating their numerator and denominator.
///
/// nsRational uses the following rules
///   0/0 is legal and will be interpreted as 0/1
///   If you are representing a whole number, the denominator should be 1
///
class nsRational
{
public:
  NS_DECLARE_POD_TYPE();

  /// \brief Default constructor, initializes to 0/1.
  nsRational();

  /// \brief Constructor to initialize a rational
  nsRational(nsUInt32 uiNumerator, nsUInt32 uiDenominator);

  /// \brief returns true if the division of the numerator by the denominator would result in a full integer
  bool IsIntegral() const;

  /// \brief Equality operator
  bool operator==(const nsRational& other) const;

  /// \brief Inequality operator
  bool operator!=(const nsRational& other) const;

  /// \brief Returns the numerator of the rational number
  nsUInt32 GetNumerator() const;

  /// \brief Returns the denominator
  nsUInt32 GetDenominator() const;

  /// \brief Returns the result of the division as an integer.
  nsUInt32 GetIntegralResult() const;

  /// \brief Returns the result of the division as a floating point number (double).
  double GetFloatingPointResult() const;

  /// \brief Returns true if the rational is valid (follows the rules stated in the class description)
  bool IsValid() const;

  /// \brief This helper returns a reduced fraction in case of an integral input.
  ///
  /// Note that this will assert in DEV builds if this class is not integral.
  nsRational ReduceIntegralFraction() const;

protected:
  nsUInt32 m_uiNumerator = 0;
  nsUInt32 m_uiDenominator = 1;
};

#include <Foundation/Math/Implementation/Rational_inl.h>
