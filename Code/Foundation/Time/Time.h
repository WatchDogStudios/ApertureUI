#pragma once

#include <Foundation/Basics.h>
#include <Foundation/Configuration/StaticSubSystem.h>

/// \brief The time class encapsulates a double value storing the time in seconds.
///
/// It offers convenient functions to get the time in other units.
/// nsTime is a high-precision time using the OS specific high-precision timing functions
/// and may thus be used for profiling as well as simulation code.
struct NS_FOUNDATION_DLL nsTime
{
public:
  /// \brief Gets the current time
  static nsTime Now(); // [tested]

  /// \brief Creates an instance of nsTime that was initialized from nanoseconds.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromNanoseconds(double fNanoseconds) { return nsTime(fNanoseconds * 0.000000001); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Nanoseconds(double fNanoseconds) { return nsTime(fNanoseconds * 0.000000001); }

  /// \brief Creates an instance of nsTime that was initialized from microseconds.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromMicroseconds(double fMicroseconds) { return nsTime(fMicroseconds * 0.000001); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Microseconds(double fMicroseconds) { return nsTime(fMicroseconds * 0.000001); }

  /// \brief Creates an instance of nsTime that was initialized from milliseconds.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromMilliseconds(double fMilliseconds) { return nsTime(fMilliseconds * 0.001); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Milliseconds(double fMilliseconds) { return nsTime(fMilliseconds * 0.001); }

  /// \brief Creates an instance of nsTime that was initialized from seconds.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromSeconds(double fSeconds) { return nsTime(fSeconds); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Seconds(double fSeconds) { return nsTime(fSeconds); }

  /// \brief Creates an instance of nsTime that was initialized from minutes.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromMinutes(double fMinutes) { return nsTime(fMinutes * 60); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Minutes(double fMinutes) { return nsTime(fMinutes * 60); }

  /// \brief Creates an instance of nsTime that was initialized from hours.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeFromHours(double fHours) { return nsTime(fHours * 60 * 60); }
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime Hours(double fHours) { return nsTime(fHours * 60 * 60); }

  /// \brief Creates an instance of nsTime that was initialized with zero.
  [[nodiscard]] NS_ALWAYS_INLINE constexpr static nsTime MakeZero() { return nsTime(0.0); }

  NS_DECLARE_POD_TYPE();

  /// \brief The default constructor sets the time to zero.
  NS_ALWAYS_INLINE constexpr nsTime() = default;

  /// \brief Returns true if the stored time is exactly zero. That typically means the value was not changed from the default.
  NS_ALWAYS_INLINE constexpr bool IsZero() const { return m_fTime == 0.0; }

  /// \brief Checks for a negative time value.
  NS_ALWAYS_INLINE constexpr bool IsNegative() const { return m_fTime < 0.0; }

  /// \brief Checks for a positive time value. This does not include zero.
  NS_ALWAYS_INLINE constexpr bool IsPositive() const { return m_fTime > 0.0; }

  /// \brief Returns true if the stored time is zero or negative.
  NS_ALWAYS_INLINE constexpr bool IsZeroOrNegative() const { return m_fTime <= 0.0; }

  /// \brief Returns true if the stored time is zero or positive.
  NS_ALWAYS_INLINE constexpr bool IsZeroOrPositive() const { return m_fTime >= 0.0; }

  /// \brief Returns the time as a float value (in seconds).
  ///
  /// Useful for simulation time steps etc.
  /// Please note that it is not recommended to use the float value for long running
  /// time calculations since the precision can deteriorate quickly. (Only use for delta times is recommended)
  constexpr float AsFloatInSeconds() const;

  /// \brief Returns the nanoseconds value
  constexpr double GetNanoseconds() const;

  /// \brief Returns the microseconds value
  constexpr double GetMicroseconds() const;

  /// \brief Returns the milliseconds value
  constexpr double GetMilliseconds() const;

  /// \brief Returns the seconds value.
  constexpr double GetSeconds() const;

  /// \brief Returns the minutes value.
  constexpr double GetMinutes() const;

  /// \brief Returns the hours value.
  constexpr double GetHours() const;

  /// \brief Subtracts the time value of "other" from this instances value.
  constexpr void operator-=(const nsTime& other);

  /// \brief Adds the time value of "other" to this instances value.
  constexpr void operator+=(const nsTime& other);

  /// \brief Multiplies the time by the given factor
  constexpr void operator*=(double fFactor);

  /// \brief Divides the time by the given factor
  constexpr void operator/=(double fFactor);

  /// \brief Returns the difference: "this instance - other"
  constexpr nsTime operator-(const nsTime& other) const;

  /// \brief Returns the sum: "this instance + other"
  constexpr nsTime operator+(const nsTime& other) const;

  constexpr nsTime operator-() const;

  constexpr bool operator<(const nsTime& rhs) const { return m_fTime < rhs.m_fTime; }
  constexpr bool operator<=(const nsTime& rhs) const { return m_fTime <= rhs.m_fTime; }
  constexpr bool operator>(const nsTime& rhs) const { return m_fTime > rhs.m_fTime; }
  constexpr bool operator>=(const nsTime& rhs) const { return m_fTime >= rhs.m_fTime; }
  constexpr bool operator==(const nsTime& rhs) const { return m_fTime == rhs.m_fTime; }
  constexpr bool operator!=(const nsTime& rhs) const { return m_fTime != rhs.m_fTime; }

private:
  /// \brief For internal use only.
  constexpr explicit nsTime(double fTime);

  /// \brief The time is stored in seconds
  double m_fTime = 0.0;

private:
  NS_MAKE_SUBSYSTEM_STARTUP_FRIEND(Foundation, Time);

  static void Initialize();
};

constexpr nsTime operator*(nsTime t, double f);
constexpr nsTime operator*(double f, nsTime t);
constexpr nsTime operator*(nsTime f, nsTime t); // not physically correct, but useful (should result in seconds squared)

constexpr nsTime operator/(nsTime t, double f);
constexpr nsTime operator/(double f, nsTime t);
constexpr nsTime operator/(nsTime f, nsTime t); // not physically correct, but useful (should result in a value without a unit)


#include <Foundation/Time/Implementation/Time_inl.h>
